#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    int n, m; cin>>n>>m;
    vector<vector<ll>> edge;
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        edge.push_back({a,b,c});
    }
    vector<ll> par(n,-1);
    vector<ll> dis(n,0);
    bool cyc=false; int st;
    for(int i=0;i<n;i++){
        for(auto x: edge){
            if(dis[x[0]]+x[2]<dis[x[1]]){
                dis[x[1]]=dis[x[0]]+x[2];
                par[x[1]]=x[0];
                if(i==n-1){
                    cyc=true;
                    st=x[1];
                }
            }
        }
    }
    if(!cyc) cout<<"NO"<<endl;
    else{
        for(int i=0;i<n;i++) st=par[st];
        vector<int> ans;
        ans.push_back(st);
        int j=par[st];
        while(j!=st){
            ans.push_back(j);
            j=par[j];
        }
        ans.push_back(st);
        reverse(ans.begin(),ans.end());
        cout<<"YES"<<endl;
        for(auto x: ans) cout<<x+1<<" ";
    }
}