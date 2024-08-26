#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void build(vector<int> &tree, int v, int l, int h){
    if(l==h) tree[v]=1;
    else{
        int mid=(l+h)/2;
        build(tree,v*2,l,mid);
        build(tree,v*2+1,mid+1,h);
        tree[v]= tree[2*v]+tree[2*v+1];
    }
}

void update(vector<int> &tree, int v, int l, int h, int pos){
    if(l==h) tree[v]=0;
    else{
        int mid=(l+h)/2;
        if(pos<=mid) update(tree,2*v,l,mid,pos);
        else update(tree,2*v+1,mid+1,h,pos);
        tree[v]= tree[2*v]+tree[2*v+1];
    }
}

int find(vector<int> &tree, int v, int l, int h , int k){
    if(l==h) return l;
    int y= tree[2*v];
    int mid=(l+h)/2;
    if(y>=k){
        return find(tree,2*v,l,mid,k);
    }
    else{
        return find(tree,2*v+1,mid+1,h,k-y);
    }
}

int main(){
    int n,k; cin>>n>>k;
    vector<int> tree(4*n);
    build(tree,1,0,n-1);
    int before=0; 
    for(int j=n;j>0;j--){
        int after= j-before; 
        if(after>=k+1){before+=k;}
        else{before=(k-after)%j;}
        int x= find(tree,1,0,n-1,before+1);
        update(tree,1,0,n-1,x);
        cout<<x+1<<" ";
    }
    cout<<endl;
    return 0;
}