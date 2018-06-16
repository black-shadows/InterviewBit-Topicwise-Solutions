vector<int> Solution::order(vector<int> &A, vector<int> &B) 
{
 vector<int> result(A.size(),-1);
 map<int,int> htsAndFronts;
 for(int i = 0;i<A.size();i++)
 {
    htsAndFronts[A[i]] = B[i];
 }
 for (map<int,int>::iterator it = htsAndFronts.begin();
 it != htsAndFronts.end(); ++it)
 {
    int i = 0;
    int j = 0;
    while(i!=it->second)
    {
         if(result[j]==-1)
              i++;
          j++;
    }
     while(result[j]!=-1)
           j++;
      result[j] = it->first;
 }
  return result;
}