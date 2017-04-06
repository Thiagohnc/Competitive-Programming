/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1166/ */

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
#define MAXN 128

using namespace std;

int main(void) {
	int n, t;
	int v[MAXN];
	
	scanf("%d", &t);
	for(int k = 0; k < t; k++) {
		memset(v,0,sizeof(int)*MAXN);
		scanf("%d", &n);
		for(int i = 1;; i++) {
			int j;
			for(j = 0; j < n; j++) {
				if(v[j] == 0 || sqrt(v[j] + i) == (int)sqrt(v[j] + i)) {
					v[j] = i;
					break;
				}
			}
			if(j == n) {
				printf("%d\n", i - 1);
				break;
			}
		}
	}
	
	return 0;
}