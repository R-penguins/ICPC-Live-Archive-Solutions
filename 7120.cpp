#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n0, n1;
    while ((cin >> n0 >> n1) && n0 && n1)
    {
        if (n0 == n1)
        {
            cout << n0 << "\n";
            continue;
        }
        int b0 = log2(n0), b1 = log2(n1);
        if (b0 != b1)
        {
            cout << pow(2, b1) << "\n";
            continue;
        }
        int l = pow(2, b0), r = pow(2, b0 + 1), mid = l + (r - l) / 2;
        if (l == n0)
        {
            cout << n0 << "\n";
            continue;
        }
        while (mid < n0 || mid > n1)
        {
            if (mid < n0)
                l = mid;
            else
                r = mid;
            mid = l + (r - l) / 2;
        }
        cout << mid << "\n";
    }
}

