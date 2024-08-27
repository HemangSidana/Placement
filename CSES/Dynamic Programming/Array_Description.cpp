#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
const ll mod= 1e9+7;

int main(){
    int n,m; cin>>n>>m;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    vector<vector<ll>> dp(n,vector<ll>(m+1,0));
    if(x[0]==0){
        for(int i=1;i<=m;i++) dp[0][i]=1;
    }
    else{
        dp[0][x[0]]=1;
    }
    for(int i=1;i<n;i++){
        if(x[i]==0){
            dp[i][1]=dp[i-1][1];
            dp[i][m]=dp[i-1][m];
            if(m>1){
                dp[i][1]+=dp[i-1][2];
                dp[i][1] %= mod;
                dp[i][m]+=dp[i-1][m-1];
                dp[i][m] %= mod;
            }
            for(int j=2;j<m;j++){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j+1]+dp[i-1][j-1]) % mod;
            }
        }
        else{
            int z= x[i];
            dp[i][z]=dp[i-1][z];
            if(z-1>0) dp[i][z]+=dp[i-1][z-1];
            if(z+1<=m) dp[i][z]+=dp[i-1][z+1];
            dp[i-1][z] %= mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        ans+=dp[n-1][i];
        ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}