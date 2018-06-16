bool isPossible(int row,int col,vector<vector<int> > &curr_state)
{
    int n = curr_state.size();
    for(int i=0;i<row;i++)
    {
        if(curr_state[i][col])
        return 0;
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(curr_state[i][j])
        {
            return 0;
        }
    }
    for(int i=row,j=col;i>=0&&j<n;i--,j++)
    {
        if(curr_state[i][j])
        {
            return 0;
        }
    }
    
    return 1;
}

void solveForSolution(vector<vector<string> > &toreturn,vector<vector<int> > &curr_state,int n,int row)
{
    if(row == n)
    {
        vector<string> vec;
        string s;
        for(int i=0;i<curr_state.size();i++)
        {
            s = "";
            for(int j=0;j<n;j++)
            {
                if(curr_state[i][j] == 1)
                {
                    s+="Q";
                }
                else
                {
                    s+=".";
                }
            }
            vec.push_back(s);
        }
        toreturn.push_back(vec);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isPossible(row,i,curr_state))
        {
            curr_state[row][i] = 1;
            solveForSolution(toreturn,curr_state,n,row+1);
            curr_state[row][i] = 0;
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string> > toreturn;
    vector<vector<int> > curr_state(A,vector<int>(A,0));
    solveForSolution(toreturn,curr_state,A,0);
    return toreturn;
}