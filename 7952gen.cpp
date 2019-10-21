#include <bits/stdc++.h>
using namespace std;
int main()
{
    default_random_engine e(time(0));
    uniform_int_distribution<int> nGen(1, 2000);
    uniform_int_distribution<long long> numGen(10000000000000000, 1000000000000000000);
    for (int i = 0; i < 100; ++i)
    {
        int n = nGen(e);
        cout << n << "\n";
        while (n--)
        {
            long long x1 = numGen(e);
            uniform_int_distribution<long long> numGen2(x1, 1000000000000000000);
            cout << x1 << " " << numGen2(e) << "\n";
        }
    }
}