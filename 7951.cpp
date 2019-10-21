/**
 * Islands
 */
#include <bits/stdc++.h>
using namespace std;
struct Pt
{
  int x, y;
  Pt(int x = 0, int y = 0) : x(x), y(y) { }
  Pt operator+(const Pt rhs)
  {
    return Pt(x + rhs.x, y + rhs.y);
  }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  const vector<Pt> DIR {Pt(-1, 0), Pt(1, 0), Pt(0, -1), Pt(0, 1)};
  while (cin >> n >> m)
  {
    vector<string> graph(n);
    for (string &line : graph)
      cin >> line;
    int ans = 0;
    for (int r = 0; r < n; ++r)
      for (int c = 0; c < m; ++c)
        if (graph[r][c] == 'L')
        {
          ++ans;
          stack<Pt> q;
          q.push(Pt(r, c));
          while (!q.empty())
          {
            Pt cur = q.top();
            q.pop();
            graph[cur.x][cur.y] = 'W';
            for (const Pt dir : DIR)
            {
              Pt next = cur + dir;
              if (0 <= next.x && next.x < n && 0 <= next.y && next.y < m && (graph[next.x][next.y] == 'L' || graph[next.x][next.y] == 'C'))
                q.push(next);
            }
          }
        }
    cout << ans << "\n";
  }
}
