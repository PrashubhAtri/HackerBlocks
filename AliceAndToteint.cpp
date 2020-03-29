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


using namespace std;

void sieve(vi &prime)       //MIN SIEVE
{
    lli i,j;
    FOI(i,2,1000000)
    {
        if(prime[i]==1)
        {
            for(j=2*i;j<=1000000;j=j+i)
            {
                if(prime[j]==1)
                {
                    prime[j]=i;
                }
            }
            prime[i]=i;
        }
    }
}
int main()
{   vector<lli> prime(1000001,1);
    lli t;
    cin>>t;
    sieve(prime);
    while(t--)
    {
        lli n;
        cin>>n;
        lli ans=n;
        lli i=n;
        set<lli> s;
        while(prime[i]!=1)
        { 
            s.insert(prime[i]); //SET STORE ALL DISTINCT PRIME NUMBERS
            i=i/prime[i];
        }
        set<lli>::iterator it;
        for(it=s.begin();it!=s.end();it++)
        {   lli k=*it;
            //cout<<k<<" ";
            ans=ans-ans/k;  //USING FORMULA OF TOTIENT
        }
        //cout<<"\n";
        
            cout<<ans<<"\n";
    }
}