#include<bits/stdc++.h>
using namespace std;
int main(){
    float num=365,den=365,p=1,n;
    int count=0;
    cin>>n;
    while(p>1-n){
        p=p*num/den;
        num--;
        count++;
        // cout<<"prob is "<<p<<" and num is "<<count<<'\n';
    }
    if(n==1){
        cout<<"366"<<endl;
    }else if(n==0){
        cout<<count+1<<endl;
    }else{
        cout<<count<<endl;
    }
    return 0;
}