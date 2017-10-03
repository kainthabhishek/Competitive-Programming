#include<bits/stdc++.h>
using namespace std;
#define Int long long
Int tree[10000008],lazy[10000008];
Int getSolLazy(Int low,Int high,Int index,Int l,Int r)
{
	if(high<l||high<low||low>r)
		return 0;
	if(lazy[index]!=0)
	{
		tree[index] = max(lazy[index],tree[index]);
		if(high!=low)
		{
			lazy[2*index + 1] = lazy[index];
			lazy[2*index + 2] = lazy[index];
		}
		lazy[index] = 0;
	}
	if(low>=l&&high<=r)
		return tree[index];
	Int mid = low + (high-low)/2;
	return max(getSolLazy(low,mid,2*index + 1,l,r),getSolLazy(mid+1,high,2*index + 2,l,r));
}
void LazyUpdate(Int low,Int high,Int index,Int l,Int r,Int val)
{
	if(lazy[index]!=0)
	{
		tree[index] = max(lazy[index],tree[index]);
		if(high!=low)
		{
			lazy[2*index + 1] = lazy[index];
			lazy[2*index + 2] = lazy[index];
		}
		lazy[index] = 0;
	}
	if(high<l||low>high||low>r)
		return;
	if(low>=l&&high<=r)
	{
		tree[index] = max(val,tree[index]);
		if(high!=low)
		{
			lazy[2*index+1] = val;
			lazy[2*index+2] = val;
		}
		return;
	}
	Int mid = low + (high-low)/2;
	LazyUpdate(low,mid,2*index + 1,l,r,val);
	LazyUpdate(mid+1,high,2*index + 2,l,r,val);
	tree[index] = max(tree[2*index + 1] , tree[2*index + 2]);
}
Int Build(Int low,Int high,Int index)
{
	if(high==low)
	{
		tree[index] = input[high];
		return tree[index];
	}
	Int mid = low + (high-low)/2;
	tree[2*index + 1] = Build(low,mid,2*index + 1);
	tree[2*index + 2]= Build(mid+1,high,2*index + 2);
	tree[index] = max(tree[2*index + 1],tree[2*index + 2]);
	return tree[index];
}
int main()
{
	Int t,n,c,p,q,m,v,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&c);
		for(i=0;i<10000008;i++)
		{
			lazy[i] = tree[i] = 0;
		}
		while(c--)
		{
			scanf("%lld",&m);
			if(m==0)
			{
				scanf("%lld %lld %lld",&p,&q,&v);
				LazyUpdate(0,n-1,0,p-1,q-1,v);
			}
			else
			{
				scanf("%lld %lld",&p,&q);
				printf("%lld\n",getSolLazy(0,n-1,0,p-1,q-1));
			}
		}
	}
	return 0;
}