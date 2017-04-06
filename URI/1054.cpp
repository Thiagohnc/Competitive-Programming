/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1054/ */

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
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f

using namespace std;

int main(void){
	int alt, max_jump;
	int t, n, d, num, cont;
	char c;
	vii v;
	
	scanf("%d", &t);
	for(int test = 1; test <= t; test++) {
		cont = alt = max_jump = 0;
		scanf("%d %d", &n, &d);
		v.pb(mp(0, 2));
		for(int i = 0; i < n; i++) {
			c = getchar();
			while(c!='B' && c!='S') c = getchar();
			getchar();
			scanf("%d", &num);
			if(c == 'B') v.pb(mp(num, 2));
			if(c == 'S') {
				v.pb(mp(num, alt));
				alt = (alt + 1)%2;
			}
		}
		v.pb(mp(d, 2));
		
		for(int i = 1; i < v.size(); i++) {
			cont += v[i].f - v[i-1].f;
			if(v[i].s != 1) {
				max_jump = max(max_jump, cont);
				cont = 0;
			}
		}
		
		for(int i = v.size() - 2; i >= 0; i--) {
			cont += v[i+1].f - v[i].f;
			if(v[i].s != 0) {
				max_jump = max(max_jump, cont);
				cont = 0;
			}
		}
		
		printf("Case %d: %d\n", test, max_jump);
		v.clear();
	}
	
	return 0;
}