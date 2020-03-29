#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,temp,ans=-2;
	cin>>n;
	temp = pow(2,n+1);
	ans+=temp;
	cout<<ans<<endl;
	return 0;
}