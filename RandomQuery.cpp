#include <bits/stdc++.h>
using namespace std;
 
#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define print_upto(a,n)        for(int i=0;i<n;i++)    cout<<a[i]<<" "; cout<<endl
#define take(x,n)           for(int i=0;i<n;i++)  cin>>x[i];
 
void fast();
 
#define ll long long
#define ull unsigned long long
#define ldob long double
#define dob double
#define F first
#define S second
#define pii pair<int, int>
#define vec(a) vector<a>
#define umap(a, b) unordered_map<a, b>
#define endl "\n"
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define int long long int
#define N 1000001
int ar[N];
int n,a,b,mod;
vec(int) v;
 
 
int32_t main()
{
    fast();
 
    int t=1;    //change t if required
    //cin>>t;
    while(t--)
    {
        cin>>n;
        take(ar,n);
        map<int,int>m;
        int dp[n];
        dp[0]=1 ;
        m[ar[0]]=1;
        double ans=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+(i+1-m[ar[i]]);
            m[ar[i]]=i+1;
            ans+=dp[i];
        }
     
        cout<<fixed<<setprecision(6)<<(double)(((ans*2*1.0)-n)/(n*n*1.0));
    }
 
    return 0;
}
 
void fast()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}