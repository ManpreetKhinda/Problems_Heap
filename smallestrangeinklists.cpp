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

/*smallest range in k lists
given sorted lists find range that includes at least one element
from each of the k lists*/

class Solution {
public:
class Node {
    public:
    int data;
    int row;
    int nextcol;
    Node(int data, int row, int nextcol)
    {
        this->data = data;
        this->row = row;
        this->nextcol = nextcol;
    }
};
struct compare{
        bool operator()(Node a,Node b){
            return a.data>b.data;
        }
};
vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<Node,vector<Node>, compare> pq;
        int maxi=INT_MIN;
        int range=INT_MAX;
        for(int i=0;i<k;i++){
            pq.push(Node(nums[i][0],i,0));
            maxi=max(maxi,nums[i][0]);
        }
        int start=0,end=0;
        while(!pq.empty()){
            Node x=pq.top();
            pq.pop();
            int mini=x.data;
            if(range>maxi-mini){
                start=mini;
                end=maxi;
                range=maxi-mini;
            }
            int nr=x.row;
            int nc=x.nextcol;
            if(nc+1<nums[nr].size()){
                pq.push(Node(nums[nr][nc+1],nr,nc+1));
                maxi=max(maxi,nums[nr][nc+1]);
            }
            else break;
        }
        
        return {start,end};



    }
};