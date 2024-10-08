#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n);
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back({b,c});
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> dis(n);
    vector<int> vis(n,0);
    dis[0]=0;
    vis[0]=1;
    pq.push({0,0});
    while(!pq.empty()){
        pair<ll,ll> p= pq.top();
        pq.pop();
        if(dis[p.second]!=p.first) continue;
        for(auto x: adj[p.second]){
            if(!vis[x.first] || dis[x.first]>x.second+p.first){
                vis[x.first]=1;
                pq.push({x.second+p.first,x.first});
                dis[x.first]= x.second+p.first;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
}