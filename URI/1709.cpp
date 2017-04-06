/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1709/ */

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
#define MAXN 200500

using namespace std;

ll v[MAXN];
int mrc[MAXN];

ll mdc(ll a, ll b) {
	if(b == 0) return a;
	return mdc(b, a % b);
}

ll mmc(ll a, ll b) {
	return (a*b)/mdc(a,b);
}

int main(void){
	ll p, n;
	
	cin >> p;
	n = p/2;
	
	for(ll i = 0; i < p; i++) {
		if(i < n) v[i] = i*2 + 1;
		else v[i] = 2*(i - n);
		mrc[i] = 0;
	}
	
	ll ans = 1;
	int idx, cont;
	for(ll i = 0; i < p; i++) {
		idx = i;
		cont = 1;
		while(mrc[idx] == 0) {
			mrc[idx] = 1;
			if(mrc[v[idx]] == 0) cont++;
			idx = v[idx];
		}
		ans = mmc(ans, cont);
	}
	
	cout << ans << endl;
	
	return 0;
}