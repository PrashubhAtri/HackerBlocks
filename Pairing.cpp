#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define pii pair<long long,long long>
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define PI 3.14159265
#define ll int
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define INF 1000000009
#define mod 1000000007
vector <ll> graph[100045];
ll prefixsum[200005];
bool vis[200005];
ll temp;
vector <ll> cnt;
void dfs(ll u)
{
	//cout<<u<<endl;
	if(vis[u])
		return;
	vis[u] = true;
	ll sz = graph[u].size();
	F(i,0,sz-1)
	{
		ll v = graph[u][i];
		if(!vis[v])
		{
			temp++;
			dfs(v);
		}
	}
	return;
}
int main() 
{
	std::ios::sync_with_stdio(false);
	ll n,m,u,v;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		graph[u].pb(v);
		graph[v].pb(u);
	}
	long long ans = 1;
	memset(vis,false,sizeof(vis));
	F(i,0,n-1)
	{
		temp = 1;
		if(!vis[i])
		{
			dfs(i);
			cnt.pb(temp);
		}
	}
	ll sz = cnt.size();
	ans = 0;
	prefixsum[0] = cnt[0];
	F(i,1,sz-1)
	{
		prefixsum[i] = prefixsum[i-1] + cnt[i];
	}
	F(i,0,sz-1)
	{
		ans = ans + (prefixsum[sz-1]-prefixsum[i])*cnt[i];
	}
	printf("%lld\n",ans);
	return 0;
}