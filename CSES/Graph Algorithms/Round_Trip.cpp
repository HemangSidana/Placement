#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> start(n,0);
    vector<int> end(n,0);
    vector<int> par(n,-1);
    for(int i=0;i<n;i++){
        if(start[i]) continue;
        stack<int> s;
        start[i]=1;
        s.push(i);
        while(!s.empty()){
            int z= s.top();
            bool left=false;
            for(auto x: adj[z]){
                if(!start[x]){
                    par[x]=z;
                    start[x]=1;
                    s.push(x);
                    left=true;
                    break;
                }
            }
            if(!left){
                end[z]=1;
                s.pop();
                for(auto x: adj[z]){
                    if(x!=par[z] && end[x]==0 && start[x]==1){
                        int cur=z;
                        vector<int> ans;
                        ans.push_back(x+1);
                        while(cur!=x){
                            ans.push_back(cur+1);
                            cur=par[cur];
                        }
                        ans.push_back(x+1);
                        cout<<ans.size()<<endl;
                        for(auto x: ans){
                            cout<<x<<" ";
                        }
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}