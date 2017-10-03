//---------------------------------------------------
#define MAXN 1005

int parent[MAXN],rank[MAXN];

void create_set(int n){
	
	memset(rank,0,sizeof(int)*(n+1));	
	for(int i=1; i <= n; i++)
		parent[i] = i;
}
int find_parent(int x){
	
	if(parent[x] == x)
		return x;	
	parent[x] = find_parent(parent[x]); // path-compression	
	return parent[x];
}
void merge(int x,int y){
	
	int px = find_parent(x), py = find_parent(y);
	
	if(rank[px] > rank[py]) 
		parent[py] = px;
	else 
		parent[px] = py;
	
	if(rank[px] == rank[px]) 
		rank[py]++;
}

//-----------------------------------------------------