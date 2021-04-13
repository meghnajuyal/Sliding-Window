//Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.
#include<bits/stdc++.h>
using namespace std;

 vector <int> max_of_subarrays(int *arr, int n, int k){
        // your code here
        vector<int>ans;
        deque<int>q;
     int i=0,j=0;
     while(j<n)
     {
         while(q.size()>0&&q.back()<arr[j] )
          q.pop_back();
         
         q.push_back(arr[j]);
         
         if(j-i+1==k)
          {
               ans.push_back(q.front());
               if(q.front()==arr[i])
                 q.pop_front();
              i++;     
          }
          j++;
     
    
    }
    return ans;
    }    

void maximum_brute(int a[],int n,int k,vector<int>&ans)
{
    int mx;
    for(int i=0;i<n-k+1;i++)
    {
        mx=INT_MIN;
        for(int j=i;j<i+k;j++)
            mx=max(a[j],mx);
        ans.push_back(mx);
    }
}

int main()
{
    vector<int>ans;
    int a[]={1, 3, -1, -3, 5, 3, 6, 7};


    maximum(a,8,3,ans);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    ans.clear();

    maximum_brute(a,8,3,ans);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
