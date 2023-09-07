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
/*Given an array and an integer K, find the
maximum for each and every contiguous
subarray of size K.*/
vector<int> max_of_subarray(vi&arr, int n, int k){
    vector<int> ans;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<k;i++){
        pq.push({arr[i],i});
    }
    ans.push_back(pq.top().first);
    for(int i=k;i<n;i++){
        pq.push({arr[i],i});
        while(pq.top().second<=i-k)pq.pop();
        ans.push_back(pq.top().first);
    }
    return ans;
}