#include <iostream>
#include <vector>
using namespace std;

int dfs(int z, vector<int>& vis, vector<int> &child, vector<vector<int>>& adj, int n, vector<int>& val){
    vis[z]=1;
    if(z==n-1){
        val[z]=1;
        for(auto x: adj[z]){
            if(!vis[x]) dfs(x,vis,child,adj,n,val);
        }
        return 1;
    }
    else{
        int maxi=0; int ind=-1;
        for(auto x: adj[z]){
            int r;
            if(!vis[x]){
                r=dfs(x,vis,child,adj,n,val);
            }
            else r=val[x];
            if(r>maxi){
                maxi=r; ind=x;
            }
        }
        if(maxi>0){
            val[z]=maxi+1;
            child[z]=ind;
        }
        return val[z];
    }
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
    }
    vector<int> vis(n,0);
    vector<int> child(n,-1);
    vector<int> val(n,-1);
    int s=dfs(0,vis,child,adj,n,val);
    if(s<=0) cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> ans;
        ans.push_back(0);
        int cur=0;
        while(cur!=n-1){
            cur=child[cur];
            ans.push_back(cur);
        }
        cout<<ans.size()<<endl;
        for(auto x: ans) cout<<x+1<<" ";
    }
}