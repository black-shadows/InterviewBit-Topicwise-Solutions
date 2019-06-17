vector<int> Solution::solve(int N, vector<vector<int> > &lamps, vector<vector<int> > &queries) 
{
    
    unordered_map<int, unordered_set<long long>> xaxis;
    unordered_map<int, unordered_set<long long>> yaxis;
    unordered_map<int, unordered_set<long long>> diags;
    unordered_map<int, unordered_set<long long>> antidiags;
    unordered_set<int> lamps_set;
    
    for(auto& lamp:lamps) {
        int x = lamp[0];
        int y = lamp[1];
        int diag = x + y; // x [0, N - 1] y [0, N - 1]
        int antidiag = x - y + N - 1;
        
        xaxis[x].insert(N*(long long)x + y);
        yaxis[y].insert(N*(long long)x + y);
        diags[diag].insert(N*(long long)x + y);
        antidiags[antidiag].insert(N*(long long)x + y);
        
        lamps_set.insert(N*(long long)x + y);
    }
    
    vector<int> ans;
    
    for(auto& query:queries) {
        int x = query[0];
        int y = query[1];
        int diag = x + y;
        int antidiag = x - y + N - 1;
        
        bool found = false;
        if(xaxis[x].size() > 0) {
            found = true;
        }
        else if(yaxis[y].size() > 0) {
            found = true;
        }
        else if(diags[diag].size() > 0) {
            found = true;
        }
        else if(antidiags[antidiag].size() > 0) {
            found = true;
        }
        
        if(found)
            ans.push_back(1);
        else
            ans.push_back(0);
        
        for(int i = x - 1; i <= x + 1; i++) {
            for(int j = y - 1; j <= y + 1; j++) {
                if(i < 0 || i >= N || j < 0 || j >= N || lamps_set.find(N*(long long)i + j) == lamps_set.end())
                    continue;
                int diag_off = i + j;
                int antidiag_off = i - j + N - 1;
                
                xaxis[i].erase(N*(long long)i + j);
                yaxis[j].erase(N*(long long)i + j);
                diags[diag_off].erase(N*(long long)i + j);
                antidiags[antidiag_off].erase(N*(long long)i + j);
                
                lamps_set.erase(N*(long long)i + j);
            }
        }
    }
    
    return ans;
    
}
