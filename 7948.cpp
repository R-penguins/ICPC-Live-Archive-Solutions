/*
 * Periodic Strings
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  string str;
  while (cin >> str)
  {
    int ans = str.size();
    for (int i = 0; i < str.size() - 1; ++i)
      if (str[i] == str[i + 1] && str.size() % (i + 1) == 0)
      {
        bool ok = true;
        for (int j = 0; j < str.size() - i - 1; j += i + 1)
          if (!(str[j + i] == str[j + i + 1] && equal(str.begin() + j, str.begin() + j + i, str.begin() + j + i + 2)))
          {
            ok = false;
            break;
          }
        if (ok)
        {
          ans = i + 1;
          break;
        }
      }
    cout << ans << "\n";
  }
}
