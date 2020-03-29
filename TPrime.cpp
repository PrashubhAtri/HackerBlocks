
#include<iostream>
using namespace std;
#include <cmath>
# define ll long long
#define int long long int
int32_t main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int rootceil =ceil(sqrt(x));
        int rootfloor =floor(sqrt(x));
        if(x==4)
        {
            cout<<"YES"<<endl;
            continue;
        }
        // TO check if the number is a perfect square or not
        if(rootceil != rootfloor)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if((x&1)==0 || x<=3)
        {
            cout<<"NO"<<endl;
            continue;
        }
       
        // Calculate the root and then check if it is prime or not
        int count=0;
        for(int j=3;j*j<=rootceil;j+=2)
        {
            if(rootceil % j==0)
            {
                count++;
                break;
            }
        }
        if (count)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}