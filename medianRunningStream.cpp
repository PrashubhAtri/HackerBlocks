#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,sum,i,num,avg;
    cin>>t;
    while(t--){
		cin>>n;
        sum=0;
		for(i=1;i<=n;i++){
			cin>>num;
            sum+=num;
            avg=sum/i;
			cout<<avg<<" ";
		}
		cout<<endl;
	}
	return 0;
}
