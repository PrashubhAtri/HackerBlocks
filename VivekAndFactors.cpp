#include <bits/stdc++.h>
using namespace std;

long long expo(long long X,long long N)
{
    if(N==0)
        return 1;
    if(N%2==0)
        return expo(X*X,N/2);
    return X*expo(X,N-1);
}
int main()
{
    int minprime[100001]={0};
    minprime[1]=1;
    for(int i=2;i*i<=100000;i++)
        if(!minprime[i])
            for(int j=i*i;j<=100000;j+=i)
                if(!minprime[j])
                    minprime[j]=i;
                    
    unordered_map<int,int> M;
    M[1]=1;
    for(int i=2;i<=100000;i++)
        if(!minprime[i])
            minprime[i]=i;
    
    for(int i=2;i<=100000;i++)
    {
        int num=i;
        unordered_map<int,int> h;
        while(num!=1)
        {
            h[minprime[num]]++;
            num/=minprime[num];
        }
        long long ans=1;
        for(auto it=h.begin();it!=h.end();it++)
        {
            long long A=it->first;
            long long N=it->second;
            ans=ans*(expo(A,N+1)-1)/(A-1);
        }
       
        M[ans]=i;
    }
    int num;
    cin>>num;
    while(num!=0)
    {
        auto it=M.find(num);
        if(it==M.end())
            cout<<-1<<endl;
        else
            cout<<it->second<<endl;
        cin>>num;
    }
}