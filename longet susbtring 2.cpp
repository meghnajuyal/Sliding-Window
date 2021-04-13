//Given a string S, find the length of the longest substring without repeating characters.
#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

int longest(string s)
{
    int i=0,j=0,max_len=-1,n=s.length();
    unordered_map<int,int> mp;
   while(j<n)
    {
        if(mp.find(s[j])==mp.end())
            mp[s[j]]=1;
        else
                mp[s[j]]+=1;
       if(mp.size()==j-i+1)
         max_len=max(max_len,j-i+1);

       else
       {
         while(mp.size()<j-i+1)   // if map size if less than the number of elements in window it means there are duplicates
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
    cout<<longest("qwertyz");
}
