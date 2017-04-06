/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1301/ */

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
#define MAXN 100500

using namespace std;

int v[MAXN], st[3*MAXN];

int build(int st[], int v[], int idx, int l, int r) {
	int mid = (l + r)/2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;
	
	if(l == r) return st[idx] = v[l];
	
	return st[idx] = build(st, v, lc, l, mid) * build(st, v, rc, mid + 1, r);
}

int update(int st[], int v[], int i, int val, int idx, int l, int r) {
	int mid = (l + r)/2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;
	
	if(l == r) return st[idx] = v[i] = val;
	
	if(i <= mid) return st[idx] = update(st, v, i, val, lc, l, mid) * st[rc];
	return st[idx] = st[lc] * update(st, v, i, val, rc, mid + 1, r);
}

int query(int st[], int v[], int idx, int l, int r, int a, int b) {
	int mid = (l + r)/2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;
	
	if(a <= l && b >= r) return st[idx];
	
	if(b <= mid) return query(st, v, lc, l, mid, a, b);
	if(a > mid) return query(st, v, rc, mid + 1, r, a, b);
	return query(st, v, lc, l, mid, a, b) * query(st, v, rc, mid + 1, r, a, b);
}

int trt(int a) {
	if(a < 0) return -1;
	if(a > 0) return 1;
	return 0;
}

void trtq(int a) {
	if(a == 1) printf("+");
	else if(a == -1) printf("-");
	else printf("0");
}

void imp(int n) {
	for(int i = 0; i < n; i++) cout << st[i] << " ";
	cout << endl;
}

int main(void) {
	int n, k;
	
	while(scanf("%d %d", &n, &k) != EOF) {
		int x;
		for(int i = 0; i < n; i++) {
			scanf("%d", &x);
			v[i] = trt(x);
		}
		build(st, v, 0, 0, n - 1);
		char c;
		int a, b;
		while(k--) {
			getchar();
			c = getchar();
			scanf("%d %d", &a, &b);
			if(c == 'C') update(st, v, a - 1, trt(b), 0, 0, n - 1);
			else trtq(query(st, v, 0, 0, n - 1, a - 1, b - 1));
		}
		puts("");
	}
	
	return 0;
}