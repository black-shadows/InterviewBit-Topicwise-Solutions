struct Trie 
{ 
    bool leaf; 
    Trie* children[2]; 
}; 
  
/*function to get Trienode*/
Trie* getNewTrieNode() 
{ 
    Trie* node = new Trie; 
    node->children[0] = node->children[1] = NULL; 
    node->leaf = false; 
    return node; 
} 

bool insert(Trie*& head, vector<int> arr, int N) 
{ 
    Trie* curr = head; 
  
    for (int i = 0; i < N; i++) 
    { 
        /*creating a new path if it don not exist*/
        if (curr->children[arr[i]] == NULL) 
            curr->children[arr[i]] = getNewTrieNode(); 
  
        curr = curr->children[arr[i]]; 
    } 
  
    /*if the row already exist return false*/
    if (curr->leaf) 
        return false; 
  
    /* making leaf node tree and return true*/
    return (curr->leaf = true); 
} 

vector<int> Solution::solve(vector<vector<int> > &mat) 
{
    
    vector<int> ans;
    
    int M = mat.size();
    
    int N = mat[0].size();
    
        Trie* head = getNewTrieNode(); 
  
    /*inserting into Trie and checking for dulpicates*/
    for (int i = 0; i < M; i++) 
  
        // If already exists 
        if (!insert(head, mat[i], N)) 
            
            ans.push_back(i+1);
            
    return ans;
}
