string Solution::simplifyPath(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        stack<char> path;
    int i = 0;
    while(i<A.size())
    {
       // cout<<"Hello"<<endl;
        if(A[i] == '/')
        {
            path.push(A[i]);
          //  cout<<A[i]<<" pushEd"<<endl;
            i++;
            while(i<A.size()&&A[i]=='/')
            {
                i++;
            }
        }
        else if(A[i] == '.')
        {
            i++;   
            if(i<A.size())
            {
                if(A[i]=='/')
                {
                    i++;
                }
                else if(A[i] == '.')
                {
                    i++;
                    if(i<A.size())
                    {
                        if(A[i] == '/')
                        {
                            if(path.size()>1)
                            {
                        //        cout<<path.top()<<" poped"<<endl;
                                path.pop();
                                while(!path.empty() && (('A'<=path.top() && path.top()<='Z') || ('a'<=path.top() && path.top()<='z')))
                         //       cout<<path.top()<<" poped"<<endl;
                                path.pop();
                            }
                        }
                        i++;
                    }
                    else
                    {
                        if(path.size()>1)
                            {
                        //        cout<<path.top()<<" poped"<<endl;
                                path.pop();
                                while(!path.empty() && (('A'<=path.top() && path.top()<='Z') || ('a'<=path.top() && path.top()<='z')))
                         //       cout<<path.top()<<" poped"<<endl;
                                path.pop();
                            }
                        
                    }
                }
            }
        }
        else
        {
          //  cout<<A[i]<<" pushed"<<endl;
            path.push(A[i]);
            i++;
        }
    }
    string toreturn  = "";
    
    while(path.size()>1 && !path.empty() && path.top()=='/')
    {
     path.pop();
    }
    while(!path.empty())
    {
     toreturn += path.top();
     path.pop();
    }
    reverse(toreturn.begin(),toreturn.end());
    return toreturn;
}