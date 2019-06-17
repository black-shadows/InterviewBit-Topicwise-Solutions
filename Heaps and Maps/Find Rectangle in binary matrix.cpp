int isRectangle(const vector<vector<int> >& matrix) {
    int rows = matrix.size();
    if (rows == 0)
        return 0;

    int columns = matrix[0].size();
    unordered_map<int, unordered_set<int> > table;

    for (int i = 0; i < rows; ++i) {
     for (int j = 0; j < columns - 1; ++j) {
        for (int k = j + 1; k < columns; ++k) {
          if (matrix[i][j] == 1 && matrix[i][k] == 1) {
            if (table.find(j) != table.end() && table[j].find(k) != table[j].end())
                        return 1;
            if (table.find(k) != table.end() && table[k].find(j) != table[k].end())
                        return 1;
            table[j].insert(k);
            table[k].insert(j);
          }
        }
      }
    }
    return 0;
}


int Solution::solve(const vector<vector<int> > &A) {
    return isRectangle(A);
}