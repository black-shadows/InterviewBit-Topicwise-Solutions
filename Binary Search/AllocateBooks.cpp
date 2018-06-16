bool isPossible(vector<int> &pages,int n,int m,int mid)
{
 int cur_sum = 0;
 int cnt = 1;
 for(int i=0;i<pages.size();i++)
 {
  cur_sum += pages[i];
  if(cur_sum<=mid)
  {
   continue;
  }
  else
  {
   cnt++;
   cur_sum = pages[i];
   if(cur_sum>mid)
   {
       return false;
   }
  }
 }
 if(cnt>m)
 {
  return false;
 }
 else
 {
  return true;
 }
}

int getAns(int n,int m,vector<int> &pages)
{
    if(pages.size()<m)
    return -1;
 int beg = 0;
 int end = 1000000007;
 int pivot = -1;
 while(beg<=end)
 {
  int mid = beg+(end-beg)/2;
  if(isPossible(pages,n,m,mid))
  {
   pivot = mid;
   end = mid-1;
  }
  else
  {
   beg = mid+1;
  }
 }
 return pivot;
}

int Solution::books(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return getAns(A.size(),B,A);
}