#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

int main(){
    int n,m; cin>>n>>m;
    vector<vector<vector<ll>>> adj(n);
    vector<vector<vector<ll>>> adj2(n);
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back({b,c});
        adj2[b].push_back({a,c});
    }
    vector<ll> dis1(n,1e14);
    vector<ll> dis2(n,1e14);
    dis1[0]=0; dis2[n-1]=0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0ll,0ll});
    while(!pq.empty()){
        pair<ll,ll> p= pq.top();
        pq.pop();
        if(dis1[p.second]<p.first) continue;
        for(auto x: adj[p.second]){
            if(dis1[x[0]]>dis1[p.second]+x[1]){
                dis1[x[0]]=dis1[p.second]+x[1];
                pq.push({dis1[x[0]],x[0]});
            }
        }
    }
    pq.push({0ll,n-1});
    while(!pq.empty()){
        pair<ll,ll> p= pq.top();
        pq.pop();
        if(dis2[p.second]<p.first) continue;
        for(auto x: adj2[p.second]){
            if(dis2[x[0]]>dis2[p.second]+x[1]){
                dis2[x[0]]=dis2[p.second]+x[1];
                pq.push({dis2[x[0]],x[0]});
            }
        }
    }
    ll ans= dis1[n-1];
    for(int i=0;i<n;i++){
        for(auto x: adj[i]){
            ans=min(ans,dis1[i]+dis2[x[0]]+(x[1]/2));
        }
    }
    cout<<ans<<endl;
}