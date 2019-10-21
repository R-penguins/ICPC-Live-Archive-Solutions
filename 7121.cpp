#include <bits/stdc++.h>
#define B begin()
#define E end()
using namespace std;
struct Rect
{
  int x1, y1, x2, y2;
};
int main()
{
  int n;
  while ((cin >> n) && n > 0)
  {
    vector<Rect> rects;
    vector<int> xs, ys;
    for (int i = 0; i < n; ++i)
    {
      Rect r;
      cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
      if (r.x1 > r.x2)
        swap(r.x1, r.x2);
      if (r.y1 > r.y2)
        swap(r.y1, r.y2);
      if (r.x1 == r.x2 || r.y1 == r.y2)
        continue;
      xs.push_back(r.x1);
      xs.push_back(r.x2);
      ys.push_back(r.y1);
      ys.push_back(r.y2);
      rects.push_back(r);
    }
    sort(xs.B, xs.E);
    sort(ys.B, ys.E);
    xs.erase(unique(xs.B, xs.E), xs.E);
    ys.erase(unique(ys.B, ys.E), ys.E);
    vector<vector<int>> grid(xs.size(), vector<int>(ys.size(), 0));
    for (Rect &r : rects)
    {
      int rb = lower_bound(xs.B, xs.E, r.x1) - xs.B;
      int re = lower_bound(xs.B, xs.E, r.x2) - xs.B;
      int cb = lower_bound(ys.B, ys.E, r.y1) - ys.B;
      int ce = lower_bound(ys.B, ys.E, r.y2) - ys.B;
      for (int r = rb; r < re; ++r)
        for (int c = cb; c < ce; ++c)
          ++grid[r][c];
    }
    int ans = 0;
    for (auto &row : grid)
      for (int i : row)
        ans = max(ans, i);
    cout << ans << "\n";
  }
}
