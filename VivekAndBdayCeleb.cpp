#include<bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename T>
class graph{
	public:
	map<T,list<T>> adj;
	void addedge(T u,T v,bool bidir=true){
		adj[u].push_back(v);
		if(bidir==true)
			adj[v].push_back(u);
	}
    void print(){
		for(auto i:adj){
			cout<<i.first<<"  ->  ";
			for(auto x: i.second){
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
	graph trans(int n){
        graph<int> g;
        for(int i=1;i<=n;i++){
            for(auto j : adj[i]){
                g.addedge(j,i,false);
            }
        }
        return g;
    }
    void dfshelp1(int u,map<T,bool> &visited,list<int>&l){
        visited[u]=true;
        for(auto v : adj[u]){
            if(visited[v]==false)
                dfshelp1(v,visited,l);
        }
        l.push_front(u);
    }
    void dfs(int u,vector<int> &vec,map<T,bool> &visited){
        visited[u]=true;
        vec.push_back(u);
        for(auto v : adj[u]){
            if(visited[v]==false)
                dfs(v,vec,visited);
        }

    }
    void dfshelp2(int u,int &count,map<T,bool> &visited){
        visited[u]=true;
        count++;
        for(auto v : adj[u]){
            if(visited[v]==false)
                dfshelp2(v,count,visited);
        }
    }
    void solution(int n){
        map<T,bool>visited;
        list<int>l;
        vector<int>v;
        map<pair<int,int>,vector<int>>m;
        int i;
        for(i=1;i<=n;i++){
            if(visited[i]==false)
                dfshelp1(i,visited,l);
        }
        graph g1=trans(n);
        visited.clear();
        int count=0;
        for(auto x : l){
            if(visited[x]==false){
                g1.dfs(x,v,visited);
                pair<int,int>p;
                p.first=v.size();
                p.second=count;
                m.insert(make_pair(p,v));
                count++;
                v.clear();
            }
        }
        for(auto &it : m){
            count=0;
            visited.clear();
            dfshelp2(  *((it.second).begin()) ,count ,visited );
            //cout<<(it.first).first;
            if(count == (it.first).first)
                break;
        }
        cout<<count;
    }
};
int main(){
	graph<int> g;
    int i,m,n,u,v;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>u>>v;
        g.addedge(u,v,false);
    }
    g.solution(n);
}