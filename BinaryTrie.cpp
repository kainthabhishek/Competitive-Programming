//---------------------------------------
#define LOGN 20
struct Node{
	Node * A[2];

	Node(){
		A[0] = A[1] = NULL;
	}
};

Node * Trie;

void Insert(int val){

	if(Trie == NULL){
		Trie = new Node;
	}

	Node * itr = Trie;
	
	for(int i = LOGN; i >= 0; i--){
		int x = (1 & (val >> i));
		
		if(itr->A[x] == NULL)
			itr->A[x] = new Node;
		
		itr = itr->A[x];
	}
}

// Change Query Function as per requirement

int Query(int val){

	int ans = 0;
	Node * itr = Trie;

	for(int i = LOGN; i >= 0; i--){

		int x = (1 & (val >> i));
		if(itr->A[x] == NULL)
			x = !x;
		
		itr = itr->A[x];
		ans |= (x << i);	
	}
	return (ans^val);
}

//------------------------------------