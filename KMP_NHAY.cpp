//KMP Algorithm
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000008
char text[MAX],pattern[MAX];
int prefix_arr[MAX];
void BuildPrefixArr(int n){
	int i,j;
	prefix_arr[0]=0;
	j=0;i=1;
	while(i<n){
		if(pattern[i]==pattern[j]){
			prefix_arr[i] = j+1;
			i++;j++;
		}else{
			if(j==0){
				prefix_arr[i] = 0;
				i++;
			}else j = prefix_arr[j-1];
		}
	}
}
void KMP(int n,int m){
	BuildPrefixArr(n);
	int i,j;
	i=0;j=0;
	while(i<m){
		if(text[i]==pattern[j]){
			i++;j++;
			if(j==n){
				printf("%d\n",i-j);
				j = prefix_arr[j-1];
			}
		}else{
			if(j==0)i++;
			else
			j = prefix_arr[j-1];
		}
	}
}
int main(){
	int i,j,k,n,m;
	while(scanf("%d",&n)!=EOF){
		scanf("%s",pattern);
		scanf("%s",text);
		m = strlen(text);
		if(m<n)printf("\n\n");
		else{
			KMP(n,m);
		}
	}
	return 0;
}