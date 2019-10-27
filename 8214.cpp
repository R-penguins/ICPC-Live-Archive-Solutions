/**
 * Purple rain
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  string line;
  while (cin >> line)
  {
    int ma = -1, mi = 1;
    int cur = 0, curMaBeg = 0, curMaEnd, curMiBeg = 0, curMiEnd;
    int maAns, maAnsEnd;
    int miAns, miAnsEnd;
    int curMin = 0;
    for (int i = 0; i < line.size(); ++i)
    {
      cur += line[i] == 'B' ? 1 : -1;
      curMaEnd = i;
      if (cur < 0)
      {
        cur = 0;
        curMaBeg = i + 1;
      }
      else if (cur > ma)
      {
        ma = cur;
        maAns = curMaBeg;
        maAnsEnd = curMaEnd;
      }

      curMin += line[i] == 'B' ? 1 : -1;
      curMiEnd = i;
      if (curMin > 0)
      {
        curMin = 0;
        curMiBeg = i + 1;
      }
      else if (curMin < mi)
      {
        mi = curMin;
        miAns = curMiBeg;
        miAnsEnd = curMiEnd;
      }
    }
    if (ma > -mi || (ma == -mi && (maAns < miAns || (maAns == miAns && maAnsEnd < miAnsEnd))))
      cout << maAns + 1 << " " << maAnsEnd + 1 << "\n";
    else
      cout << miAns + 1 << " " << miAnsEnd + 1 << "\n";
  }
}
