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
/*In an array numbers range from 0 to 9 find the minimum sum*/
string solve(vi&arr, int n){
    sort(arr.begin(),arr.end());
    string s1="", s2="";
    for(int i=0;i<n;i++){
        if(i%2==0)s1+=to_string(arr[i]);
        else s2+=to_string(arr[i]);
    }
    string ans="";
    int n1=s1.size(), n2=s2.size();
    int carry=0;
    while(n1>0 && n2>0){
        int a=(s1[n1-1]-'0')+(s2[n2-1]-'0')+carry;
        ans+=to_string(a%10);
        carry=a/10;
        n1--;n2--;
    }
    if(n%2==1){
        ans+=s1[0]+carry;
    }
    else ans+=to_string(carry);
    while(ans.back()=='0')ans.pop_back();
    reverse(ans.begin(),ans.end());
    if(ans=="")return "0";
    return ans;
}
