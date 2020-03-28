#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q,x,i,l,r;
	cin>>n>>q;
	vector<int> v;
	v.push_back(0);
	for(i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	for(i=0;i<q;i++){
		cin>>x;
		if(x==1){
			cin>>l>>r;
			int Min=INT_MAX;
			for(int j=l;j<=r;j++){
				Min=min(Min,v[j]);
			}
			cout<<Min<<endl;
		}else if(x==2){
			cin>>l>>r;
			v[l]=r;
		}
	}
	return 0;
}