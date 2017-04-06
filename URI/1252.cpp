/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1252/ */

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
	int n, m;
	vector<pair<int, pair<int, int> > > v;
	
	while(1) {
		scanf("%d %d", &n, &m);
		if(!n && !m) break;
	
		int num;
		for(int i = 0; i < n; i++) {
			scanf("%d", &num);
			num % 2 == 0 ? v.pb(mp(num % m, mp(1, num))) : v.pb(mp(num % m, mp(0, -num)));
		}
		sort(v.begin(), v.end());
		
		printf("%d %d\n", n, m);
		for(int i = 0; i < v.size(); i++) printf("%d\n", - v[i].s.s + 2 * v[i].s.s * v[i].s.f);
		
		v.clear();
	}
	puts("0 0");
	
	return 0;
}