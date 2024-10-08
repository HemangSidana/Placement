#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

int main(){
    int n,m,k; cin>>n>>m>>k;
    vector<vector<vector<ll>>> adj(n);
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back({b,c});
    }
    vector<int> vis(n,0);
    vector<priority_queue<ll>> hem(n);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    vector<ll> ans;
    while(!pq.empty() && ans.size()<k){
        pair<ll,ll> p= pq.top();
        pq.pop();
        vis[p.second]++;
        if(p.second==n-1) ans.push_back(p.first);
        if(vis[p.second]==k+1) continue;
        for(auto x: adj[p.second]){
            if(vis[x[0]]>=k) continue;
            if(hem[x[0]].size()>=k && hem[x[0]].top()<p.first+x[1]) continue;
            pq.push({p.first+x[1],x[0]});
            hem[x[0]].push(p.first+x[1]);
        }
    }
    for(auto z: ans){
        cout<<z<<" ";
    }
}