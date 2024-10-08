#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n);
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back({b,-c});
    }
    vector<ll> dp(n,1e16);
    dp[0]=0;
    for(int i=0;i+1<n;i++){
        for(int j=0;j<n;j++){
            if(dp[j]==1e16) continue;
            for(auto x: adj[j]){
                dp[x.first]=min(dp[x.first],dp[j]+x.second);
            }
        }
    }
    vector<ll> dp2(n);
    for(int i=0;i<n;i++) dp2[i]=dp[i];
    for(int j=0;j<n;j++){
        if(dp[j]==1e16) continue;
        for(auto x: adj[j]){
            dp2[x.first]=min(dp2[x.first],dp2[j]+x.second);
        }
    }
    vector<int> vis(n,0);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(dp[i]!=dp2[i]){
            vis[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int z= q.front();
        q.pop();
        for(auto x: adj[z]){
            if(!vis[x.first]){
                vis[x.first]=1;
                q.push(x.first);
            }
        }
    }
    if(vis[n-1]) cout<<-1<<endl;
    else{
        cout<<-dp[n-1]<<endl;
    }
}