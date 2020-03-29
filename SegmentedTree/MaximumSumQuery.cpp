#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10000007];
struct Tree{
   ll prefixsum;
   ll suffixsum;
   ll total;
   ll best;
};
Tree tree[500005];
void build_segment_tree(ll index , ll s  , ll e){
    //leaf node
    if(s == e){
        tree[index].prefixsum = a[s];
        tree[index].suffixsum = a[s];
        tree[index].total = a[s];
        tree[index].best = a[s];
        return ;
    }
    ll mid = (s+e)/2;
    build_segment_tree(2*index , s  ,mid);
    build_segment_tree(2*index+1, mid+1  ,e);

    tree[index].prefixsum = max(tree[2*index].prefixsum , (tree[2*index].total + tree[2*index+1].prefixsum));
    tree[index].suffixsum = max(tree[2*index+1].suffixsum , (tree[2*index+1].total + tree[2*index].suffixsum));
    tree[index].total = tree[2*index].total + tree[2*index+1].total;
    tree[index].best = max((tree[2*index].suffixsum + tree[2*index+1].prefixsum) , max(tree[2*index].best , tree[2*index+1].best));
    return ;
    
}

Tree query(ll index , ll s , ll e , ll qs , ll qe){
    Tree t;
    //no overlap
    if(s>qe || e<qs){
        t.prefixsum = INT_MIN;
        t.suffixsum = INT_MIN;
        t.total = 0;
        t.best = INT_MIN;
        return t;
    }
    //complete overlap
    if(s>=qs && e<=qe ){
        return tree[index];
    }

    //partial overlap
    ll mid = (s+e)/2;
    Tree q1 = query(2*index , s , mid , qs , qe);
    Tree q2 = query(2*index+1 , mid+1 , e , qs , qe);
    
    t.prefixsum = max(q1.prefixsum , q1.total + q2.prefixsum);
    t.suffixsum = max(q2.suffixsum , q2.total + q1.suffixsum);
    t.total = q1.total + q2.total;
    t.best = max(q1.suffixsum + q2.prefixsum , max(q1.best ,q2.best));

    return t;

}
int main() {
   ll n , q;
   cin>>n;
   for(int i=1; i<=n ;i++){
       cin>>a[i];
   }
   build_segment_tree(1 , 1 , n);
   cin>>q;
   while(q--){
       ll l , r;
       cin>>l>>r;
       cout<<query(1 , 1 , n , l ,r).best<<endl;
   }
  return 0;
}
