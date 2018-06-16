struct e{
  string w; // word
  int d; //distance
  e(string _w, int _d): w(_w), d(_d) {}
};

bool neighbor(const string &q, const string &p){
  int diff=0, size=q.size();
  for(int i=0 ; i<size ; ++i){
    if(q[i] != p[i])  ++diff;
  }

  return diff == 1;
}

// add Solution::
int Solution::ladderLength(string start, string end, vector<string> &dictV) {
  unordered_map<string, int> mark;
  queue<e> Q;

  Q.push(e{start, 1}); mark[start] = 1;
  while(Q.size()){
    e fro = Q.front();  Q.pop(); //<<--- notice
    if(fro.w == end)  return fro.d;
    
    for(const string &word : dictV){
      if(neighbor(fro.w, word) and !mark[word]){
        Q.push(e{word, fro.d + 1});
        mark[word]=1;
      }
    }
  }
  return 0;
}