#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
bool isPrime(ll n){
    if(n<2)
    return false;
    if(n==2||n==3)
    return true;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)
        return false;
    }
    return true;   
}
ll sum_of_digits(ll n){
    ll sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
bool Is_Boston(ll n){
    int arr[1000000];
    int k=0;
    ll ans=0;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
           arr[k++]=i; 
           arr[k++]=n/i;
        }
    }    
    for(int i=0;i<k;i++){
        if(isPrime(arr[i])){
            int a=arr[i];
            while(n%a==0){
                ans+=sum_of_digits(arr[i]);
                a=a*arr[i];
            }
        }
    }
    if(sum_of_digits(n)==ans) return true;
    return false;
}

int main() {
    cin>>n;
    cout<<Is_Boston(n)<<endl;
	return 0;
}''