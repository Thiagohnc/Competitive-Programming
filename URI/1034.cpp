/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1034/ */

#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ull unsigned long long int
#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define ii pair<int,int>
#define lb lower_bound
#define ub upper_bound
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MAXN 1000500

using namespace std;

int pd[MAXN];
int v[MAXN];

int main(void) {
	int t, n, m;
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++) scanf("%d", &v[i]);
		memset(pd,INF,sizeof(int)*(m+1));
		pd[0] = 0;
		for(int i = 0; i < n; i++) for(int j = v[i]; j <= m; j++) pd[j] = min(pd[j], pd[j-v[i]] + 1);
		printf("%d\n", pd[m]);
	}
	
	return 0;
}