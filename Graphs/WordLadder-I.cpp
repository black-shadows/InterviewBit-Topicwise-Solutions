int Solution::solve(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        unordered_map<string,unordered_set<string> > dict;
        string word;
        
        for(int i=0;i<wordList.size();++i)
        {   word=wordList[i];
            for(int j=0;j<n;++j)
            {
                string s=word.substr(0,j)+"*"+word.substr(j+1,n-j-1);
                dict[s].insert(word);
            }
        }
        
    unordered_set<string> visited;
    queue<pair<string, int> > q;

    q.push(make_pair(beginWord, 1)); 
    visited.insert(beginWord);
    
    while(!q.empty())
    {
        pair<string, int> x = q.front();  
        q.pop(); 
        string word = x.first;
        
        for(int i=0;i<n;++i)
        {   string adj=word.substr(0,i)+"*"+word.substr(i+1,n-i-1);
            for(unordered_set<string>::iterator it = dict[adj].begin();it!=dict[adj].end();++it)
            {   string adj_word=*it;
                if(adj_word==endWord)
                    return x.second+1;
                if(visited.find(adj_word)==visited.end())
                {
                    visited.insert(adj_word);
                    q.push(make_pair(adj_word,x.second+1));
                }    
            }
            
        }
        
    
    }
    return 0;
        
    }


