//Longest Substring With K Unique Characters
#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

int longest(string s,int k)
{
  unordered_map<int,int> mp;
  string ans="";
  int i=0,j=0,max_len=-1,n=s.length();
   while(j<n)
   {
      if(mp.find(s[j])==mp.end())
        mp[s[j]]=1;
      else
        mp[s[j]]+=1;

     if(mp.size()==k)
      {
          max_len=max(max_len,j-i+1);
      }
      else if(mp.size()>k)
      {
          while(mp.size()>k)
          {
              mp[s[i]]--;
              if(mp[s[i]]==0)
                mp.erase(s[i]);
              i++;
          }
      }
     j++;
   }

   return max_len;

}
int main()
{
  cout<<longest("aabacbebebe",3);

}
