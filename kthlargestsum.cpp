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
/* K-th largest sum of 
contiguous subarray within the array elements.*/

int kthlargestsum(vi&arr, int n,int k){
    vector<int>sums;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            sums.push_back(sum);
        }
        
    }
    sort(sums.begin(),sums.end(),greater<int>());
    return sums[k-1];
}
/*using pq*/
int kthlargestsum(vi&arr, int n, int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            pq.push(sum);
            if(pq.size()>k)pq.pop();
        }
    }
    return pq.top();
}