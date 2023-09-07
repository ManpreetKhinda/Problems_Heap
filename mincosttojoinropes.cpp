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

long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(long long  i=0;i<n;i++)pq.push(arr[i]);
        long long sum=0;
        while(pq.size()>1){
            long long  x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            long long temp=x+y;
            sum+=temp;
            pq.push(temp);
        }
        return sum;
    }