#include <bits/stdc++.h>
using namespace std;
int main()
{
  default_random_engine e(time(0));
  uniform_int_distribution<int> nGen(0, 80);
  uniform_int_distribution<char> charGen(32, 126);
  uniform_int_distribution<char> pureGen(60, 90);
  for (int i = 0; i < 50; ++i)
  {
    int n = nGen(e);
    for (int j = 0; j < n; ++j)
    {
      char c = charGen(e);
      if (c < 55)
        c = ' ';
      cout << c;
    }
    cout << "\n";
  }
  for (int i = 0; i < 50; ++i)
  {
    int n = nGen(e);
    for (int j = 0; j < n; ++j)
    {
      char c = pureGen(e);
      if (c < 60)
        c = ' ';
      cout << c;
    }
    cout << "\n";
  }
}

