#include <bits/stdc++.h>
using namespace std;
int query(int n){
	int summODD=0,sumEVEN=0;
	for(int i=1;i<(n/2);i++){
		if(n%i==0){
			if(i&1) summODD+=i;
			else sumEVEN+=i;
		}
	}
	if(n&1) summODD+=n;
	else sumEVEN+=n;
	return sumEVEN - summODD;
}
int main(){
	int q;cin>>q;while(q--){
		int n;
		cin>>n;
		cout<<query(n)<<endl;
	}
	return 0;
}