#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
    int n; cin>>n;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    vector<vector<ll>> dp(n,vector<ll>(n));
    vector<ll> pref(n+1,0);
    for(int i=1;i<=n;i++) pref[i]=pref[i-1]+x[i-1];
    for(int i=0;i<n;i++) dp[i][i]=x[i];
    for(int l=1;l<n;l++){
        for(int i=0;i+l<n;i++){
            dp[i][i+l]= max(pref[i+l+1]-pref[i+1]-dp[i+1][i+l]+x[i],pref[i+l]-pref[i]-dp[i][i+l-1]+x[i+l]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}