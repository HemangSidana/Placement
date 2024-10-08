#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
    int n,m,q; cin>>n>>m>>q;
    ll dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else dp[i][j]=1e12;
        }
    }
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        dp[a][b]=min(dp[a][b],c);
        dp[b][a]=min(dp[b][a],c);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dp[j][k]= min(dp[j][i]+dp[i][k],dp[j][k]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==1e12) dp[i][j]=-1;
        }
    }
    while(q--){
        int a,b; cin>>a>>b;
        a--; b--;
        cout<<dp[a][b]<<endl;
    }
}