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
    vector<int> color(n,0);
    for(int i=0;i<n;i++){
        if(color[i]!=0) continue;
        color[i]=1;
        stack<int> s;
        s.push(i);
        while(!s.empty()){
            int z= s.top();
            s.pop();
            for(auto x: adj[z]){
                if(color[x]==color[z]){
                    cout<<"IMPOSSIBLE"<<endl;
                    return 0;
                }
                if(color[x]==0){
                    color[x]=3-color[z];
                    s.push(x);
                }
            }
        }
    }
    for(int i=0;i<n;i++) cout<<color[i]<<" ";
    cout<<endl;
}