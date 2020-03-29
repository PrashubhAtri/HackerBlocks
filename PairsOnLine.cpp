#include <bits/stdc++.h>
#include <map>
using namespace std;
int main(){
	map<int,int> mp;
	int n,m,c,y,ans=0;
	cin>>n>>m>>c;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(mp.count(arr[i])){mp[arr[i]]++;}
		else{mp.insert({arr[i],1});}
	}
	for(int i=0;i<n;i++){
		y = (m*arr[i]) + c;
		if(mp.count(y)) ans+=mp[y];
	}	
	cout<<ans<<endl;
	return 0;	
}