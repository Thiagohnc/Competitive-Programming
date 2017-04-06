/* https://www.urionlinejudge.com.br/judge/en/problems/view/1127/ */

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
#define MAXN 200050

using namespace std;

void z_alg(int z[], int v[], int n) {
	int l = 0, r = 0;
	z[0] = 0;
	for(int i = 1; i < n; i++) {
		if(i > r) {
			l = r = i;
			while(r < n && v[r] == v[r-l]) r++;
			z[i] = r - l;
			r--;
		}
		else {
			z[i] = min(z[i-l], r - i + 1);
			if(i + z[i] == r + 1) {
				l = i;
				while(r < n && v[r] == v[r-l]) r++;
				z[i] = r - l;
				r--;
			}
		}
	}
}

int val(char a[]) {
	int vl;
	if(a[0] == 'A') vl = 1;
	if(a[0] == 'B') vl = 3;
	if(a[0] == 'C') vl = 4;
	if(a[0] == 'D') vl = 6;
	if(a[0] == 'E') vl = 8;
	if(a[0] == 'F') vl = 9;
	if(a[0] == 'G') vl = 11;
	if(a[1] == '#') vl++;
	if(a[1] == 'b') vl--;
	return vl % 12;
}

void rot(int v[], int n) {
	for(int i = 0; i < n; i++) v[i] = (v[i] + 1) % 12;
}

int main(void) {
	int n, m, v[MAXN], z[MAXN];
	char st[20];
	
	while(1) {
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		for(int i = m + 1; i < n + m + 1; i++) {
			scanf("%s", st);
			v[i] = val(st);
		}
		for(int i = 0; i < m; i++) {
			scanf("%s", st);
			v[i] = val(st);
		}
		v[m] = -1;
		bool yes = false;
		for(int i = 0; i < 12; i++) {
			z_alg(z, v, n + m + 1);
			for(int i = 0; i < n + m + 1; i++) if(z[i] == m) yes = true;
			rot(v, m);
		}
		if(yes) puts("S");
		else puts("N");
	}
	
	return 0;
}