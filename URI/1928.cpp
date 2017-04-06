/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1928/ */

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
#define MAXN 100050
#define LOGMAX 25

using namespace std;

int vd[MAXN][LOGMAX], dad[MAXN], mrc[MAXN];
vi v[MAXN];

void dfs(int a, int pai, int lvl) {
	mrc[a] = lvl;
	dad[a] = pai;
	for(int i = 0; i < v[a].size(); i++) if(mrc[v[a][i]] == 0) dfs(v[a][i], a, lvl + 1);
}

void build(int n) {
	for(int i = 0; i < n; i++) vd[i][0] = dad[i];
	for(int j = 1; j < LOGMAX; j++) {
		for(int i = 0; i < n; i++) {
			vd[i][j] = vd[vd[i][j-1]][j-1];
		}
	}
}

int dist(int a, int b) {
	int d = 0;
	if(mrc[a] > mrc[b]) swap(a, b);
	for(int i = LOGMAX - 1; i >= 0; i--) {
		if(mrc[vd[b][i]] > mrc[a]) {
			b = vd[b][i];
			d += 1 << i;
		}
	}
	if(mrc[b] != mrc[a]) {
		d++;
		b = vd[b][0];
	}

	for(int i = LOGMAX - 1; i >= 0; i--) {
		if(vd[b][i] != vd[a][i]) {
			a = vd[a][i];
			b = vd[b][i];
			d += 2*(1 << i);
		}
	}
	if(b != a) d += 2;
	return d;
}

vi p[MAXN];

int main(void) {
	int n;
	
	scanf("%d", &n);
	int a;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		p[a].pb(i);
	}
	
	int b;
	for(int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		v[a-1].pb(b-1);
		v[b-1].pb(a-1);
	}
	
	memset(mrc,0,sizeof(int)*n);
	
	dfs(0, 0, 1);
	build(n);
	
	int ans = 0;

	for(int i = 1; i <= n/2; i++) ans += dist(p[i][0], p[i][1]);
	
	printf("%d\n", ans);
	
	return 0;
}