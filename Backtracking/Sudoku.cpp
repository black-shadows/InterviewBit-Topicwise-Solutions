bool isValidForRow(vector<vector<char> > &board,int row,char ch)
{
 for(int i=0;i<9;i++)
 {
  if(board[row][i] == ch)
  {
   return 0;
  }
 }
 return 1;
}

bool isValidForCol(vector<vector<char> > &board,int col,char ch)
{
 for(int i=0;i<9;i++)
 {
  if(board[i][col] == ch)
  {
   return 0;
  }
 }
 return 1;
}

bool isValidForGrid(vector<vector<char> > &board,int row,int col,char ch)
{
 int I = 3*(row/3);
 int J = 3*(col/3);
 for(int i=I;i<I+3;i++)
 {
  for(int j=J;j<J+3;j++)
  {
   if(board[i][j] == ch)
   {
    return 0;
   }
  }
 }
 return 1;
}

bool getPossible(vector<vector<char> > &board,int row,int col,char ch)
{
 if(isValidForRow(board,row,ch)&&isValidForCol(board,col,ch)&&isValidForGrid(board,row,col,ch))
 {
  return true;
 }
 return false;
}

bool findUnassigned(vector<vector<char> > &board,int &row,int &col)
{
 for(int i=0;i<9;i++)
 {
  for(int j=0;j<9;j++)
  {
   if(board[i][j] == '.')
   {
    row = i;
    col = j;
    return true;
   }
  }
 }
 return false;
}

bool solveToGetSudoku(vector<vector<char> > &board)
{
 int row,col;
 if(!findUnassigned(board,row,col))
 {
  return true;
 }
 char ch[] = {'1','2','3','4','5','6','7','8','9'};
 for(int i=0;i<9;i++)
 {
  if(getPossible(board,row,col,ch[i]))
  {
   board[row][col] = ch[i];
   if(solveToGetSudoku(board))
   {
    return true;
   }
   board[row][col] = '.';
  }
 }
 return false;
}


void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    solveToGetSudoku(A);
}
