// #include <bits/stdc++.h>
// using namespace std;

// int query(vector<int> *tree,int ss,int se,int qs,int qe,int index,int k){
//     ///Complete Overlap
//     if(ss>=qs and se<=qe)    return (tree[index].size() - (lower_bound(tree[index].begin(),tree[index].end(),k) - tree[index].begin()));
//     //No Overlap
//     if(qe<ss or qs>se)  return 0;    
//     //Partial Overlap 
//     int mid = (ss+se)/2;
//     int leftAns = query(tree,ss,mid,qs,qe,2*index,k);
//     int rightAns  = query(tree,mid+1,se,qs,qe,2*index+1,k);
//     return leftAns+rightAns ;   
// }

// vector<int> Mymerge(vector<int> a,vector<int> b){
//     int it1=0,it2=0;vector<int> ans;
//     while(it1<a.size() or it2<b.size()){
//         if(a[it1]<=b[it2]) ans.push_back(a[it1++]);
//         else ans.push_back(b[it2++]);
//     }
//     if(it1==a.size() and it2<b.size()){
//         while(it2<b.size()){ans.push_back(b[it2++]);}
//     }if(it1<a.size() and it2==b.size()){
//         while(it1<a.size()){ans.push_back(a[it1++]);}
//     }
//     return ans;
// }

// void buildTree(int *a,int s,int e,vector<int> *tree,int index){
//     if(s==e){
//         tree[index].push_back(a[s]);
//         return ;
//     }
//     int mid = (s+e)/2;
//     buildTree(a,s,mid,tree,2*index);
//     buildTree(a,mid+1,e,tree,2*index+1);
//     tree[index] = Mymerge(tree[2*index],tree[2*index+1]);
//     return;
// }

// void display(vector<int> v){
//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     }return;
// }

// int main() {
//     int n,q,l,r,k,i=0;
//     cin>>n;
//     int a[n];
//     for(i;i<n;i++){cin>>a[i];}
//     vector<int> tree[4*n+1];
//     buildTree(a,0,n-1,tree,1);
//     // // Printing The Tree
//     // for(int i=1;i<=9;i++){
//     //    display(tree[i]);cout<<endl;
//     // }
//     // cout<<"^^^^^^^^^^^^^^^^^^^^^^"<<endl;
//     cin>>q;while(q--){
//         cin>>l>>r>>k;
//         cout<<query(tree,0,n-1,l,r,1,k)<<endl;
//     }
//     return 0;
// }

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
//#define int long long int
#define N 200005
int ar[N];
vec(int) tree[2*N+4];
int n,a,b,k,mod;
vec(int) v;


void build(int s,int e,int index)
{
    if(s==e)
    {
        tree[index]=vec(int) (1,ar[s]);
    }
    else
    {
        int mid=(s+e)/2;
        build(s,mid,2*index);
        build(mid+1,e,2*index+1);
        merge(tree[2*index].begin(),tree[2*index].end(),tree[2*index+1].begin(),tree[2*index+1].end(),back_inserter(tree[index]));

    }    
}

int query(int s,int e,int qs,int qe,int index,int x)
{
    if(qs>qe) return 0;
    if(s==qs && e==qe)
    {
        auto pos = lower_bound(begin(tree[index]),end(tree[index]),x);
        if(pos!=tree[index].end())
            return tree[index].size()-(pos-begin(tree[index]));
        return 0;
    }

    int mid=(s+e)/2;
    
    return query(s,mid,qs,min(qe,mid),2*index,x)+ query(mid+1,e,max(qs,mid+1),qe,2*index+1,x);
}

int32_t main()
{
    fast();

    int t=1;    //change t if required
    //cin>>t;
    //int tt=1;
    while(t--)

    {
        //cout<<"working";
        cin>>n;
        take(ar,n);
        build(0,n-1,1);

        int pp;
        cin>>pp;
        while(pp--)
        {
            int l,r,k;
            cin>>l>>r>>k;
            cout<<query(0,n-1,l-1,r-1,1,k)<<endl;
        }
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