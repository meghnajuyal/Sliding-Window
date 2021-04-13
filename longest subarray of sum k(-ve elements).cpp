 int lenOfLongSubarr(int A[],  int N, int K)
    {
        // Complete the function
        unordered_map <int,int>mp;
        int sum=0,mx=0;
        for(int i=0;i<N;i++)
        {
          sum+=A[i];
          if(sum==K)
            mx=i+1;

          if(mp.find(sum)==mp.end())
           mp[sum]=i;
          if(mp.find(sum-K)!=mp.end())
           mx=max(mx,i-mp[sum-K]);
        }
        return mx;
    }
