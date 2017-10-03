#include<bits/stdc++.h>
#define Int long long
using namespace std;
char a[1000005];
struct node{
	node*children[26];
	node(){
		for(int i=0;i<26;i++)children[i]=NULL;
	}
};
struct trie{
	node*root;
	trie():root(NULL){}
};
Int Build(trie &T,char a[]){
	Int i,j,ans=1,l;node*temp;
	l=strlen(a);
	if(T.root!=NULL)temp=T.root;
	for(i=0;a[i]!='\0';i++){
		if(T.root==NULL){
			temp = new node;
			T.root = temp;
			temp->children[a[i]-'a'] = new node;
			temp = temp->children[a[i]-'a'];
		}else{
			if(temp->children[a[i]-'a']==NULL)
			{
				temp->children[a[i]-'a'] = new node;
				temp = temp->children[a[i]-'a'];
			}
			else
			{
				temp = temp->children[a[i]-'a'];
				ans++;
			}
		}
	}
	if(ans>l)ans=l;
	return ans;
}
void FreeMem(node* it){
	int i,j;bool cond=false;
	for(i=0;i<26;i++){
		if(it->children[i]!=NULL){
			cond=true;
			FreeMem(it->children[i]);
			it->children[i]=NULL;
		}
	}
	if(!cond){
		free(it);
	}
}
int main()
{
	Int i,j,t,n,ans;
	cin>>t;
	for(j=1;j<=t;j++){
		trie T;
		cin>>n;ans=0;
		for (i = 0; i <n; ++i)
		{
			scanf("%s",a);
			ans+=Build(T,a);
		}
		cout<<"Case #"<<j<<": "<<ans<<endl;
		FreeMem(T.root);
	}
	return 0;
}