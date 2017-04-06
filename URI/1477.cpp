/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1477/ */

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
#define MAXN 500500

using namespace std;

struct Strat {
	int a, b, c;
	Strat() {}
	Strat(int a, int b, int c) : a(a), b(b), c(c) {}
	Strat operator+ (const Strat &o) const { return Strat(a + o.a, b + o.b, c + o.c); }
	void chg(int k) {
		int v[3];
		v[0] = a;
		v[1] = c;
		v[2] = b;
		a = v[k%3];
		b = v[(k+2)%3];
		c = v[(k+1)%3];
	}
	void imp() {
		printf("%d %d %d\n", a, b, c);
	}
};

Strat st[3*MAXN];
int lt[3*MAXN];

void propagate(Strat st[], int lt[], int idx, int l, int r) {
	st[idx].chg(lt[idx]);
	if(l != r) {
		lt[2*idx + 1] += lt[idx];
		lt[2*idx + 2] += lt[idx];
	}
	lt[idx] = 0;
}

Strat build(Strat st[], int lt[], int idx, int l, int r) {
	int mid = (l + r)/2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;
	
	lt[idx] = 0;
	if(l == r) return st[idx] = Strat(1, 0, 0);
	
	return st[idx] = build(st, lt, lc, l, mid) + build(st, lt, rc, mid + 1, r);
}

Strat query(Strat st[], int lt[], int idx, int l, int r, int a, int b) {
	int mid = (l + r)/2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;
	
	propagate(st, lt, idx, l, r);
	propagate(st, lt, lc, l, mid);
	propagate(st, lt, rc, mid + 1, r);
	
	if(a <= l && b >= r) return st[idx];
	
	if(b <= mid) return query(st, lt, lc, l, mid, a, b);
	if(a > mid) return query(st, lt, rc, mid + 1, r, a, b);
	return query(st, lt, lc, l, mid, a, b) + query(st, lt, rc, mid + 1, r, a, b);
}

void rupdate(Strat st[], int lt[], int idx, int l, int r, int a, int b) {
	int mid = (l + r)/2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;
	
	if(a <= l && b >= r) {
		lt[idx]++;
		propagate(st, lt, idx, l, r);
		return;
	}
	
	propagate(st, lt, idx, l, r);
	propagate(st, lt, lc, l, mid);
	propagate(st, lt, rc, mid + 1, r);
	
	if(b <= mid) rupdate(st, lt, lc, l, mid, a, b);
	else if(a > mid) rupdate(st, lt, rc, mid + 1, r, a, b);
	else if(a > l || b < r) {
		rupdate(st, lt, lc, l, mid, a, b);
		rupdate(st, lt, rc, mid + 1, r, a, b);
	}
	
	st[idx] = st[lc] + st[rc];
}

int main(void) {
	int n, k;
	
	while(scanf("%d %d", &n, &k) != EOF) {
		char c;
		int a, b;
		build(st, lt, 0, 0, n - 1);
		while(k--) {
			getchar();
			c = getchar();
			scanf("%d %d", &a, &b);
			if(c == 'C') query(st, lt, 0, 0, n - 1, a - 1, b - 1).imp();
			else rupdate(st, lt, 0, 0, n - 1, a - 1, b - 1);
		}
		puts("");
	}
	
	return 0;
}