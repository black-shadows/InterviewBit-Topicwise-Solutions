class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    Point() : Point(0, 0) {}

    void ChangeOrigin(const Point &org) { x -= org.x; y -= org.y; }

    bool operator<(const Point &other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
    
    bool operator==(const Point &other) {
        return !((*this) < other) && !(other < (*this));
    }
};

class ValPoint : public Point {
public:
    int val = 0;
    ValPoint(int x, int y) : Point(x, y) {}
    ValPoint() : Point() {}
};

int Solution::solve(vector<int> &x, vector<int> &y) 
{
    vector<ValPoint> points(x.size());
    for (int i = 0; i < x.size(); i++) points[i] = ValPoint(x[i], y[i]);
    sort(points.begin(), points.end());
    int last = 0;
    for (int i = 0; i < points.size(); i++) {
        int j = 1;
        while (i + j < points.size() && points[i] == points[i + j]) j++;
        points[last] = points[i];
        points[last].val = j;
        last++;
        i += (j - 1);
    }
    points.resize(last);

    int res = 0;
    while (!points.empty()) {
        auto p = points.back();
        //cout << "p.x: " << p.x << " "<< p.y << " ; ";
        points.pop_back();
        vector<ValPoint> n_points(points.size());
        transform(points.begin(), points.end(), n_points.begin(), [&p] (ValPoint p1) { 
            p1.ChangeOrigin(p);
            if (p1.y < 0 && p1.x < 0) { p1.y *= -1; p1.x *= -1; }
            if (p1.y < 0 && p1.x >= 0) { p1.y *= -1; p1.x *= -1; }
            return p1; 
        });
        auto it1 = partition(n_points.begin(), n_points.end(), [] (const ValPoint &p1) { return p1.y != 0; });
        int curr_res = p.val;
        for (auto it2 = it1; it2 != n_points.end(); it2++) {
            curr_res += (*it2).val;
        }
        res = max(res, curr_res);
        n_points.resize(distance(n_points.begin(), it1));
        //const auto sml = [&p] (const Point &p1, const Point &p2) { return (p1.x - p.x) * (p2.y - p.y) < (p2.x - p.x) * (p2.y - p.y); };
        //const auto eq =  [&p, &sml] (const Point &p1, const Point &p2) { return !sml(p1, p2) && !sml(p1, p2);  };
        const auto sml = [&p] (const ValPoint &p1, const ValPoint &p2) { return (p1.x) * (p2.y) < (p2.x) * (p1.y); };
        const auto eq =  [&p, &sml] (const ValPoint &p1, const ValPoint &p2) { return !sml(p1, p2) && !sml(p2, p1);  };
        sort(n_points.begin(), n_points.end(), sml);
        //cout << " size =  " << n_points.size() << " ";
        for (int i = 0; i < n_points.size(); i ++) {
            //cout << " | i = " << i << " ";
            curr_res = p.val;
            int j = 0;
            while (i + j < n_points.size() && eq(n_points[i], n_points[i + j])) {
                curr_res += n_points[i + j].val;
                j++;
                //cout << " n_points[i] = " << n_points[i].x  << " " << n_points[i].y <<
                //    " n_points[i + j] = " << n_points[i + j].x << " " << n_points[i + j].y << " ";
            }
            //cout << " j = " << j << "  ";
            res = max(res, curr_res);
            i += (j - 1);
        }
    }
    return res;
}