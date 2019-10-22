#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, k;
  while ((cin >> n >> k) && n && k)
  {
    vector<int> nums(n), lev(n, 0), sub(n, 0);
    for (int &i : nums)
      cin >> i;
    vector<vector<int>> sz {{1}};
    lev[0] = 0;
    sub[0] = 0;
    int nk = 0, lv = 0;
    int i = 1;
    while (i < n)
    {
      if (nk == 0)
      {
        nk = accumulate(sz[lv].begin(), sz[lv].end(), 0);
        sz.push_back(vector<int>());
        ++lv;
      }
      int cnt = 1;
      --nk;
      lev[i] = lv;
      sub[i] = nk;
      for (++i; i < n && nums[i] == nums[i - 1] + 1; ++i)
      {
        lev[i] = lv;
        sub[i] = nk;
        ++cnt;
      }
      sz.back().push_back(cnt);
    }
    int pos = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
    int pos_lv = lev[pos], pos_sub = sz[pos_lv].size() - 1 - sub[pos];
    cout << accumulate(sz[pos_lv].begin(), sz[pos_lv].end(), 0) - sz[pos_lv][pos_sub] << "\n";
  }
}
