/**
 * Talking About Numbers
 * 2015 Mid-Atlantic
 */
#include <bits/stdc++.h>
using namespace std;
string make(int n)
{
  static const vector<string> R {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  static const vector<string> T {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  string ans = "";
  if (n / 100)
  {
    ans += R[n / 100] + " hundred";
    n %= 100;
  }
  if (n)
  {
    if (ans != "")
      ans += " and ";
    if (n < 20)
      ans += R[n];
    else
    {
      ans += T[n / 10];
      if (n %= 10)
        ans += ("-" + R[n]);
    }
  }
  return ans;
}
int main()
{
  int n;
  while ((cin >> n) && n > -1)
  {
    if (n == 0)
    {
      cout << "zero\n";
      continue;
    }
    string ans = "";
    if (n >= 1000000)
    {
      ans += make(n / 1000000) + " million";
      n %= 1000000;
    }
    if (n >= 1000)
    {
      if (ans != "")
        ans += ", ";
      ans += make(n / 1000) + " thousand";
      n %= 1000;
    }
    if (n)
    {
      if (ans != "")
        if (n / 100)
          ans += ", ";
        else
          ans += " and ";
      ans += make(n);
    }
    cout << ans << "\n";
  }
}
