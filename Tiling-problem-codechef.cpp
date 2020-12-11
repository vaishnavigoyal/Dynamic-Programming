// Question link : https://www.codechef.com/problems/JAM11
// Question based on DP and similar to fibonacci series
// but due to large I/P we have used matrix exponentiation

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll arr[2][2], I[2][2];

void mul(ll a[][2], ll b[][2])
{
  ll res[2][2];
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      res[i][j] = 0;
      for (int k = 0; k < 2; k++)
      {
        res[i][j] += ((a[i][k] % 1000000007) * (b[k][j] % 1000000007)) % 1000000007;
      }
    }
  }
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      a[i][j] = res[i][j];
    }
  }
}

void power(ll a[][2], ll n)
{
  I[0][0] = 1;
  I[1][1] = 1;
  I[0][1] = 0;
  I[1][0] = 0;

  while (n)
  {
    if (n % 2 == 1)
    {
      mul(I, a);
      n--;
    }
    else
    {
      mul(a, a);
      n /= 2;
    }
  }
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      a[i][j] = I[i][j];
    }
  }
}

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
    else
    {
      arr[0][0] = 0;
      arr[1][1] = 1;
      arr[1][0] = 1;
      arr[0][1] = 1;
      power(arr, n - 1);
      ll x = (arr[0][0] + (2 * arr[1][0]) % 1000000007) % 1000000007;
      cout << x << endl;
    }
  }
  return 0;
}