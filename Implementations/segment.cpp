#include <iostream>
#include <vector>
using namespace std;

const int N= 1e5;
int t[4*N];

void build(vector<int>& a, int v, int l, int r){
    if(l==r){
        t[v]= a[l];
        return;
    }
    int m= (l+r)/2;
    build(a,2*v,l,m);
    build(a,2*v+1,m+1,r);
    t[v]= t[2*v]+ t[2*v+1];
}

int sum(int v, int tl, int tr, int l, int r){
    if(l>r) return 0;
    if(l==tl && r==tr) return t[v];
    int tm= (tl+tr)/2;
    return sum(2*v,tl,tm,l,min(r,tm))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}

void update(int v, int l, int r, int pos, int val){
    if(l==r){
        t[v]=val;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m) update(2*v,l,m,pos,val);
    else update(2*v+1,m+1,r,pos,val);
    t[v]=t[2*v]+t[2*v+1];
}


int main(){
    vector<int> z{1,2,3,4,5};
    build(z,1,0,4);
    cout<<sum(1,0,4,1,3)<<endl;;
    update(1,0,4,2,6);
    cout<<sum(1,0,4,1,3)<<endl;;
}