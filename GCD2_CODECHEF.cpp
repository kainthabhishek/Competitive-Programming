#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(){
	int t,a,i,j,m,ans;char b[300];
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&a,b);
		if(a==0)cout<<b<<endl;
		else{
			m=0;
			for(i=0;b[i]!='\0';i++){
				m = (m * 10%a) + (b[i]-'0')%a;
			}
			ans = gcd(m,a);
			//printf("%d\n",ans);
		}
	}
	return 0;
}