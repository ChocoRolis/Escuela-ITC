#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void permCR(string &s, string act,int r)
{
   if(act.size()==r)
   {
      cout<<act<<endl;
      return;
   }
   for(int i=0;i<s.size();i++) //Por cada letra
   {
      permCR(s,act+s[i],r);
   }
}

void combCR(string &s, string act,int pos, int r)
{
   if(act.size()==r)
   {
      cout<<act<<endl;
      return;
   }
   for(int i=pos;i<s.size();i++) //Por cada letra
   {
      combCR(s,act+s[i],i,r);
   }
}

void combSR(string &s, string act,int pos, int r)
{
   if(act.size()==r)
   {
      cout<<act<<endl;
      return;
   }
   for(int i=pos;i<s.size();i++) //Por cada letra
   {
      combSR(s,act+s[i],i+1,r);
   }
}


void permSR(string &s, string act,int pos, int r)
{
   if(act.size()==r)
   {

      do{
         cout<<act<<endl;
      }while(next_permutation(act.begin(),act.end()));
      return;
   }
   for(int i=pos;i<s.size();i++) //Por cada letra
   {
      permSR(s,act+s[i],i+1,r);
   }
}


int main ()
{
   string s="1234";
   //permCR(s,"",3);
   //combCR(s,"",0,3);
   //combSR(s,"",0,2);
   permSR(s,"",0,2);

   /*
   sort(s.begin(),s.end());
   do{
      cout<<s<<endl;
   }while(next_permutation(s.begin(),s.end()));
   */
}
