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
/*all the values int the left 
subtree of a node should be
less than all the values in 
the right subtree of the tree*/

/* idea 
as we copy sorted elements in preorder 
fashion we ensure that left subtree element
remain there */
void inorder(Node*root, vector<int> &arr){
    if(root==NULL)return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
void bsttominheap(Node*root, vector<int>&arr, int*i){
    if(root==NULL)return ;
    root->data=arr[++*i];
    bsttominheap(root->left,arr,i);
    bsttominheap(root->right,arr,i);
}
void converttominheap(Node*root){
    vector<int> arr;
    int i=-1;
    inorder(root,arr);
    bsttominheap(root,arr,&i);
}
