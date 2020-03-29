#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
typedef set<int> setint;

map<string,int> mymap;
map<int,string> mymap2;
map<int,setint> result;
vector<int> vec;
map<int,setint>::iterator rit;
setint::iterator sit;

int main()
{
 
 	// #ifndef ONLINE_JUDGE
 	//     freopen("input.txt","r",stdin);   
 	//     freopen("output.txt","w",stdout);
 	// #endif 
 	
 string str,str2;
 int i,x,y,test,m,n;
 test=1;
 while(cin>>n)
 {
  mymap.clear();
  mymap2.clear();
  vec.clear();
  for(i=1;i<=n;i++)
  {
   cin>>str;
   mymap[str]=i;
   mymap2[i]=str;
   result[i].insert(0);
  }
  cin>>m;
  for(i=0;i<m;i++)
  {
   cin>>str>>str2;
   x=mymap[str2];
   y=mymap[str];
   result[x].insert(y);
  }
  while(result.size()!=0)
  {
   for(rit=result.begin();rit!=result.end();rit++)
   {
    if(rit->second.size()==1)
    {
     x=rit->first;
     result.erase(x);
     break;
    }
   }
   vec.push_back(x);
   for(rit=result.begin();rit!=result.end();rit++)
   {
    if(rit->second.size()>1)
    {
     sit=rit->second.find(x);
     if(sit!=rit->second.end())
     {
      rit->second.erase(x);
     }
    }
   }
  }
  cout<<"Case #"<<test++<<": Vivek should drink beverages in this order:";
  for(i=0;i<n;i++)
  {
   cout<<" "<<mymap2[vec[i]];
  }
  cout<<"."<<endl<<endl;
 }
    return 0;
}
