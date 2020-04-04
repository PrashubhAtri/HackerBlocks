#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long
#define MOD 1000000007

vector<vector<ll> > multiply(vector<vector<ll> > A, vector<vector<ll> > B){
    vector<vector<ll> > C(2,vector<ll>(2));

    for(int i=0; i<=1; i++){
        for(int j = 0; j<=1; j++){
            for(int x = 0; x<=1; x++){
                C[i][j] = (C[i][j] + A[i][x]*B[x][j]%MOD)%MOD;
            }
        }
    }
    return C;
}

vector<vector<ll> > pow(vector<vector<ll> > A, ll p){
    //base
    if(p==1){
        return A;
    }
    //recu
    if(p&1){
        return multiply(A, pow(A,p-1));
    }
    else{
        vector<vector <ll> > X = pow(A,p/2);
        return multiply(X,X);
    }

} 

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<ll> > T{{0,1}, {1,1}};
    vector<vector<ll> > F1{{1}, {1}};
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<ll> > A = multiply(pow(T,n-1),F1);
        cout<<A[0][0]<<endl;
    }
}