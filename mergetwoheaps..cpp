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
void heapify(vi&arr, int n, int i){
    int idx=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[idx])idx=l;
    if(r<n &&arr[r]>arr[idx])idx=r;
    if(idx!=i){
        swap(arr[i],arr[idx]);
        heapify(arr, n,idx);
    }
}
vector<int> mergeHeaps(vi&a, vi&b, int n,int m){
    vector<int> temp;
    for(auto i:a)temp.push_back(i);
    for(auto i:b)temp.push_back(i);
    int x=m+n;
    for(int i=x/2-1;x>=0;x--){
        heapify(temp,x,i);
    }
    return temp;
}