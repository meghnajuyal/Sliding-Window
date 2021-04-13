//First negative integer in every window of size k
#include<bits/stdc++.h>
using namespace std;


void firstNegative(int a[],int n,int k,vector<int>&ans)
{
     queue<int> l;
    int i=0,j=0,flag=0;

    while(j<n)
    {
      if(a[j]<0)
        l.push(a[j]);
      if(j-i+1==k)
      {
          if(l.size()==0)
            ans.push_back(0);
          else
          {
             ans.push_back(l.front());
            if(a[i]==l.front())
              l.pop();
          }

          i++;
      }

      j++;

    }
}
void firstNegative_brute(int a[],int n,int k,vector<int>&ans)
{
    int flag;
    for(int i=0;i<=n-k;i++)
    {
        flag=0;
        for(int j=i;j<i+k;j++)
         {
           if(a[j]<0)
           {
              ans.push_back(a[j]);
              flag=1;
              break;
           }
         }
         if(flag==0)
            ans.push_back(0);

    }


}

int main()
{
  int a[]={-8,2,3,-6,1,0};
  vector<int>ans;
  firstNegative_brute(a,6,2,ans);

  for(int i=0;i<ans.size();i++)
     cout<<ans[i]<<" ";

  ans.clear();
  firstNegative(a,6,2,ans);

  for(int i=0;i<ans.size();i++)
     cout<<ans[i]<<" ";

}
