class trienode{
    public:
    trienode* left;
    trienode* right;
    trienode(){
        left=NULL;
        right=NULL;
    }
};
class Trie{
    public:
    trienode* root;
    int mxor;
    Trie(){
        root = new trienode();
        mxor=0;
    }
    void insert(int n){
        trienode* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(bit==0){
                if((temp->left)!=NULL)temp=temp->left;
                else{
                    trienode* nw = new trienode();
                    temp->left=nw;
                    temp=nw;
                }
            }
            else{
                if((temp->right)!=NULL)temp=temp->right;
                else{
                    trienode* nw = new trienode();
                    temp->right = nw;
                    temp=nw;
                }
            }
        }
    }
    void findmxor(int n){
        int ans=0;
        trienode* temp=root;
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit==0){
                if((temp->right) != NULL){
                    ans+=(1<<i);
                    temp=temp->right;
                }
                else  temp=temp->left;
            }
            else{
                if((temp->left) !=NULL){
                    ans+=(1<<i);
                    temp=temp->left;
                }
                else  temp=temp->right;
            }
        }
        
        if(ans>mxor)mxor=ans;
    }
};
int Solution::solve(vector<int> &A, vector<int> &B) {
    Trie t;
    for(int i=0;i<A.size();i++)t.insert(A[i]);
    for(int i=0;i<B.size();i++)t.findmxor(B[i]);
    return t.mxor;
}
