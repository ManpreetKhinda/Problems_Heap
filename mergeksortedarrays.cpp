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
/*given k sorted arrays merge into one*/
struct Node
{
	int data;
	Node* next;
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
vector<int> mergekarrays(vector<vector<int>>&arr, int k){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for(int i=0;i<k;i++){
        pq.push({arr[i][0],i});
    }
    vector<int> ans;
    vector<int> idx(k,0);
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        ans.push_back(x.first);
        if(idx[x.second]+1<arr[x.second].size()){
            pq.push({arr[x.second][idx[x.second+1]],x.second});
        }
        idx[x.second]++;
    }
    return ans;
}
/* merge k sorted lists*/
struct compare{
    bool operator()(const Node*a, const Node*b){
        return a->data>b->data;
    }
};
Node*mergeklists(vector<Node*>&lists){
    priority_queue<Node*,vector<Node*>,compare>pq;
    for(auto i:lists){
        if(i)pq.push(i);
    }
    Node*head=pq.top();
    pq.pop();
    if(head->next)pq.push(head->next);
    Node*curr=head;
    while(!pq.empty()){
        curr->next=pq.top();
        pq.pop();
        curr=curr->next;
        if(curr->next)pq.push(curr->next);
    }
    return head;
}