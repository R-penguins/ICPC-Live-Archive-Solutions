#include <bits/stdc++.h>
using namespace std;
struct Pt
{
  array<long long, 3> v;
};
int main()
{
  int n;
  long long k;
  while ((cin >> n >> k) && n && k)
  {
    k *= k;
    vector<Pt> pts(n);
    for (Pt &pt : pts)
      cin >> pt.v[0] >> pt.v[1] >> pt.v[2];
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
      {
        bool ok = true;
        long long sum = 0;
        for (int pos = 0; pos < 3; ++pos)
        {
          long long cur = pts[i].v[pos] - pts[j].v[pos];
          if ((sum += cur * cur) >= k)
          {
            ok = false;
            break;
          }
        }
        if (ok)
        {
          ++ans;
          //cout << i << ", " << j<< endl;
        }
      }
    cout << ans << "\n";
  }
}
