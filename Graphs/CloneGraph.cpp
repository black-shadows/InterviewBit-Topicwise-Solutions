/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode* getNode(int x){
    return new UndirectedGraphNode (x);
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL)
        return node;
    unordered_map<UndirectedGraphNode*,bool> vis;
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mymap;
    queue<UndirectedGraphNode*> Q;
    Q.push(node);
    vis[node]=1;
    while(!Q.empty()){
        UndirectedGraphNode *thisnode=Q.front();
        Q.pop();
        
        for(int i=0;i<thisnode->neighbors.size();i++){
            if(vis.find(thisnode->neighbors[i])==vis.end()){
                vis[thisnode->neighbors[i]]=true;
                Q.push(thisnode->neighbors[i]);
            }
        }
        mymap[thisnode]=getNode(thisnode->label);
    }
    Q.push(node);
    vis.clear();
    vis[node]=1;
    while(!Q.empty()){
        UndirectedGraphNode *thisnode=Q.front();
        UndirectedGraphNode *clone=mymap[thisnode];
        Q.pop();
        for(int i=0;i<thisnode->neighbors.size();i++){
            if(vis.find(thisnode->neighbors[i])==vis.end()){
                vis[thisnode->neighbors[i]]=true;
                Q.push(thisnode->neighbors[i]);
                //cout<<clone->label<<" "<<l<<endl;
                
            }
            clone->neighbors.push_back(mymap[thisnode->neighbors[i]]);
            
        }
    }
    vis.clear();
    return mymap[node];
}