// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

int Solution::fibsum(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // not taking 1 two times ... :)
   int t1=1,t2=2;
   vector<int>val;
   val.push_back(t1);
   val.push_back(t2);
   // Storing all fibonacci numbers <= A
   while(1){
      if(t1+t2 > A) break;
      int temp = t2;
      t2 += t1;
      val.push_back(t2);
      t1 = temp;
   }
   int count = 0;
   while(A > 0){
       // everytime take the max value <= A to get less count
       auto it = lower_bound(val.begin(),val.end(),A);
       if(it == val.end() || *it > A){
           it--;
       }
      
       A -= *it;
       count++;
   }
   return count;
}
