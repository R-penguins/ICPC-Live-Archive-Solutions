/**
 * Text Roll
 * 2013 Mid-Atlantic
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  while ((cin >> n) && n)
  {
    int ans = 0;
    string line;
    getline(cin, line);
    while (n--)
    {
      getline(cin, line);
      if (ans >= line.size())
        continue;
      bool done = false;
      for (int i = ans; i < line.size(); ++i)
        if (line[i] == ' ')
        {
          ans = i;
          done = true;
          break;
        }
      if (!done)
        ans = line.size();
    }
    cout << ans + 1 << "\n";
  }
}
