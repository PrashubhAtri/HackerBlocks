#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int C(int x,int y){
	if(x==y)return 1;
	if(y==0) return 1;
	if(y==1) return (long long int)x;
	long long int ans=1;
	if(y>x-y)y=x-y;
	for(int i=0;i<y;i++){
		ans=ans*(x-i)/(i+1);
	}
	return ans;
}
int main() {
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		cout<<C(n-1,k-1)<<endl;
	}
	return 0;
}

//
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// int main() {
//   int t;
//   cin >> t;
//   ll a , k , ans = 1;
//   while(t--)
//   {
//     cin >> a >> k;
//     if((a-k) > 0)
//     {
//       for(ll i = a-1 ; i >= a-k+1 ; i--){
//         ans = ans * i;
//         ans = ans/(a-i);
//       }
//       cout <<ans <<"\n";
//     }
//     else
//       cout << 1 << "\n";
//     ans = 1;
//   }
// 	return 0;
// }

