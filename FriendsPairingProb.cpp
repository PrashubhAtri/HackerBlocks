#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define fr first
#define sc second
#define pb push_back
#define pop pop_back
#define int long long int
int dp[100];

int friendsPairing(int n)
{	
    if(n==1)
        return 1;
    if(n==2)
        return 2;

         
	if (dp[n] != -1) 
       	return dp[n]; 
  
    if (n > 2) 
        return dp[n] = (friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2)); 
    	
}




int32_t main()
{
	fast;
	int n;
	memset(dp, -1, sizeof(dp)); 
	test
	{
		cin>>n;
		cout<<friendsPairing(n)<<endl;
	}


	return 0;
}