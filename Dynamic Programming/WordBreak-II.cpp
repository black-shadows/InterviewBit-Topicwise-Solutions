#define UNKNOWN -1
using vs = vector<string>;

vector<vs> table;
vector<string> buffer;
vector<string> res;

bool dictContains(const vector<string> &dict, const string &query){
	for(string word : dict){
		if(word == query) 	return true;
	}
	return false;
}

void bufferToRes(){
	string sentence;
	for(string word : buffer){
		sentence += word + " ";
	}
	sentence.pop_back();
	res.push_back(sentence);
}

vs _wordBreak(const string &G, const vs &dict, int start){
    // base 1: shit hit the fan
    if(start == G.length())  return vs();
	// memo
	if(table[start].size())     return table[start];
	// recurshon
    vector<string> bricks;
	string sub;
	for(int i=start ; i<G.length() ; ++i){
		sub.push_back(G[i]);
		if(dictContains(dict, sub)){
		    // base 2: reached end of string
		    if(i == G.length()-1 )  bricks.push_back(sub);
			
			vs rest = _wordBreak(G, dict, i+1);
			for(string sol : rest){
			    bricks.push_back(sub + " " + sol);
			}
		}
	}
	return table[start] = bricks;
}

vector<string> Solution::wordBreak(string G, vector<string> &dict) {
	table = vector<vs>(G.length());
	return _wordBreak(G, dict, 0);
}