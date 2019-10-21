/**
 * Ping!
 * 2013 Mid-Atlantic
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  string str;
  while ((cin >> str) && str != "0")
  {
    bool first = true;
    for (int i = 1; i < str.size(); ++i)
      if (str[i] == '1')
      {
        if (first)
          first = false;
        else
          cout << " ";
        cout << i;
        for (int j = i; j < str.size(); j += i)
          str[j] = str[j] == '0' ? '1' : '0';
      }
    cout << "\n";
  }
}
