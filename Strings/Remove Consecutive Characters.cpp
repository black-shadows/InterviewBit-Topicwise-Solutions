string Solution::solve(string A, int B) {
    string s;
    for(int i=0;i<A.size();i++)
    {
        int k=1,count=1;
         while(A[i]==A[i+k])
            {
                count++;
                k++;
            }
            if(count==B)
            {
                i=i+B-1;
                continue;
            }
         s.push_back(A[i]);
    }
    return s;
       
}