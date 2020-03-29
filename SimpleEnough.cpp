#include <bits/stdc++.h>

using namespace std;
#include <iomanip>  
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define SZ(x) ((int)(x.size()))
#define FOI(i, a, n) for( i = int(a); i <= int(n); i++)
#define FOD(i, a, n) for( i = int(a); i >= int(n); i--)
#define IN(x, y) ((y).find(x) != (y).end())
#define ALL(t) t.begin(),t.end()
#define MSET(tabl,i) memset(tabl, i, sizeof(tabl))
#define PSET(x,y) fixed<<setprecision(y)<<lf(x)
#define DBG(c) cout << #c << " = " << c << endl;
#define RTIME ((double)clock()/(double)CLOCKS_PER_SEC)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Mod 1000000007

typedef long long int ll;
typedef long long int lli;
typedef long double lf;
typedef pair < ll, ll > pii;
typedef pair < ll, ll > pll;
typedef vector < ll > vi;
typedef vector<vi> vvi;
typedef complex<double> base;


const int N = 1e5 + 5;
const int lgN = 1e6+5;
const int te = 3e8+1;
const lli MOD = 998244353;
const lf pi = 3.141592653589793238462643383;
const ll IMAX = INT_MAX; 
const double PI = 3.141592653589793;

template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>; 


ll x,y;
template<class T> T gcd(T a,T b){ if(a==0) {x=0,y=1; return b;}T gc=gcd(b%a,a);T temp;temp=x;x=y-(b/a)*temp;y=temp;return gc;}

//(a^x)%m
ll po(ll a, ll x,ll m){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; } 
map<pair<lli,lli> ,lli> m;

lli c1=0;
lli func(lli n)
{
    if(n==1)
        return 1;

    if(n==0)
        return 1;
    lli x=func(n/2);
    if(n%2==0)
    {
        x=2*x+1;
    }
    else
    {
        x=2*x+1;
    }
    return x;
}
lli l,r;
void func2(lli n,lli left,lli right)
{

    if(n==1)
    {
        c1++;
        return ;
    }
    if(n==0)
    {
        return ;
    }
    lli x=(right-left)/2;
    if(!((l>left+x-1)||(r<left)))
    {
        func2(n/2,left,left+x-1);
    }
    if(!((l>right)||(r<left+x+1)))
    {
        func2(n/2,left+x+1,right);
    }
    if(((left+x)>=l)&&(left+x<=r)&&(n%2==1))
    {
        c1++;
    }
}
int main()
{
    lli n;
    cin>>n;
    lli x=func(n);
    //cout<<x;
    cin>>l>>r;
    func2(n,1,x);
    cout<<c1;

}