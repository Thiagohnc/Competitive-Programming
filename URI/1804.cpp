/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1804/ */

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
#define MAXN 200500

using namespace std;

int v[MAXN], st[2*MAXN];

int build(int v[], int st[], int idx, int l, int r) {
	int mid = (l + r)/2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;
	
	if(l == r) return st[idx] = v[l];
	return st[idx] = build(v, st, lc, l, mid) + build(v, st, rc, mid + 1, r);
}

int update(int v[], int st[], int i, int idx, int val, int l, int r) {
	int mid = (l + r)/2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;
	
	if(l == r) return st[idx] = v[i] = val;
	
	if(i <= mid) return st[idx] = update(v, st, i, lc, val, l, mid) + st[rc];
	return st[idx] = st[lc] + update(v, st, i, rc, val, mid + 1, r);
}

int query(int v[], int st[], int idx, int l, int r, int a, int b) {
	int mid = (l + r)/2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;
	
	if(a <= l && b >= r) return st[idx];
	
	if(b <= mid) return query(v, st, lc, l, mid, a, b);
	if(a > mid) return query(v, st, rc, mid + 1, r, a, b);
	return query(v, st, lc, l, mid, a, b) + query(v, st, rc, mid + 1, r, a, b);
}

int main(void) {
	int n;
	char c;
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	v[0] = 0;
	
	build(v, st, 0, 0, n);
	
	int x;
	while(1) {
		getchar();
		if(scanf("%c %d", &c, &x) == EOF) break;
		if(c == 'a') update(v, st, x, 0, 0, 0, n);
		if(c == '?') printf("%d\n", query(v, st, 0, 0, n, 0, x - 1));
	}

	return 0;
}