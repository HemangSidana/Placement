#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void update(vector<int> &tree, int v, int l, int h, int pos, int val){
    if(l==h) tree[v]=val;
    else{
        int mid=(l+h)/2;
        if(pos<=mid) update(tree,2*v,l,mid,pos,val);
        else update(tree,2*v+1,mid+1,h,pos,val);
        tree[v]= tree[2*v]+tree[2*v+1];
    }
}

int sum(vector<int> &tree, int v, int tl, int tr, int l, int r){
    if(l>r) return 0;
    if(l==tl && r==tr) return tree[v];
    int tm= (tl+tr)/2;
    return sum(tree,2*v,tl,tm,l,min(r,tm)) + sum(tree,2*v+1,tm+1,tr,max(l,tm+1),r);
}

int main(){
    int n; cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,-y,i,1});
        v.push_back({y,-x,i,-1});
    }
    sort(v.begin(),v.end());
    vector<int> tree(4*n,0);
    vector<int> contains(n);
    vector<int> contained(n);
    vector<int> m(n);
    int j=0;
    for(auto x: v){
        if(x[3]==1){
            m[x[2]]=j;
            j++;
        }
    }
    int open=-1;
    for(auto x: v){
        int ind= m[x[2]];
        if(x[3]==1){
            update(tree,1,0,n-1,ind,1);
            open=ind;
        }
        else{
            contains[x[2]]=open-ind-sum(tree,1,0,n-1,ind+1,open);
            contained[x[2]]=sum(tree,1,0,n-1,0,ind-1);
            update(tree,1,0,n-1,ind,0);
        }
    }
    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }
    cout<<endl;
    return 0;
}