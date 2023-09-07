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

void heapify(vi &arr, int n, int i){
    int idx=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[idx]){
        idx=l;
    }
    if(r<n && arr[r]>arr[idx]){
        idx=r;
    }
    if(idx!=i){
        swap(arr[idx],arr[i]);
        heapify(arr,n,idx);
    }
}
void buildheap(vi&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void heapsort(vi &arr, int n){
    buildheap(arr);
}