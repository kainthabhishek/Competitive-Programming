#include<bits/stdc++.h>
using namespace std;
#define MAX 100000008
char text[MAX],pattern[MAX];
int Z[MAX];
void Z_Algo(int n,int m){
	int i,L,R,k,len;
	pattern[n] = '$';
	for(i=0;i<m;i++){
		pattern[n+i+1] = text[i]; 
	}
	pattern[n+i+1] = '\0';
	len = n+m+1;L=R=0;
	for(i=1;i<len;i++){
		if(i>R){
			L = R = i;
			while(R<len && pattern[R-L] == pattern[R])
				R++;
			Z[i] = R-L;
			R--; 
		}else{
			k = i-L;

			if(Z[k]<R-i+1){
				Z[i] = Z[k];
			}else{
				L = i;
				while(R<len && pattern[R-L] == pattern[R])
					R++;
				Z[i] = R-L;
				R--;
			}
		}
	}

	for(i=n+1;i<len;i++){
		if(Z[i]==n){
			printf("%d\n",i-n-1);
		}
	}
}
int main(){

	int n,m;
	while(scanf("%d",&n)!=EOF){
		scanf("%s",pattern);
		scanf("%s",text);
		m = strlen(text);
		if(m<n)printf("\n\n");
		else{
			Z_Algo(n,m);
		}
	}
	return 0;
}