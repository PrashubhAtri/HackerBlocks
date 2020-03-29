#include<bits/stdc++.h>
using namespace std;

int LIS(int ar[],int n)
{
    
    int DP[n+1],temp=1;
    for(int i=0;i<n;i++)
    {
        DP[i]=1;
        for(int j=i-1;j>=0;j--)
            if(ar[i]>ar[j])
                DP[i]=max(DP[i],DP[j]+1);
        temp=max(temp,DP[i]);
    }

    return temp;
}

int main()
{
int n;
cin>>n;
int ar[n];
for(int i=0;i<n;i++)
    cin>>ar[i];
cout<<LIS(ar,n);
return 0;
}
