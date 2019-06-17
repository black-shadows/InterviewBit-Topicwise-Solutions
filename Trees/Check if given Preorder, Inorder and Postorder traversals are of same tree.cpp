int search(vector<int> in, int startIn, int endIn, int data) 
{ 
    int i = 0; 
    for (i = startIn; i < endIn; i++)  
        if (in[i] == data)  
            return i;             
    return i; 
} 


void printPost(vector<int> in, vector<int> pre, vector<int> post,  int inStrt, int inEnd, int &preIndex, int &postIndex, bool &res) 
{ 
    if (inStrt > inEnd)  
        return;         

    int inIndex = search(in, inStrt, inEnd, pre[preIndex++]); 

    printPost(in, pre, post, inStrt, inIndex - 1, preIndex, postIndex, res); 

    printPost(in, pre, post, inIndex + 1, inEnd, preIndex, postIndex, res); 
    
   // System.out.println("in[inIndex] = " + in[inIndex] + "post[postIndex]= " + post[postIndex]);
    
    if(in[inIndex] != post[postIndex++]) {
       
        res = false;
    }
    //System.out.print(in[inIndex] + " "); 
} 
  
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    
    int n = A.size();
    
    int preIndex = 0; 
    int postIndex = 0;
    bool res = true;
    
    printPost(B, A, C, 0, n-1, preIndex, postIndex, res);
    
    return res;
    
}
