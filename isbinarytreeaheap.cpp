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
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int countnodes(Node*root){
    if(root==NULL)return 0;
    return 1+countnodes(root->left)+countnodes(root->right);
}
/* to check if BT is complete or not*/
bool iscomplete(Node*root, int index, int number_nodes){
    if(root==NULL)return 1;
    if(index>=number_nodes)return false;
    return iscomplete(root->left, 2*index+1,number_nodes)
        && iscomplete(root->right, 2*index+2, number_nodes);
}
bool isheap(Node*root){
    if(root->left==NULL && root->right==NULL)return true;
    if(root->right==NULL)return (root->data>=root->left->data);
    else{
        if(root->data >=root->left->data
        && root->data>=root->right->data){
            return (isheap(root->left)&& isheap(root->right));
        }
        else return false;
    }
}
bool isheapmain(Node*root){
    int node_count=countnodes(root);
    int index=0;
    if(iscomplete(root,index,node_count)&& isheap(root))return true;
    return false;
}

/* to check using lot*/
bool isheap(Node*root){
    queue<Node*>q;
    q.push(root);
    bool nullfound=false;
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp->left){
            if(nullfound||temp->left->data> temp->data)return false;
            q.push(temp->left);
        }
        else nullfound=true;
        if(temp->right){
            if(nullfound||temp->right->data> temp->data)return false;
            q.push(temp->right);
        }
        else nullfound=true;
    }
    return true;
}