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

priority_queue<int, vi, greater<int>> pqmin;
priority_queue<int, vi> pqmax;
void insertheap(int &x){
    if(pqmin.size()==pqmax.size()){
        if(pqmax.size()==0)pqmax.push(x);
        if(x<pqmax.top())pqmax.push(x);
        else pqmin.push(x);
    }
    else if(pqmax.size()> pqmin.size()){
        if(x>=pqmax.top()) pqmin.push(x);
        else{
            int temp=pqmax.top();
            pqmax.pop();
            pqmax.push(x);
            pqmin.push(temp);
        }
    }
    else{
        if(x<=pqmin.top())pqmax.push(x);
        else{
            int temp=pqmin.top();
            pqmin.pop();
            pqmin.push(x);
            pqmax.push(temp);
        }
    }
}
double getmedian(){
    if(pqmax.size()==pqmin.size())return (pqmax.top()+pqmin.top())/2.0;
    else if(pqmax.size()>pqmin.size())return pqmax.top();
    else return pqmin.top();
}