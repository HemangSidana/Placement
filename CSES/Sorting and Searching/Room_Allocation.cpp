#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tree[(int)1e6];

void build(int v, int l, int h){
    if(l==h) tree[v]=1;
    else{
        int mid=(l+h)/2;
        build(v*2,l,mid);
        build(v*2+1,mid+1,h);
        tree[v]= tree[2*v]+tree[2*v+1];
    }
}

void update(int v, int l, int h, int pos, int val){
    if(l==h) tree[v]=val;
    else{
        int mid=(l+h)/2;
        if(pos<=mid) update(2*v,l,mid,pos,val);
        else update(2*v+1,mid+1,h,pos,val);
        tree[v]= tree[2*v]+tree[2*v+1];
    }
}

int find(int v, int l, int h , int k){
    if(l==h) return l;
    int y= tree[2*v];
    int mid=(l+h)/2;
    if(y>=k){
        return find(2*v,l,mid,k);
    }
    else{
        return find(2*v+1,mid+1,h,k-y);
    }
}

int main(){
    int n; cin>>n;
    build(1,0,n-1);
    vector<int> room(n,0);
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        v.push_back({a,0,i});
        v.push_back({b,1,i});
    }
    sort(v.begin(),v.end());
    int k=0;
    for(auto x: v){
        if(x[1]==0){
            int y= find(1,0,n-1,1);
            update(1,0,n-1,y,0);
            room[x[2]]=y+1;
            k=max(k,y+1);
        }
        else{
            int z= room[x[2]]-1;
            update(1,0,n-1,z,1);
        }
    }
    cout<<k<<endl;
    for(int i=0;i<n;i++) cout<<room[i]<<" ";
    cout<<endl;
    return 0;
}