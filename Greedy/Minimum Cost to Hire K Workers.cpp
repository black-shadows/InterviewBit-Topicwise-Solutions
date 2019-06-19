static bool compare(const pair<double,int> &w1, const pair<double,int> &w2) {
        return w1.first < w2.first;
    }

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    priority_queue<int> quality_heap;
    vector<pair<double,int>> worker;
    for(int i=0; i< quality.size(); i++)
        worker.push_back(make_pair(double(wage[i])/quality[i],quality[i]));
    sort(worker.begin(),worker.end(), compare);
    double ratio = 0;
    int total_quality = 0;
    double min_cost = 1.0*INT_MAX;
    for(auto w: worker) {
        if(quality_heap.size() == K && w.second < quality_heap.top()) {
            total_quality -= quality_heap.top();
            quality_heap.pop();
        }
        if(quality_heap.size() < K) {
            quality_heap.push(w.second);
            total_quality+=w.second;
            ratio = w.first;
            if(quality_heap.size() == K)
                min_cost = min(ratio*total_quality, min_cost);
        }
    }
    assert(min_cost>=0&&min_cost<=2000000000.00);
    return min_cost;
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    double ans=mincostToHireWorkers(A,B,C);
    return ceil(ans);
}