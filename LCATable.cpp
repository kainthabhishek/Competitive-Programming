//----------------------------------------------

#define MAX 300005
#define LOGMAX 20

int L[MAX], LCA[MAX][LOGMAX], P[MAX];// L(i) = level of i, P(i) = parent of i, LCA(i,j) = 2^j ances of i;

//DFS to fill P and L in O(N)
void dfs1(int curr, int par, int lev){

	P[curr] = par;
	L[curr] = lev;

	for(int child : G[curr])
		if(child != par)
			dfs1(child, curr, lev + 1);
}

//Func to fill LCATable in O(NlogN)
void fillLCA(int N){

	int i, j;

	for(i = 0; i <= N; i++)
		for(j = 0; (1 << j) <= N; j++)
			LCA[i][j] = -1;

	for(i = 1; i <= N; i++)
		LCA[i][0] = P[i];

	for(j = 1; (1 << j) <= N; j++)
		for(i = 1; i <= N; i++)
			if(LCA[i][j-1] != -1)
				LCA[i][j] = LCA[LCA[i][j-1]][j-1];
}

//Gives LCA of p and q in O(LogN)
int QueryLCA(int p, int q){

	if(L[p] < L[q])
		p ^= q, q ^= p, p ^= q;

	int log, i;

	for(log = 1; (1<<log) <= L[p]; log++);
	log--;
	
	for(i = log; i >= 0; i--)
		if(L[p] - (1 << i) >= L[q])
			p = LCA[p][i];

	if(p == q)
		return p;

	for(i = log; i >= 0; i--)
		if(LCA[p][i] != -1 && LCA[p][i] != LCA[q][i])
			p = LCA[p][i], q = LCA[q][i];

	return P[p];
}

//-------------------------------------------------------
