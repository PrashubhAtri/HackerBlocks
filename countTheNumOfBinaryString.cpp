#include<iostream>
#define ll long long 
using namespace std;
ll int count(ll int n){
	ll int a[n],b[n];
	a[0]=1,b[0]=1;
	for(int i=1;i<n;i++){
		a[i]=a[i-1]+b[i-1];
		b[i]=a[i-1];
	}
	return a[n-1]+b[n-1];
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	cout<<count(n)<<endl;
	}
	

}