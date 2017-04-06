/* Problem: http://br.spoj.com/problems/PEDAGIO/ */

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
#define MAXN 1024

using namespace std;

int mrc[MAXN], bs[MAXN];
vi v[MAXN];

void bfs(int n) {
	queue<int> q;
	bs[n] = 0;
	mrc[n] = 1;
	q.push(n);
	int num;
	while(!q.empty()) {
		num = q.front();
		q.pop();
		for(int i = 0; i < v[num].size(); i++){
			if(mrc[v[num][i]] == 0) {
				mrc[v[num][i]] = 1;
				bs[v[num][i]] = bs[num] + 1;
				q.push(v[num][i]);
			}
		}
	}
}


int main(void){
	int n, m, l, p, t=1;
	
	while(1){
		scanf("%d %d %d %d", &n, &m, &l, &p);
	
		if(!n&&!m&&!l&&!p) break;
	
		int x, y;
		for(int i=0;i<m;i++){
			scanf("%d %d", &x, &y);
			x--;
			y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		
		memset(mrc,0,sizeof(int)*n);
		memset(bs,INF,sizeof(int)*n);
		bfs(l-1);
		
		printf("Teste %d\n", t++);
		for(int i=0;i<n;i++){
			if(bs[i] <= p && bs[i] != 0) printf("%d ", i + 1);
		}
		printf("\n\n");
		
		for(int i=0;i<n;i++) v[i].clear();
	}
	
	return 0;
}