#include<bits/stdc++.h>
#define M 1000000007
using namespace std;

int solveCoins(int n,int m,int s[]){
    
    if(n<0)
    return 0;
    if(n==0)
    return 1;
    if(m<=0&&n>=1)
    return 0;
    
    return solveCoins(n,m-1,s)+solveCoins(n-s[m-1],m,s);
}

int solveCoinsDP(int n,int m,int s[]){
    
    int dp[n+1][m+1]{0};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                
                dp[i][j]=1;
            }
            else if(i>=1&&j<=0)
            dp[i][j]=0;
            
            else{
                if(i>=s[j-1])
                dp[i][j]=(dp[i-s[j-1]][j]+dp[i][j-1])%M;
                else
                dp[i][j]=dp[i][j-1]%M;
            }
        }
    }
    return dp[n][m];
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
    cin>>m;
    int s[m];
    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    cin>>n;
    cout<<solveCoinsDP(n,m,s)<<endl;
    }
    
	return 0;
}