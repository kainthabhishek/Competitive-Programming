//-----------------------------------------------------------------------------
void computeDP(int i, int jleft, int jright, int kleft, int kright){
 
	int jmid = (jleft + jright)/2;
 
	dp[i][jmid] = inf;
 
	int bestk = -1;
 
	for(int K = kleft; K <= jmid && K <= kright; K++){
		if(dp[i-1][K-1] + Cost(K, jmid) < dp[i][jmid] ){
			dp[i][jmid] = dp[i-1][K-1] + Cost(K, jmid);
			bestk = K;
		}
	}
 
	if(jleft <= jmid -1)
		computeDP(i, jleft, jmid - 1, kleft, bestk);
	if(jmid + 1 <= jright)
		computeDP(i, jmid + 1, jright, bestk, kright);
 
}
/*
	Call this function for every i from 1 to k
	and initialize dp for i = 0
*/
//---------------------------------------------------------------------------