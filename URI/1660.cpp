/* Problem https://www.urionlinejudge.com.br/judge/en/problems/view/1660/ */

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
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
using namespace std;

int main(void) {
	ll n, a, b;
	set<ll> s;
	vector<ll> v;
	
	while(scanf("%lld %lld %lld", &n, &a, &b) == 3) {
		ll idx = 0;
		ll aux;
		int ant = 1;
		while(1) {
			ant = s.size();
			s.insert(idx);
			v.pb(idx);
			if(ant == s.size()) break;
			aux = idx;
			idx = (a * aux) % n;
			idx = (idx * aux) % n;
			idx = (idx + b) % n;
		}
		ll src;
		for(src = 0;;src++) if(v[src] == idx) break;
		ll rem = v.size() - src - 1;
		printf("%lld\n", n - rem);
		s.clear();
		v.clear();
	}
	
	return 0;
}