#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a,b; cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
    dp[1][1]=0;
    for(int i=2;i<=a;i++) dp[i][1]= i-1;
    for(int j=2;j<=b;j++) dp[1][j]= j-1;
    for(int i=2; i<=a; i++){
        for(int j=2; j<=b; j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            int cur=1e6;
            for(int k=1;k<i;k++){
                cur=min(cur,dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;k++){
                cur=min(cur,dp[i][k]+dp[i][j-k]+1);
            }
            dp[i][j]=cur;
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}