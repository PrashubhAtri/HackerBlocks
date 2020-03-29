#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll k[100005],n;

ll merge(ll *a, ll si, ll ei) 
{
     if (si >= ei)
          return 0;

     ll count = 0;
     ll mi = (si + ei) / 2;

     count = count + merge(a, si, mi) + merge(a, mi + 1, ei);

     ll i = si, j = mi+1;
     ll d = si;

     while (i <= mi && j <=ei) 
     {
          if (a[i] <= a[j]) 
          {
               k[d++] = a[i++];
          }
          else {
               k[d++] = a[j++];
               count = count + (mi - i+1);
          }
     }

     while (i <= mi) 
     {
          k[d++] = a[i++];
     }

     while (j <= ei) 
     {
          k[d++] = a[j++];
     }

     for (int i = si; i <= ei; i++)  a[i] = k[i];

     return count;
}
int main() {
 #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 freopen("debug.txt", "w", stderr);
 #endif
     int t;
     cin >> t;
     while (t--) 
     {
          cin >> n;
          ll a[n];
          for (ll i = 0; i < n; i++) 
          {
               cin >> a[i];
          }
          cout << merge(a, 0, n - 1) << "\n";
     }
}