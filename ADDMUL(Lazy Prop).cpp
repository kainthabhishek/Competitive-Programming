/* Problem : https://www.codechef.com/JULY15/problems/ADDMUL 
   Author : Abhishek Kainth */

#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
long long tree[1000006],input[100005],lazyadd[1000006],lazymul[1000006];
 
long long Merge(long long a,long long b)
{
	long long temp;
	temp = (a+b)%M;
	return temp;
}
void pushdown(long long index,long long high,long long low)
{
	if(lazymul[index]!=1||lazyadd[index]!=0)
	{
		if(lazymul[index]!=1)
		{
			tree[index] = (lazymul[index]* tree[index])%M;
		}
		if(lazyadd[index]!=0)
		{
			tree[index] = (((high-low+1)*lazyadd[index]) + tree[index])%M;
		}
		if(high!=low)
		{
			lazyadd[2*index + 1] = (lazyadd[index] + lazyadd[2*index + 1]*lazymul[index])%M;
			lazyadd[2*index + 2] = (lazyadd[index] + lazyadd[2*index + 2]*lazymul[index])%M;
			lazymul[2*index + 1] = (lazymul[index] * lazymul[2*index + 1])%M ;
			lazymul[2*index + 2] = (lazymul[index] * lazymul[2*index + 2])%M;
		}
		lazyadd[index] = 0;
		lazymul[index] = 1;
	}
}
long long getSolLazy(long long low,long long high,long long index,long long l,long long r)
{
	pushdown(index,high,low);
	if(high<l||high<low||low>r)
	return 0;
	if(low>=l&&high<=r)
	return tree[index];
	long long mid = low + (high-low)/2;
	return Merge(getSolLazy(low,mid,2*index + 1,l,r),getSolLazy(mid+1,high,2*index + 2,l,r));
}
void LazyUpdateAdd(long long low,long long high,long long index,long long l,long long r,long long diff)
{
	pushdown(index,high,low);
	if(high<l||low>high||low>r)
	return;
	if(low>=l&&high<=r)
	{
		tree[index] += ((high-low+1)*diff)%M;
		if(high!=low)
		{
			lazyadd[2*index+1] = (diff+lazyadd[2*index+1])%M;
			lazyadd[2*index+2] = (diff+lazyadd[2*index+2])%M;
		}
		return;
	}
	long long mid = low + (high-low)/2;
	LazyUpdateAdd(low,mid,2*index + 1,l,r,diff);
	LazyUpdateAdd(mid+1,high,2*index + 2,l,r,diff);
	tree[index] = Merge(tree[2*index + 1],tree[2*index + 2]);
}
void LazyUpdateMul(long long low,long long high,long long index,long long l,long long r,long long diff)
{
	pushdown(index,high,low);
	if(high<l||low>high||low>r)
	return;
	if(low>=l&&high<=r)
	{
		tree[index] = (diff%M * tree[index]%M)%M;
		if(high!=low)
		{
			lazyadd[2*index+1] = (diff * lazyadd[2*index+1])%M;
			lazyadd[2*index+2] = (diff * lazyadd[2*index+2])%M;
			lazymul[2*index+1] = (diff * lazymul[2*index+1])%M;
			lazymul[2*index+2] = (diff * lazymul[2*index+2])%M;
		}
		return;
	}
	long long mid = low + (high-low)/2;
	LazyUpdateMul(low,mid,2*index + 1,l,r,diff);
	LazyUpdateMul(mid+1,high,2*index + 2,l,r,diff);
	tree[index] = Merge(tree[2*index + 1], tree[2*index + 2]);
}
void ReInitializer(long long low,long long high,long long index,long long l,long long r,long long diff)
{
	pushdown(index,high,low);
	if(high<l||low>high||low>r)
	return;
	if(low>=l&&high<=r)
	{
		tree[index] = ((high-low+1)*diff)%M;
		if(high!=low)
		{
			lazyadd[2*index + 1] = diff%M;
			lazyadd[2*index + 2] = diff%M;
			lazymul[2*index + 1] = 0;
			lazymul[2*index + 2] = 0;
		}
		lazymul[index] = 1;lazyadd[index] = 0;
		return;
	}
	long long mid = low + (high-low)/2;
	ReInitializer(low,mid,2*index + 1,l,r,diff);
	ReInitializer(mid+1,high,2*index + 2,l,r,diff);
	tree[index] = Merge(tree[2*index + 1] , tree[2*index + 2]);
}
long long Build(long long low,long long high,long long index)
{
	if(high==low)
	{
		tree[index] = input[high]%M;
		lazyadd[index]=0;lazymul[index]=1;
		return tree[index];
	}
	long long mid = low + (high-low)/2;
	tree[2*index + 1] = Build(low,mid,2*index + 1);
	tree[2*index + 2]= Build(mid+1,high,2*index + 2);
	lazyadd[index]=0;lazymul[index]=1;
	tree[index] = Merge(tree[2*index + 1],tree[2*index + 2]);
	return tree[index];
}
int main()
{
	long long n,q,i,j,x,y,t,v;
	scanf("%lld %lld",&n,&q);
	for(i=0;i<n;i++)scanf("%lld",&input[i]);
	Build(0,n-1,0);
	while(q--)
	{
		scanf("%lld",&t);
		if(t==1)
		{
			scanf("%lld %lld %lld",&x,&y,&v);
			LazyUpdateAdd(0,n-1,0,x-1,y-1,v);
		}
		else if(t==2)
		{
			scanf("%lld %lld %lld",&x,&y,&v);
			LazyUpdateMul(0,n-1,0,x-1,y-1,v);
		}
		else if(t==3)
		{
			scanf("%lld %lld %lld",&x,&y,&v);
			ReInitializer(0,n-1,0,x-1,y-1,v);
		}
		else
		{
			scanf("%lld %lld",&x,&y);
			printf("%lld\n",getSolLazy(0,n-1,0,x-1,y-1));
		}		
	}
	return 0;
}
