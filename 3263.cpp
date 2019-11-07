#include <bits/stdc++.h>
using namespace std;
struct Pt
{
    double x, y;
    Pt(double x = 0, double y = 0) : x(x), y(y) { }
}
int main()
{
    int n;
    while ((cin >> n) && n)
    {
        vector<Pt> pts(n);
        for (Pt &pt : pts)
            cin >> pt.x >> pt.y;
        vector<Pt> v = pts;
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n - 1; ++j)
                v.push_back(intersect(pts[i], pts[i + 1], pts[i], pts[j], pts[j + 1]));
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
}
