const int dir[][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inside(int x, int y,int n,int m) {
        return (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1);
}

struct Grid {
    int x, y;
    int d;

    Grid(int _x = 0, int _y = 0, int _d = 0): x(_x), y(_y), d(_d) {};

    bool operator < (const Grid &g) const {
        return d > g.d;
    }
};

 int findMinimumDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        auto &a = maze;
        int n = a.size();
        int m = a[0].size();

        int sx = start[0];
        int sy = start[1];
        int ex = destination[0];
        int ey = destination[1];

        vector<vector<int>> v(n, vector<int>(m, INT_MAX));
        priority_queue<Grid> pq;
        int i;
        int d, d1;
        int x, y;
        int x1, y1;
        int x2, y2;

        pq.push(Grid(sx, sy, 0));
        while (!pq.empty() && v[ex][ey] == INT_MAX) {
            x = pq.top().x;
            y = pq.top().y;
            d = pq.top().d;
            pq.pop();
            if (v[x][y] != INT_MAX) {
                continue;
            } else {
                v[x][y] = d;
            }

            for (i = 0; i < 4; ++i) {
                x1 = x;
                y1 = y;
                d1 = 0;
                while (true) {
                    x2 = x1 + dir[i][0];
                    y2 = y1 + dir[i][1];
                    if (inside(x2, y2,n,m) && a[x2][y2] == 0) {
                        x1 = x2;
                        y1 = y2;
                        ++d1;
                    } else {
                        break;
                    }
                }
                if (d1 > 0 && v[x1][y1] == INT_MAX) {
                    pq.push(Grid(x1, y1, d + d1));
                }
            }
        }
        while (!pq.empty()) {
            pq.pop();
        }
        int res = (v[ex][ey] != INT_MAX ? v[ex][ey] : -1);
        v.clear();

        return res;
    }

int Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    return findMinimumDistance(A,B,C);
}