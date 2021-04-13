//Max Sum Subarray of size K
#include<bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int K, int Arr[] , int N){
        // code here
        int i=0,j=0,sum=0,mx=INT_MIN;
        while(j<N)
        {
          sum+=Arr[j];

          if(j-i+1==K)
           {
               mx=max(sum,mx);
               sum-=Arr[i];
               i++;

           }
           j++;
        }
        return mx;
    }
int maximumSumSubarray_Brute(int k,int a[],int n)
{
    int sum,max_sum=INT_MIN;
    for(int i=0;i<=n-k;i++)
    {
        sum=0;
        for(int j=i;j<i+k;j++)
        {
            sum+=a[j];
        }

        max_sum=max(sum,max_sum);
    }
    return max_sum;

}
int main()
{
 int a[]={100,200,300,400};
 cout<<maximumSumSubarray_Brute(2,a,4)<<endl;
 cout<<maximumSumSubarray(2,a,4);
}
