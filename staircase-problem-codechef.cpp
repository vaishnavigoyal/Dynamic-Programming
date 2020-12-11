// Question link : https://www.codechef.com/problems/JAM11
// Question based on DP

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
    ll n;
    cin >> n;
    if (n == 1)
    {
      cout << 1 << endl;
    }
    else if (n == 2)
    {
      cout << 2 << endl;
    }
    else if (n == 3)
    {
      cout << 4 << endl;
    }
    else
    {
      vector<ll> arr(n);
      arr[0] = 1;
      arr[1] = 2;
      arr[2] = 4;
      for (int i = 3; i < n; i++)
      {
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % 1000000007;
      }
      cout << arr[n - 1] << endl;
    }
  }
  return 0;
}
