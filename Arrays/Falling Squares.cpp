vector<int> fallingSquares(vector<pair<int, int>>& positions) {
    std::map<int, int> distro = { { 0, 0 }, { INT_MAX, 0 } };
    int n = positions.size();
    vector<int> result(n, 0);
    
    int maxH = 0, k = 0;
    for (auto& p : positions) {
        int start = p.first, end = p.first + p.second;
        auto itr1 = distro.upper_bound(start), itr2 = distro.lower_bound(end);
        
        int borderH = itr2->first == end ? itr2->second : (--itr2)++->second;
    
        int localMaxH = 0;
        for (auto iter = --itr1; iter != itr2; ++iter) {
            localMaxH = std::max(localMaxH, iter->second);
        }
        localMaxH += p.second;
        
        distro.erase(++itr1, itr2);
        
        distro[start] = localMaxH;
        distro[end] = borderH;
        
        maxH = std::max(maxH, localMaxH);
        result[k++] = maxH;
    }
    return result;
}

vector<int> Solution::solve(vector<vector<int> > &A) 
{
    
    vector<pair<int, int>> p;
    
    for(int i=0; i<A.size(); i++)
    {
        
        p.push_back(make_pair(A[i][0], A[i][1]));
        
    }
    
    return fallingSquares(p);
    
}
