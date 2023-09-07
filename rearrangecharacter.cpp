#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include<numeric>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii vector<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
/* The task is to rearrange characters in a string 
such that no two adjacent characters are the same.*/

string rearrangeString(string&s){
        int n=s.size();
        unordered_map<char, int> mp;
        char maxfreq;
        for(auto ch:s){
            mp[ch]++;
            if(mp[ch]>mp[maxfreq]){
                maxfreq=ch;
            }
        }
        if(mp[maxfreq]>(n+1)/2)return "-1";
        int idx=0;
        while(mp[maxfreq]){
            s[idx]=maxfreq;
            idx+=2;
            mp[maxfreq]--;
        }
        for(auto i:mp){
            char ch=i.first;
            int cnt=i.second;
            while(cnt){
                if(idx>=n)idx=1;
                s[idx]=ch;
                idx+=2;
                cnt--;
            }
        }
        return s;
}
/*using pq*/
string rearrangeStringpq(string &s){
    unordered_map<char,int> mp;
    for(auto ch:s)mp[ch]++;
    priority_queue<pair<int,char>>pq;
    for(auto x:mp){
        pq.push({x.second,x.first});
    }
    string ans="";
    pair<int,char> prev(-1,'#');
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        ans+=curr.second;
        curr.first--;
        if(prev.first>0)pq.push(prev);
        prev=curr;
    }
    if(ans.length()!=s.length())return "-1";
    return ans;
}
