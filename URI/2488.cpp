/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/2488/ */

#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
#include <time.h>
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
#define MAXN 105000

using namespace std;

double v[MAXN], st[3*MAXN];

double build(double st[], double v[], int idx, int l, int r) {
	if (l == r) return st[idx] = v[l];

	int m = (l + r) / 2;
	int lc = 2*idx + 1;
	int rc = 2*idx + 2;

	return st[idx] = max(build(st, v, lc, l, m), build(st, v, rc, m + 1, r));
}

double query(double st[], int idx, int l, int r, int a, int b) {
   if (a == l and b == r) return st[idx];

   int m = (l + r) / 2;
   int lc = 2*idx + 1;
   int rc = 2*idx + 2;

   if (b <= m) return query(st, lc, l, m, a, b);
   else if (a > m) return query(st, rc, m+1, r, a, b);
   else return max(query(st, lc, l, m, a, m), query(st, rc, m+1, r, m+1, b));
}

double dist(int x0, int y0, int x1, int y1) {
	return sqrt(pow(y1 - y0, 2) + pow(x1 - x0, 2));
}

int main(void) {
	int n, p, a, b, c, d;
	set<pair<pair<int,int>,int> > ms;
	std::set<pair<pair<int,int>,int> >::iterator it;
	pair<pair<int,int>,int> p1, p2;
	
	cin >> n >> p;
	
	int antx, anty;
	scanf("%d %d", &antx, &anty);
	ms.insert(mp(mp(antx,anty),0));
	v[0] = 0.0;
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		ms.insert(mp(mp(a,b),i));
		v[i] = dist(a, b, antx, anty);
		antx = a;
		anty = b;
	}
	
	build(st, v, 0, 0, n - 1);
	
	for(int i = 0; i < p; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		it = ms.lb(mp(mp(a,b),0));
		p1 = *it;
		it = ms.lb(mp(mp(c,d),0));
		p2 = *it;
		if(min(p1.s, p2.s) == max(p1.s, p2.s)) puts("0.00");
		else printf("%.2lf\n", query(st, 0, 0, n - 1, min(p1.s, p2.s) + 1, max(p1.s, p2.s)));
	}
	
	return 0;
}