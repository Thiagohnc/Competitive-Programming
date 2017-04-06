/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1716/ */

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

ll inv(ll a, ll b) {
	ll r[2], q, ans[2], temp;
	r[0] = b;
	r[1] = a;
	ans[0] = 0;
	ans[1] = 1;
	
	while(r[0] % r[1] != 0) {
		q = r[0] / r[1];
		temp = r[1];
		r[1] = r[0] % r[1];
		r[0] = temp;
		temp = ans[1];
		ans[1] = ans[0] - ans[1] * q;
		ans[0] = temp;
	}
	
	return ans[1];
}

ll bm(ll n, ll exp, ll m){
	ll num = 1;
	while(exp > 0) {
		if(exp % 2 == 1) num = (num * n) % m;
		n = (n * n) % m;
		exp /= 2;
	}
	return num;
}

int main(void){
	ll n, e, c, d;
	ll p, q, ph;
	cin >> n >> e >> c;
	
	for(p = 2; p < n; p++){
		if(n % p == 0) {
			q = n / p;
			break;
		}
	}
	ph = (p - 1) * (q - 1);
	d = inv(e, ph);
	while(d < 0) d += ph;
	
	cout << bm(c, d, n) << endl;
	
	return 0;
}