#include <bits/stdc++.h>
using namespace std;
struct Set
{
  int a, b;
  Set(int a = 0, int b = 0) : a(a), b(b) { }
};
Set intersect(Set &left, Set &right)
{
  Set l = left, r = right;
  if (r.a < l.a)
    swap(l, r);
  if (l.b < r.a)
    return Set(0, 0);
  if (l.b <= r.b)
    return Set(r.a, l.b);
  return r;
}
vector<vector<bool>> g;
vector<vector<Set>> sets;
vector<Set> room;
int n, m, k, s, t;
vector<bool> ans;
void dfs(int s, int t, int p)
{
  if (s == t)
  {
    /*
    int l = room[t].a, r = room[t].b;
    if (ans.empty())
    {
      ans.push_back(room[t].a);
      ans.push_back(room[t].b);
    }
    else if (r <= ans.front())
    {
      if (r < ans.front())
        ans.push_front(r);
      else
        ans.pop_front();
      ans.push_front(l);
    }
    else if (l >= ans.back())
    {
      if (l > ans.back())
        ans.push_back(l);
      else
        ans.pop_back();
      ans.push_back(r);
    }
    else
    {
      
    }
    */
    cout << room[t].a << " " << room[t].b << endl;
    for (int i = room[t].a; i <= room[t].b; ++i)
      ans[i] = true;
    return;
  }
  for (int i = 1; i <= n; ++i)
    if (g[s][i] && i != p)
    {
      room[i] = intersect(room[s], sets[s][i]);
      if (room[i].a)
        dfs(i, t, s);
    }
}
int main()
{
  while (cin >> n >> m >> k >> s >> t)
  {
    g = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
    sets = vector<vector<Set>>(n + 1, vector<Set>(n + 1));
    room = vector<Set>(n + 1);
    ans = vector<bool>(k + 1, false);
    while (m--)
    {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      g[a][b] = true;
      sets[a][b] = Set(c, d);
    }
    room[s] = Set(1, k);
    dfs(s, t, 0);
    int cnt = 0;
    for (int i = 1; i <= k; ++i)
      if (ans[i])
        ++cnt;
    cout << cnt << "\n";
  }
}
