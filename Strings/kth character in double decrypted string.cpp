string Solution::solve(string A, int B) {
        int n = A.length();
        vector<pair<char,long long int>> s;
        long long int l = 0;
        for(int i=0;i<n;)
        {
            if(isalpha(A[i]))
            {
                
                l++;
                s.push_back(make_pair(A[i],l));
                i++;
            }
            else if(isdigit(A[i]))
            {
                int x = 0;
                while(i<n && isdigit(A[i]))
                {
                    x = x*10 + (int)(A[i]-'0');
                    i++;
                }
                l *= (long long int)x;
            }
            
            if(l>B)
            break;
        }
        while(s.size()>0)
        {
            
            pair<char,long long int> p = s[s.size()-1];
            char ch = p.first;
            long long int z = p.second;
            B = B%(int)z;
            if(B==0)
            {
                return (string) ""+ch;
            }
            
            s.pop_back();
        }
    }
