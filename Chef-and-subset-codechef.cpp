// Question link : https://www.codechef.com/problems/CHEFSETC
// Question based on bit masking
// Complexity is (2^N)*N

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    vector<int> arr(4);
    for (int i = 0; i < 4; i++)
    {
      cin >> arr[i];
    }
    bool flag = false;
    int total = 1 << 4;
    for (int mask = 1; mask < total; mask++)
    {
      int sum = 0;

      for (int i = 0; i < 4; i++)
      {
        int f = 1 << i;
        if ((mask & f) != 0)
        {
          sum += arr[i];
        }
      }
      if (sum == 0)
      {
        flag = true;
        break;
      }
    }
    if (flag)
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
  return 0;
}