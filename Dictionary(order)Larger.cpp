#include <iostream>
#include<string.h>
#include<set>
#include<iterator>

using namespace std;

 char temp[1000];

 set<string>s;

void permute(string in, int i)
{
    if(in[i]=='\0')
    {
       // cout<<in<<endl;

         s.insert(in); //THIS IS NOT WORKING FINE

        return;
    }

    for(int j=i;in[j]!='\0';j++)
    {
       swap(in[i],in[j]);
       permute(in,i+1);
       swap(in[i],in[j]);
    }


}


int main()
{
   string in;
   cin>>in;

   string temp;

   temp=in;


   permute(in,0);

   set<string> :: iterator itr;


   for(itr=s.begin();itr!=s.end();itr++)
   {
     if(*itr>temp)
     {
         cout<<*itr<<endl;
     }
   }

    return 0;
}
