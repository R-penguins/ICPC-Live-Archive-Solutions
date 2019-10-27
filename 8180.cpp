/**
 * Star Arrangements
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int s;
  while (cin >> s)
  {
    cout << s << ":\n";
    if (s < 3 || s > 1000000)
      continue;
    for (int x = 2; x <= s / 2 + 1; ++x)
      for (int y = x - 1; y <= x; ++y)
        if (s % (x + y) == 0 || s % (x + y) == x)
          cout << " " << x << "," << y << "\n";
  }
}
