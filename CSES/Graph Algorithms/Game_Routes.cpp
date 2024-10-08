#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const ll mod= 1000000007;

vector<int> vis;
vector<vector<int>> adj;
vector<ll> val;

ll dfs(int z,int n){
    vis[z]=1;
    if(z==n-1){
        val[z]=1;
        for(auto x: adj[z]){
            if(!vis[x]) dfs(x,n);
        }
        return val[z];
    }
    else{
        ll ans=0;
        for(auto x: adj[z]){
            if(vis[x]) ans=(ans+val[x])%mod;
            else{
                ll cur= dfs(x,n);
                ans=(ans+cur)%mod;
            }
        }
        val[z]=ans;
        return ans;
    }
}

int main(){
    int n,m; cin>>n>>m;
    adj.assign(n,vector<int>());
    vis.assign(n,0);
    val.assign(n,0ll);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
    }
    ll ans= dfs(0,n);
    cout<<ans<<endl;
}