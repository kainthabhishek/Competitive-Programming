#include<bits/stdc++.h>
using namespace std;
#define Int long long
#define MAX 10000010	//Define MAX here
int sieve[MAX]={0},prime[MAX],ETF[MAX]={0};
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int fill(){
	Int i,j,index=0;
	for(i=2;i*i<MAX;i++){
		if(sieve[i]==0){
			for(j=i*i;j<MAX;j+=i){
				sieve[j]++;
			}
		}
	}
	for(i=2;i<MAX;i++)if(sieve[i]==0)prime[index++] = i;
		return index;
}
int phi(int n)
{    
    Int result,i,j,d,m;  
    for(i=0;prime[i]*prime[i]<=n;i++){
    	if(n%prime[i]==0){
            m=prime[i];
            n/=prime[i];
            d = gcd(n,m);
            result = (ETF[n]*ETF[m]*d)/ETF[d];
            break;
    	}
    }
    return result;
}
int main(){
	int t,n,i,j,a,b,index;
	index = fill();
	ETF[1]=1;ETF[2] = 1;
	for(i=3;i<MAX;i++){
		if(i%2==0){
			j=i/2;
			if(j%2==0){
				ETF[i] = 2*ETF[j];
			}else{
				ETF[i] = ETF[j];
			}
		}
		else if(sieve[i]==0){
			ETF[i] = i-1;
		}
		else
		{
			ETF[i] = phi(i);
		}
	}
	
	return 0;
}