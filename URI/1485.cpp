/* Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1485/ */

#include <cstdio>
#include <string.h>
#define MAXN 512
#define INF 0x3f3f3f3f

int max(int a, int b){
  if(a>b) return a;
  else return b;
}

int m[250][MAXN][MAXN], s, b, sum[MAXN], p[MAXN][MAXN];

int mod(int a){
	while(a<0) a+=s;
	while(a>=s) a-=s;
	return a;
}

using namespace std;

int main(void){
	while(1){
		scanf("%d %d", &s, &b);
		if(!s&&!b) break;
		memset(sum,0,sizeof(int)*(s+1));
		for(int i=0;i<s;i++){
			memset(p[i],0,sizeof(int)*(s+1));
		}
		for(int i=0;i<s;i++) scanf("%d", &sum[i]);
		int first=sum[0];
		for(int i=0;i<s-1;i++) sum[i]+=sum[i+1];
		sum[s-1]+=first;
		for(int i=b-1;i>=0;i--){
		  int num;
		  scanf("%d", &num);
		  num*=-1;
		  for(int j=0;j<s;j++) p[i][j]=num*sum[j];
		}
		
		for(int k=0;k<=b;k++){
				for(int i=0;i<=s;i++) memset(m[k][i],0,sizeof(int)*(s+1));
			}
		
		// First Matrix
		for(int i=0;i<s;i++) m[0][i][i]=p[0][i];
		for(int i=0;i<s;i++){
		  for(int j=i+1;j<s;j++){
			m[0][i][j]=max(p[0][j],m[0][i][j-1]);
		  }
		}
		for(int i=s-1;i>0;i--){
		  for(int j=0;j<i;j++){
			if(j==0){
			  if(i<s-1) m[0][i][j]=max(p[0][i],m[0][i+1][j]);
			  else m[0][i][j]=max(p[0][i], p[0][j]);
			}
			else{
			  m[0][i][j]=max(p[0][j],m[0][i][j-1]);
			}
		  }
		}

		// Other Matrices
		for(int k=1;k<b;k++){
			for(int j=s-1;j>=0;j--){
				for(int i=j;i>=0;i--){
				  if(j-i<k*2||mod(i-j)<2){
					  m[k][i][j]=-INF;
				  }
				  else m[k][i][j]=max(p[k][i]+m[k-1][(i+2)%s][j],m[k][(i+1)%s][j]);
				}
				for(int i=s-1;i>j;i--){
					if(mod(j-i)<k*2||mod(i-j)<2){
						m[k][i][j]=-INF;
						if(k==2){
						}
					}	
					if(m[k][i][j]!=-INF){
						if(j==s-1) m[k][i][j]=p[k][i]+m[k-1][(i+2)%s][j];
						else m[k][i][j]=max(p[k][i]+m[k-1][(i+2)%s][j],m[k][(i+1)%s][j]);
					}
				}
			}
		}
		int maximo = -INF;
		for(int i=0;i<s;i++){
			for(int j=0;j<s;j++){
				if(m[b-1][i][j]>maximo) maximo = m[b-1][i][j];
			}
		}
		printf("%d\n", maximo);
  }

  return 0;
}
