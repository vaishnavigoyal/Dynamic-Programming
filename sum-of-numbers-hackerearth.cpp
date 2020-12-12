// Question link : https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/sum-of-numbers-9/description/
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int p;
    cin >> p;
    bool flag = false;
    int total = 1 << n;
    for (int mask = 0; mask < total; mask++)
    {
      int sum = 0;

      for (int i = 0; i < n; i++)
      {
        int f = 1 << i;
        if ((mask & f) != 0)
        {
          sum += arr[i];
        }
      }
      if (sum == p)
      {
        flag = true;
        break;
      }
    }
    if (flag)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}