#include<iostream>
#include<map>

using namespace std;

int lengthMax(int a[],int n,int k)
{
  int sum=0,rem=0,max_len=0;
  unordered_map<int,int> mp;
   mp.insert({0,-1});

  for(int i=0;i<n;i++)
  {
      sum+=a[i];
      rem=sum%k;
      if(rem<0)
         rem+=k; //normalize result

      if(mp.find(rem)==mp.end())
         mp[rem]=i;
      else
       max_len=max(max_len,i-mp[rem]);

  }

}
