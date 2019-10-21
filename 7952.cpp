#include <bits/stdc++.h>
using namespace std;
struct Seg
{
  long long x, y;
  Seg(long long x = 0, long long y = 0) : x(x), y(y) { }
};
int main()
{
  int n;
  while (cin >> n)
  {
    vector<long long> xs;
    vector<Seg> segs(n);
    for (Seg &seg : segs)
    {
      cin >> seg.x >> seg.y;
      xs.push_back(seg.x);
      xs.push_back(seg.y);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    vector<vector<long long>> ends(xs.size());
    for (Seg &seg : segs)
    {
      long long bg = lower_bound(xs.begin(), xs.end(), seg.x) - xs.begin();
      long long ed = lower_bound(xs.begin(), xs.end(), seg.y) - xs.begin();
      ends[bg].push_back(ed);
    }
    vector<long long> dp(xs.size() + 1);
    dp[xs.size()] = 0;
    for (int i = xs.size() - 1; i >= 0; --i)
    {
      long long &cur = dp[i];
      cur = dp[i + 1];
      for (long long pt : ends[i])
        cur = max(cur, xs[pt] - xs[i] + dp[pt]);
    }
    cout << dp[0] << "\n";
  }
}
