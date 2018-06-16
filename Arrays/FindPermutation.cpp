
vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size();
    int num_I =0,num_D =0;
    for(int i=0;i<n;i++)
    {
        if(A[i] == 'I')
        {
            num_I++;
        }
        else
        {
            num_D++;
        }
    }
    vector<int> toreturn;
    int ind_I,ind_D;
    if(A[0] == 'I')
    {
        ind_I = (n+1)-num_I;
        ind_D = ind_I-1;
        toreturn.push_back(ind_I);
        ind_I++;
    }
    else
    {
        ind_I = (B+1)-num_I;
        ind_D = ind_I-1;
        toreturn.push_back(ind_D);
        ind_D--;
    }
    
    
    for(int i=0;i<n;i++)
    {
        if(A[i] == 'I')
        {
            toreturn.push_back(ind_I);
            ind_I++;
        }
        else
        {
            toreturn.push_back(ind_D);
            ind_D--;
        }
        
    }
    
    return toreturn;
}