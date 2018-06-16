#define ALFABE_SIZE 26

inline int getindex(char q){return q-'a';}

vector<string> tokenize(const string &s){
	vector<string> res; string buffer;
	// tokenize the motherfucking string maiiieieieine.
	for(auto c : s){
		if(c=='_')	res.push_back(buffer), buffer.clear();
		else 		buffer.push_back(c);
 	}
 	// last buffer after _
 	res.push_back(buffer);

 	return res;
}

class yumi{
  public:
    bool end_of_word;
    yumi *next[ALFABE_SIZE];
  	yumi(){
  	    end_of_word = 0;
  		for(int i=0 ; i<ALFABE_SIZE ; ++i)  next[i] = NULL;
  	}
};

class trie{
  private:
    yumi* _root;

  	yumi* insert(yumi* root, const string &key, int ind){
  		if(!root) 	root = new yumi();
  		if(ind == key.size() ) 	 {root->end_of_word=1; return root;}
  		int next_ind = getindex(key[ind]);
  		root->next[next_ind] = insert(root->next[next_ind], key, ind+1);
  		return root;
  	}

  	bool contains(yumi *root, const string &key, int ind){
  		if(!root) 	return false;
  		if(ind == key.size()) 	return root->end_of_word;
  		return contains(root->next[getindex(key[ind])], key, ind+1);
  	}
  	
  public:
  	void insert(const string &key){
  		_root = insert(_root, key, 0);
  	}
  	bool contains(const string &key){
  		return contains(_root, key, 0);
  	}
  	trie() {
  		_root = new yumi();
  	}
    
};

void insert_wordz(trie &t, const string &good_words){
	vector<string> gw_tokens = tokenize(good_words);
	for(auto gw : gw_tokens) 	t.insert(gw);
}

vector<int> Solution::solve(string good_words, vector<string> &reviews) {
	trie t; 	// trie that stores words
	vector< pair<int, int> > val_ind;// values_indices of reviews.
    // populate t with good words.
	insert_wordz(t, good_words);
	//  a tokenized review  | goodness count  | review index.
	vector<string> rw_tokens; 	int count, index=0;
	for(auto review : reviews){
		rw_tokens = tokenize(review);
		count = 0;
		for(auto word : rw_tokens) {
			if(t.contains(word))  ++count;
		}
		val_ind.push_back(make_pair(-count, index++));
	}
	sort(val_ind.begin(), val_ind.end());
	
	vector<int> res(reviews.size());
	for(int i=0 ; i<val_ind.size() ; ++i){
		res[i] = val_ind[i].second;
	}
	return res;
}