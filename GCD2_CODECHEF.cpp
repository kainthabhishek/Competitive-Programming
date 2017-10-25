/* Problem : https://www.codechef.com/problems/GCD2 
   Author : Abhishek Kainth */

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
	cin >> t;
	while(t--){
		scanf("%d %s",&a,b);
		if(a==0)cout<<b<<endl;
		else{
			m=0;
			for(i=0;b[i]!='\0';i++){
				m = (m * 10%a) + (b[i]-'0')%a;
			}
			ans = gcd(m,a);
			//cout << ans ;
		}
	}
	return 0;
}
