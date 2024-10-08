#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
const ll mod= 1000000007;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<vector<ll>>> adj(n);
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back({b,c});
    }
    vector<ll> cost(n,1e14);
    vector<ll> num(n,0);
    vector<int> mini(n);
    vector<int> maxi(n);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    cost[0]=0;
    num[0]=1;
    mini[0]=1;
    maxi[0]=1;
    while(!pq.empty()){
        pair<ll,ll> p= pq.top();
        pq.pop();
        for(auto x: adj[p.second]){
            if(p.first+x[1]==cost[x[0]]){
                mini[x[0]]=min(mini[x[0]],1+mini[p.second]);
                maxi[x[0]]=max(maxi[x[0]],1+maxi[p.second]);
                num[x[0]]= (num[x[0]]+num[p.second])%mod;
            }
            else if(p.first+x[1]<cost[x[0]]){
                mini[x[0]]=1+mini[p.second];
                maxi[x[0]]=1+maxi[p.second];
                num[x[0]]=num[p.second];
                cost[x[0]]=p.first+x[1];
                pq.push({cost[x[0]],x[0]});
            }
        }
    }
    cout<<cost[n-1]<<" "<<num[n-1]<<" "<<mini[n-1]-1<<" "<<maxi[n-1]-1<<endl;
}