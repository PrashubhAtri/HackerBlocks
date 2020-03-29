#include <bits/stdc++.h>
using namespace std;

#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define print_upto(a,n)        for(int i=0;i<n;i++)    cout<<a[i]<<" "; cout<<endl
#define take(x,n)           for(int i=0;i<n;i++)  cin>>x[i];

#define ll long long
#define ull unsigned long long
#define ldob long double
#define dob double
#define F first
#define S second
#define pii pair<int, int>
#define vec(a) vector<a>
#define umap(a, b) unordered_map<a, b>
#define endl "\n"
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define int long long int
#define N 200005
int ar[N];
//int n,a,b,c;
int n;
vec(int) v;

int primes[N];
void fast()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void sieve()
{
    primes[2]=true;
    v.pb(2);
    for(int i=3;i<=n;i+=2)
        primes[i]=true;
    
    for(int i=3;i<=n;i+=2)
    {
        if(primes[i])
        {
            v.pb(i);
            for(int j=i*i;j<=n;j+=2*i)
                primes[j]=false;
        }
    }

}
int x,y,GCD;
void extended(int a,int b)
{
    if(b==0)
    {

        x=1;
        y=0;
        GCD=a;
        return ;
    }
    extended(b,a%b);
    int cx,cy;
    cx = y;
    cy=x-(a/b)*y;

    x=cx;
    y=cy;
    return;
}





string multiply(string a,string b)
{
    int l1=a.length();
    int l2=b.length();

    vec(int) temp(l1+l2);

    int p =-1;
    int pp=-1;
    for(int i=l1-1;i>=0;i--)
    {
        p++;
        pp=-1;
        int carry=0;
        for(int j=l2-1;j>=0;j--)
        {
            pp++;
            temp[p+pp] += (a[i]-'0')*(b[j]-'0')+carry;
            carry=temp[p+pp]/10;
            temp[p+pp]%=10;
            //print(temp);
        }
        temp[p+pp+1]+=carry;
    }
    

    int z=l1+l2-1;
    while(temp[z]==0) z--;

    string answer;
    while(z>=0)
        answer+=to_string(temp[z--]);

    return answer;

}

string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    //if (isSmaller(str1, str2)) 
      //  swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i=0; i<n2; i++) 
    { 
        // Do school mathematics, compute difference of 
        // current digits 
          
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
          
        // If subtraction is less then zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        // if the sub value is -ve, then make it positive 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
int32_t main()
{
    fast();

    int t=1;    //change t if required
    //cin>>t;   
    while(t--)
    {

        string a;
        cin>>a;
        
        string ans1=multiply(a,a);
        string ans2=ans1;
        ans2=multiply(ans2,"5");
        ans1=multiply(ans1,a);
        ans1=multiply(ans1,"4");
        string ans3 = multiply(a,"6");
        string ans4="14";
        string final = findSum(findDiff(findSum(ans1,ans2),ans3),ans4);
        cout<<final;
        
      
    }

    return 0;
}