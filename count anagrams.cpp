#include<bits/stdc++.h>
using namespace std;

int countAnagrams(string txt,string pat)
{
    int c=0,i=0,j=0,dcount=0,k;
    int n=txt.length();
     int c1[256]={0};
     k=pat.length();
     for(int i=0;i<k;i++) //count all characters in pat
       c1[pat[i]]++;
     for(int i=0;i<256;i++)
        if(c1[i]!=0)
          dcount++; //distinct characters count

     while(j<n)
     {
         c1[txt[j]]--;
         if(c1[txt[j]]==0)  //if this is true that means we have counted all occurrences of one character so change dcount by-1
            dcount--;

         if(j-i+1==k)
         {
             if(dcount==0)  // if dcount if 0 it means that all distinct characters have been covered,hence we have found one anagram
                c++;
             if(c1[txt[i]]==0)
                dcount++;
             c1[txt[i]]++;
             i++;
         }
         j++;

     }
     return c;


}

int countAnagrams_MAP(string txt,string pat)
{
    int c=0,i=0,j=0,dcount=0,k;
    int n=txt.length();
    map<char,int> mp;
     k=pat.length();
     for(int i=0;i<k;i++) //count all characters in pat
     {
         auto a=mp.find(pat[i]);
         if(a==mp.end())
         {
             mp.insert({pat[i],1});
         }
         else
         {
             a->second+=1;
         }

     }
    dcount=mp.size();


     while(j<n)
     {

         auto a=mp.find(txt[j]);
         if(a!=mp.end())
         {
           a->second--;
           if(a->second==0)  //if this is true that means we have counted all occurrences of one character so change dcount by-1
            dcount--;
         }


         if(j-i+1==k)
         {

             if(dcount==0)  // if dcount if 0 it means that all distinct characters have been covered,hence we have found one anagram
                c++;
             auto a=mp.find(txt[i]);
             if(a!=mp.end())
             {
                 if(a->second==0)
                  dcount++;
                 a->second++;
             }
             i++;
         }
         j++;

     }
     return c;


}


int main()
{
  cout<<countAnagrams("aabaabaa","aaba")<<endl;
  cout<<countAnagrams_MAP("forxxorfxdofr","for");
}
