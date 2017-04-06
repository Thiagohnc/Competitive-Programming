/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1093 */

#include <bits/stdc++.h>

using namespace std;

int main(void){
	int ev1, ev2, at, d;
	
	while(1){
		cin >> ev1 >> ev2 >> at >> d;
		if(!ev1&&!ev2&&!at&&!d) break;
		double p1, p2, v[32];
		double p;
		int i = 0, j = 0;
		p1 = at/6.0;
		p2 = (6-at)/6.0;
		while(ev2>0){
			i++;
			ev2 -= d;
		}
		while(ev1>0){
			j++;
			ev1 -= d;
		}
		j = i + j;
		for(int k=0;k<=j;k++) v[k]=0;
		v[i]=1.0;
		for(int k = 0; k <5000; k++){
			for(int z = 1; z < j; z++){
				v[z-1] += v[z]*p1;
				v[z+1] += v[z]*p2;
				v[z] = 0;
			}
		}
		printf("%.1lf\n", v[0]*100);
	}
	
	return 0;
}