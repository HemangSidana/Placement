#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector<int> vis1;
vector<int> vis2;
vector<int> par;

int st; 
int en;
bool found;

void dfs(int z, int p, vector<vector<int>>& adj){
    vis1[z]=1;
    par[z]=p;
    for(auto x: adj[z]){
        if(!vis1[x]){dfs(x,z,adj);}
        else if(!vis2[x]){
            found=true;
            st=z; en=x;
        }
    }
    vis2[z]=1;
}

int main(){
    int n, m; cin>>n>>m;
    found=false;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b; a--; b--;
        adj[a].push_back(b);
    }
    vis1.assign(n,0);
    vis2.assign(n,0);
    par.assign(n,-1);
    for(int i=0;i<n;i++){
        if(!vis1[i]){
            dfs(i,-1,adj);
        }
    }
    if(!found){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int> ans;
        ans.push_back(st);
        int cur=par[st];
        while(cur!=en){
            ans.push_back(cur);
            cur=par[cur];
        }
        ans.push_back(en);
        ans.push_back(st);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto x: ans) cout<<x+1<<" ";
    }
}