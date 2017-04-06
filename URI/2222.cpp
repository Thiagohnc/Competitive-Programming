/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/2222/ */

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
#define MAXN 10500
#define bitqt(X) __builtin_popcount(X)
#define bitqtll(X) __builtin_popcountll(X)

using namespace std;

int main(void) {
	int t, n, q;
	ll bt[MAXN];
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			int m, x;
			bt[i] = 0;
			scanf("%d", &m);
			for(int j = 0; j < m; j++) {
				scanf("%d", &x);
				bt[i] |= 1LL << x;
			}
		}
		
		scanf("%d", &q);
		int a, b, c;
		for(int i = 0; i < q; i++) {
			scanf("%d %d %d", &a, &b, &c);
			if(a == 1) printf("%d\n", __builtin_popcountll(bt[b]&bt[c]));
			else printf("%d\n", __builtin_popcountll(bt[b]|bt[c]));
		}
	}
		
	return 0;
}