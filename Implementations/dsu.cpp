#include <iostream>
using namespace std;

const int N= 1e5;
int par[N];
int sz[N];

void add(int v){
    par[v]=v;
    sz[v]=1;
}

int parent(int v){
    if(par[v]==v) return v;
    int z= parent(par[v]);
    par[v]=z;
    return z;
}

void merge(int a, int b){
    a= parent(a);
    b= parent(b);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
}


int main(){
    for(int i=0;i<20;i++) add(i);
    for(int j=0;j<9;j++) merge(j,j+2);
    for(int i=0;i<20;i++){
        int z= parent(i);
        cout<<z<<" "<<sz[z]<<endl;
    }
}