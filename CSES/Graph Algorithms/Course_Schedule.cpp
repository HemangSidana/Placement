#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> deg(n,0);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        a--; b--; adj[a].push_back(b);
        deg[b]++;
    }
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(deg[i]==0){
            q.push(i); ans.push_back(i);
        }
    }
    while(!q.empty()){
        queue<int> z;
        while(!q.empty()){
            int x= q.front();
            q.pop();
            for(auto y: adj[x]){
                deg[y]--;
                if(deg[y]==0){
                    z.push(y);
                    ans.push_back(y);
                }
            }
        }
        q=z;
    }
    if(ans.size()<n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(auto x: ans){
            cout<<x+1<<" ";
        }
    }
}