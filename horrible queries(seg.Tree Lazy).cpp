#include<bits/stdc++.h>
using namespace std;
#define Int long long
Int tree[10000008],lazy[10000008];
Int Merge(Int a,Int b)
{
	return a+b;
}
Int getSolLazy(Int low,Int high,Int index,Int l,Int r)
{
	if(high<l||high<low||low>r)
		return 0;
	if(lazy[index]!=0)
	{
		tree[index] += (high-low+1)*lazy[index];
		if(high!=low)
		{
			lazy[2*index + 1] += lazy[index];
			lazy[2*index + 2] += lazy[index];
		}
		lazy[index] = 0;
	}
	if(low>=l&&high<=r)
		return tree[index];
	Int mid = low + (high-low)/2;
	return Merge(getSolLazy(low,mid,2*index + 1,l,r),getSolLazy(mid+1,high,2*index + 2,l,r));
}
void LazyUpdate(Int low,Int high,Int index,Int l,Int r,Int diff)
{
	if(lazy[index]!=0)
	{
		tree[index] += (high-low+1)*lazy[index];
		if(high!=low)
		{
			lazy[2*index + 1] += lazy[index];
			lazy[2*index + 2] += lazy[index];
		}
		lazy[index] = 0;
	}
	if(high<l||low>high||low>r)
		return;
	if(low>=l&&high<=r)
	{
		tree[index] += (high-low+1)*diff;
		if(high!=low)
		{
			lazy[2*index+1] += diff;
			lazy[2*index+2] += diff;
		}
		return;
	}
	Int mid = low + (high-low)/2;
	LazyUpdate(low,mid,2*index + 1,l,r,diff);
	LazyUpdate(mid+1,high,2*index + 2,l,r,diff);
	tree[index] = tree[2*index + 1] + tree[2*index + 2];
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