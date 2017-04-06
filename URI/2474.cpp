/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/2474/ */

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
#define MAXN 1000500

using namespace std;

/* Goldbach Conjecture */

bool prime(ll a) {
	if(a == 2) return true;
	if(a % 2 == 0) return false;
	ll lim = (ll)sqrt(a);
	for(ll i = 3; i <= lim; i+=2) {
		if(a % i == 0) return false;
	}
	return true;
}

int main(void) {
	ll n;
		
	while(scanf("%lld", &n) != EOF) {
		if(prime(n)) printf("%lld\n", n - 1);
		else if(n % 2 == 0) printf("%lld\n", n - 2);
		else if(prime(n - 2)) printf("%lld\n", n - 2);
		else printf("%lld\n", n - 3);
	}
	
	return 0;
}