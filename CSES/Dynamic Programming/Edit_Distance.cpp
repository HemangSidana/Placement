#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string a,b; cin>>a>>b;
    int n= a.size();
    int m= b.size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][0]= (a[0] != b[0]);
    for(int i=1;i<n;i++){
        dp[i][0]=min(1+dp[i-1][0],(a[i] != b[0])+i);
    }
    for(int j=1;j<m;j++){
        dp[0][j]=min(1+dp[0][j-1],(b[j] != a[0])+j);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1, dp[i-1][j-1]+1});
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}