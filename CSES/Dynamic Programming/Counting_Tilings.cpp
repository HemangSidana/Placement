#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
const ll mod= 1e9+7;

int main(){
    int n,m; cin>>n>>m;
    int z= (1<<n);
    ll dp[m+1][n][z];
    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<z;k++){
                dp[i][j][k]=0;
            }
        }
    }
    dp[0][n-1][z-1]=1;
    
    for(int c=1; c<=m; c++){
        for(int i=0;i<n;i++){
            for(int j=0;j<z;j++){
                if(i>0) dp[c][i][j]= dp[c][i-1][j ^ (1<<i)];
                else dp[c][i][j]= dp[c-1][n-1][j ^ (1<<i)];
                if(i>0 && (j & (1<<i)) && (j & (1<<(i-1)))){
                    if(i>1) dp[c][i][j]+=dp[c][i-2][j];
                    else dp[c][i][j] += dp[c-1][n-1][j];
                    dp[c][i][j] %= mod;
                }
            }
        }
    }
    cout<<dp[m][n-1][z-1]<<endl;
    return 0;
}