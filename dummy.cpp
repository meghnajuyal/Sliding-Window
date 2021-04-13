#include<bits/stdc++.h>
using namespace std;




int main()
{
    string s="aabbbcc";

    map<char,int> mp;

    for(int i=0;i<s.length();i++)
    {
        auto a=mp.find(s[i]);
        if(a==mp.end())
        {
            mp.insert({s[i],1});
        }
        else
        {

            a->second=a->second+1;
        }
    }

    for(auto i=mp.begin();i!=mp.end();i++)
        cout<<i->second;
}
