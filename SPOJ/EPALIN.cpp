/* Problem: http://www.spoj.com/problems/EPALIN/ */

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
#define bitqt(X) __builtin_popcount(X)
#define bitqtll(X) __builtin_popcountll(X)
#define ii pair<int,int>
#define MAXN 200500

using namespace std;

char ch[MAXN], ns[MAXN];
int z[MAXN];

void z_alg(char ch[], int z[], int tam) {
	int l = 0, r = 0;
	z[0] = 0;
	for(int i = 1; i < tam; i++) {
		if(i == l || i > r) {
			l = i;
			if(i > r) r = i;
			while(r < tam && ch[r] == ch[r-l]) r++;
			z[l] = r - l;
			r--;
			continue;
		}
		z[i] = min(r - i + 1, z[i-l]);
		if(r + 1 < tam && z[i] == r - i + 1 && ch[r+1] == ch[r+1-i]) {
			l = i;
			i--;
		}
	}
}

int main(void) {
	
	while(scanf("%s", ch) != EOF) {
		int tam = strlen(ch);
		for(int i = tam - 1; i >= 0; i--) ns[tam-1-i] = ch[i];
		ns[tam] = '#';
		for(int i = 0; i < tam; i++) ns[tam+i+1] = ch[i];
		ns[2*tam+1] = 0;
		int tam2 = 2*tam + 1;
		z_alg(ns, z, tam2);
		int idx = tam2;
		for(int i = tam + 1; i < tam2; i++) {
			if(z[i] >= (tam2-i)/2) {
				idx = i;
				break;
			}
		}
		idx -= tam + 1;
		for(int i = 0; i < tam; i++) putchar(ch[i]);
		for(int i = idx - 1; i >= 0; i--) putchar(ch[i]);
		puts("");
	}
	
	return 0;
}