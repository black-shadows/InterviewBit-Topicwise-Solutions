const int maxn = 100009;
vector < int > adj[maxn];
int visited[maxn];
void ini() {
  for (int i = 0; i < maxn; i++) adj[i].clear();
  memset(visited, 0, sizeof(visited));
}
bool isReachable(int s, int d) {
  if (s == d) return true;
  queue < int > q;
  q.push(s);
  visited[s] = 1;
  while (q.empty() == false) {
    int s = q.front();
    q.pop();
    for (auto v: adj[s]) {
      if (v == d) return true;
      if (visited[v] == 0) {
        visited[v] = 1;
        q.push(v);
      }
    }
  }
  return false;
}
int Solution::solve(int A, vector < vector < int > > & B) {
  assert(A >= 2 && A <= 100000);
  assert(B.size() <= 200000);
  ini();
  for (auto & it: B) adj[it[0]].push_back(it[1]);
  if (isReachable(1, A)) return 1;
  return 0;
}
