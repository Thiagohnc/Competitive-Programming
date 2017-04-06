/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1488/ */

#include <bits/stdc++.h>
#include <cmath>
#include <string.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define MAXN 105000
#define ull unsigned long long int

using namespace std;

inline int funcao(int a){
	return a*a + 2*a + 1;
}

int main(void){
	int n, m, a, b, c, d, inst = 1;
	
	while(1){
		scanf("%d", &n);
		if(n==0) break;
		double frac;
		int yes = 0;
		for(m = sqrt(n) + 1; m > 0; m--){
			frac = (double)n/(double)funcao(m);
			if(frac == (int)frac){
				yes = 1;
				break;
			}
		}
		printf("Instancia %d\n", inst++);
		if(yes){
			c = n / funcao(m);
			a = (c * m) - m;
			b = (c * m) + m;
			d = c * m * m;
			printf("%d %d %d %d %d\n\n", m, a, b, c, d);
		}
		else printf("%d nao e quadripartido\n\n", n);
	}
	
	return 0;
}