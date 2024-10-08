#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    vector<vector<int>> vis(n,vector<int>(m,0));
    int sx,sy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='M'){
                q1.push({i,j});
            }
            if(v[i][j]=='A'){
                q2.push({i,j});
                sx=i; sy=j;
                v[i][j]='.';
            }
        }
    }
    while(!q2.empty()){
        queue<pair<int,int>> mon;
        while(!q1.empty()){
            pair<int,int> p= q1.front();
            q1.pop();
            int x= p.first; int y= p.second;
            if(x>0 && v[x-1][y]=='.'){
                v[x-1][y]='M';
                mon.push({x-1,y});
            }
            if(x<n-1 && v[x+1][y]=='.'){
                v[x+1][y]='M';
                mon.push({x+1,y});
            }
            if(y>0 && v[x][y-1]=='.'){
                v[x][y-1]='M';
                mon.push({x,y-1});
            }
            if(y<m-1 && v[x][y+1]=='.'){
                v[x][y+1]='M';
                mon.push({x,y+1});
            }
        }
        q1=mon;
        queue<pair<int,int>> qnext;
        while(!q2.empty()){
            pair<int,int> p= q2.front();
            q2.pop();
            int x= p.first; int y= p.second;
            if(x==0 || x==n-1 || y==0 || y==m-1){
                string ans="";
                while(x!=sx || y!=sy){
                    if(vis[x][y]==1){
                        ans+='U';
                        x++;
                    }
                    else if(vis[x][y]==2){
                        ans+='D';
                        x--;
                    }
                    else if(vis[x][y]==3){
                        ans+='L';
                        y++;
                    }
                    else{
                        ans+='R';
                        y--;
                    }
                }
                reverse(ans.begin(),ans.end());
                cout<<"YES"<<endl;
                cout<<ans.size()<<endl;
                cout<<ans<<endl;
                return 0;
            }
            if(!vis[x-1][y] && v[x-1][y]=='.'){
                vis[x-1][y]=1;
                qnext.push({x-1,y});
            }
            if(!vis[x+1][y] && v[x+1][y]=='.'){
                vis[x+1][y]=2;
                qnext.push({x+1,y});
            }
            if(!vis[x][y-1] && v[x][y-1]=='.'){
                vis[x][y-1]=3;
                qnext.push({x,y-1});
            }
            if(!vis[x][y+1] && v[x][y+1]=='.'){
                vis[x][y+1]=4;
                qnext.push({x,y+1});
            }
        }
        q2= qnext;
        
    }
    cout<<"NO"<<endl;
}