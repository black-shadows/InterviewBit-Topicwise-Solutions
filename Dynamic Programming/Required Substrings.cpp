struct AhoCorasick {
  static const int UNDEF = 0;
  static const int MAXN = 360;
  static const int CHARSET = 26;

  int end;
  int tag[MAXN];
  int fail[MAXN];
  int trie[MAXN][CHARSET];

  void init() {
    tag[0] = UNDEF;
    fill(trie[0], trie[0] + CHARSET, -1);
    end = 1;
  }

  void add(int m, const int* s, int t) {
    int p = 0;
    for (int i = 0; i < m; ++i) {
      if (trie[p][*s] == -1) {
        tag[end] = UNDEF;
        fill(trie[end], trie[end] + CHARSET, -1);
        trie[p][*s] = end++;
      }
      p = trie[p][*s];
      ++s;
    }
    tag[p] = t;
  }

  void build() {
    queue<int> bfs;
    fail[0] = 0;
    for (int i = 0; i < CHARSET; ++i) {
      if (trie[0][i] != -1) {
        fail[trie[0][i]] = 0;
        bfs.push(trie[0][i]);
      } else {
        trie[0][i] = 0;
      }
    }
    while (!bfs.empty()) {
      int p = bfs.front();
      tag[p] |= tag[fail[p]];
      bfs.pop();
      for (int i = 0; i < CHARSET; ++i) {
        if (trie[p][i] != -1) {
          fail[trie[p][i]] = trie[fail[p]][i];
          bfs.push(trie[p][i]);
        } else {
          trie[p][i] = trie[fail[p]][i];
        }
      }
    }
  }
};

const int MAXN = 6;
const int MAXL = 60;
const int MOD = 1000000009;

int a[MAXL];
int dp[MAXL][AhoCorasick::MAXN][1 << MAXN];

int countsubstrings(vector <string> words, int C, int L) {
  int n = words.size();
  AhoCorasick ac;
  ac.init();
  for (int i = 0; i < n; ++i) {
    int m = words[i].length();
    for (int j = 0; j < m; ++j) {
      a[j] = words[i][j] - 'a';
    }
    ac.add(m, a, 1 << i);
  }
  ac.build();

  fill(dp[0][0], dp[L + 1][0], 0);
  dp[0][0][ac.tag[0]] = 1;
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < ac.end; ++j) {
      for (int k = 0; k < (1 << n); ++k) {
        if (dp[i][j][k] != 0) {
          for (int t = 0; t < AhoCorasick::CHARSET; ++t) {
            int jj = ac.trie[j][t];
            int kk = k | ac.tag[jj];
            dp[i + 1][jj][kk] = (dp[i + 1][jj][kk] + dp[i][j][k]) % MOD;
          }
        }
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < ac.end; ++j) {
    for (int k = 0; k < (1 << n); ++k) {
      if (__builtin_popcount(k) == C) {
        ans = (ans + dp[L][j][k]) % MOD;
      }
    }
  }
  return ans;
}

int Solution::solve(vector<string> &A, int B, int C) {
    return countsubstrings(A,B,C);
}