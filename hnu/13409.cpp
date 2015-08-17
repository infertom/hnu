#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;

const int MAXN = 100000 + 100;
const double EX = 1e-8;

int n;
double k;

typedef struct {
	double a, b, c, d;
	double m;
}NODE;
NODE node[MAXN];

bool mCmp(NODE aa, NODE bb)
{
	return aa.m > bb.m;
}


int main()
{
	//freopen("in.txt", "r", stdin);

	while ( scanf("%d", &n) != EOF && !(n == 0) )
	{
		scanf("%lf", &k);
		for (int i = 0; i < n; i++){
			scanf("%lf%lf%lf%lf", &node[i].a, &node[i].b, &node[i].c, &node[i].d);

		}

		double ans = 0;
		for (int i = 0; i < n; i++){
			if ( node[i].d > EX ) ans += node[i].d / node[i].c * node[i].b;
		}

		double tempX = k, tempC = 0;
		for (int i = 0; i < n; i++){
			if ( node[i].a > -EX && node[i].d < EX){
				node[i].m = -1;
			}
			else if ( node[i].a < EX && node[i].d > EX ){
				tempX -= node[i].a / node[i].c * node[i].b;
				tempC += node[i].d / node[i].c * node[i].b;
				node[i].m = -1;
			}
			else if ( node[i].a < EX && node[i].d < EX ){
				tempX -= node[i].a / node[i].c * node[i].b;
				tempC += node[i].d / node[i].c * node[i].b;
				node[i].m = node[i].d / node[i].a;
			}
			else {
				node[i].m = node[i].d / node[i].a;
			}
		}

		sort(node, node + n, mCmp);
		node[n].m = -2;
		//printf("ans=%lf\n",ans);
		//printf("x=%lf  c=%lf\n", tempX, tempC);
		//for (int i = 0; i < n; i++) cout<<node[i].m<<endl;
		for (int i = 0; i < n && !(fabs(node[i].m) < EX); i++){
			if ( node[i].a < EX ){
				tempX += node[i].a / node[i].c * node[i].b;
				tempC -= node[i].d / node[i].c * node[i].b;
			}
			else {
				tempX -= node[i].a / node[i].c * node[i].b;
				tempC += node[i].d / node[i].c * node[i].b;
			}
			if ( fabs(node[i].m - node[i+1].m) < EX ) continue;
			ans = min(ans, tempX * node[i].m + tempC);
			//printf("i=%d  ans=%lf\n", i, ans);
			//printf("x=%lf  c=%lf\n", tempX, tempC);
		}

		printf("%,6lf\n", ans);
	}


	return 0;
}