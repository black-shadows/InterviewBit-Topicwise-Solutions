int Solution::solve(vector<int> &A, int B) {
    int i,j,len,temp;
    int n = A.size();
    i = j = 0;
    int maxele, minele;
    int minindex,maxindex,maxlen;
    maxlen = 0;
    maxele = minele = A[0];
    minindex = maxindex = 0;    //maintain indexes so we don't have to search
    while(i<=j && j<n)
    {
        if(A[j]<minele) 
        {
            minele = A[j];
            minindex = j;
        }
        else if(A[j]>maxele)
        {
            maxele = A[j];
            maxindex = j;
        }
        if(maxele-minele < B){
            len = j-i+1;
            j++;
            if(len > maxlen)
                maxlen = len;
            if(j>=n) break;
        }
        else
        {
            temp = min(minindex,maxindex);
            if(i == temp)
                i++;
            else 
                i = temp;
            j = i+1;
            if(j>=n) break;
            minele = maxele = A[i];
            minindex = maxindex = i;
        }
    }
    return maxlen;

}