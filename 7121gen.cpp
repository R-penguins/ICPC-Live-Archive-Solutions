#include <bits/stdc++.h>
using namespace std;
int main()
{
  default_random_engine e(time(0));
  uniform_int_distribution<int> nGen(1, 10);
  uniform_int_distribution<int> numGen(-5, 5);
  for (int i = 0; i < 20; ++i)
  {
    int n = nGen(e);
    cout << n << "\n";
    while (n--)
    {
      for (int k = 0; k < 4; ++k)
        cout << numGen(e) << " ";
      cout << "\n";
    }
  }
  cout << "0\n";
}

