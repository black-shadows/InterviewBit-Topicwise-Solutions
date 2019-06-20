string Solution :: solve(vector <vector <int> > &A)
{
    int n = A.size();
    string temp = "";
    for (int i = 0 ; i < n ; i++)
    {
        temp = temp + "-" + to_string(A[0][i]);
    }
    temp += temp;
    for (int i=1; i<n; i++)
    {
        string s = "";
        for (int j = 0 ; j < n ; j++)
            {
             s = s + "-" + to_string(A[i][j]);
            }
        if (temp.find(s) == string::npos)
        {
            return "NO";
        }
    }
    return "YES";
}