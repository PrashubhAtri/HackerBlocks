#include<bits/stdc++.h>
using namespace std;
int main()
{
      int t;
      cin>>t;
     long long int n;
	long long int a[10000005];

      while(t--)
      {
      cin>>n;
      for(int i=0;i<n;i++)
      cin>>a[i];
      long long int s=0,c=0;
      long long int prefixsum[10000005]={0};
      for(int i=0;i<n;i++)
      {
            s += a[i];
            s = s%n;
            s = (s+n)%n;
            prefixsum[s]++;
            
      }
      long long int ans=(prefixsum[0]*(prefixsum[0]+1))/2;
      for(long long int i=1;i<n;i++)
  {
     ans=ans+(prefixsum[i]*(prefixsum[i]-1))/2;
  }
      cout<<ans;
      cout<<endl;
      }
}