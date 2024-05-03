#include <bits/stdc++.h>
using namespace std;

map<string,int> M;

int pal(string &s)
{
	string r=s;
	reverse(r.begin(),r.end());
   	if(r==s)
      	return 1;
   	if(M.find(s)!=M.end())
   	{
      		return M[s];
   	}
   	int mp=99999;
   	for(int i=1;i<s.length();i++)
   	{
      		string ls= s.substr(0,i);
      		string rs= s.substr(i);
      		int p=pal(ls)+pal(rs);
      		mp =min(mp,p);
   	}
   	M[s]=mp;
   	return mp;
}

int main(){
   	int casos;
   	string s;
   	cin>>casos;
   	for(int i=0;i<casos;i++)
   	{
      		cin>>s;
      		cout<<pal(s)<<endl;
   	}
    
}
