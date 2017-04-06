/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/2241/ */

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
#define MAXN 520

using namespace std;

int mt[MAXN][MAXN];
ll ans[5];

int main(void) {
	int n, m;
	
	for(int i = 0; i < MAXN; i++) memset(mt[i],0,sizeof(ll)*MAXN);
	
	scanf("%d %d", &n, &m);
	int a, b;
	ans[0] = ans[1] = ans[2] = m;
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		mt[a][b] = 1;
	}
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		mt[a][b] = 2;
	}
	
	for(int k = 1; k <= n - 1; k++) {
		for(int i = 1; i <= n - k; i++) {
			for(int j = 1; j <= n - k; j++) {
				mt[i][j] |= (mt[i+1][j] | mt[i][j+1] | mt[i+1][j+1]);
				ans[mt[i][j]]++;
			}
		}
	}
	
	printf("%lld %lld\n", ans[1], ans[2]);
	
	return 0;
}