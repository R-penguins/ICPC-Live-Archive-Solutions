#include <bits/stdc++.h>
using namespace std;
int main()
{
  array<long long, 4> arr;
  while ((cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]) && arr[0] >= 0 && arr[3] >= 0)
  {
    int pos = find(arr.begin(), arr.end(), -1) - arr.begin();
    switch (pos)
    {
      case 0:
        if (arr[3] - arr[2] == arr[2] - arr[1])
          arr[0] = arr[1] - (arr[2] - arr[1]);
        else if (arr[3] * arr[1] == arr[2] * arr[2])
          arr[0] = arr[1] * arr[1] / arr[2];
        break;
      case 1:
        if ((arr[2] - arr[0]) % 2 == 0 && arr[3] - arr[2] == (arr[2] - arr[0]) / 2)
          arr[1] = arr[0] + arr[3] - arr[2];
        else if (arr[3] * arr[3] * arr[0] == arr[2] * arr[2] * arr[2])
          arr[1] = arr[0] * arr[3] / arr[2];
        break;
      case 2:
        if ((arr[3] - arr[1]) % 2 == 0 && arr[1] - arr[0] == (arr[3] - arr[1]) / 2)
          arr[2] = arr[1] + arr[1] - arr[0];
        else if (arr[0] * arr[0] * arr[3] == arr[1] * arr[1] * arr[1])
          arr[2] = arr[1] * arr[1] / arr[0];
        break;
      case 3:
        if (arr[1] - arr[0] == arr[2] - arr[1])
          arr[3] = arr[2] + (arr[2] - arr[1]);
        else if (arr[2] * arr[0] == arr[1] * arr[1])
          arr[3] = arr[2] * arr[2] / arr[1];
        break;
    }
    if (0 >= arr[pos] || arr[pos] > 1000000)
      arr[pos] = -1;
    cout << arr[pos] << "\n";
  }
}
