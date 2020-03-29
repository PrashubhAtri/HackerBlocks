#include<bits/stdc++.h>
#define N 1000001
using namespace std;

int prime[N];

void primeA(){
    fill(prime,prime+N,1);
    for(int i=2;i*i<=N;i++){
        if(prime[i])
        for(int j=2*i;j<N;j+=i){
            prime[j]=0;
        }
    }
    
}



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        primeA();
        
        map<int,int> m;
        for(int i=0;i<n;i++){
            for(int j=2;j<=a[i];j++){
                if(a[i]%j==0){
                    int x=j;
                    if(prime[j]){
                        while(a[i]%x==0){
                            m[j]++;
                            x=x*j;
                        }
                    }
                    
                }
            }
        }
        int ans=1;
        for(auto it : m){
            ans*=(it.second+1);
        }
        cout<<ans<<endl;
    }
	return 0;
}