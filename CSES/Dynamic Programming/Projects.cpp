#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
    int n; cin>>n;
    vector<ll> dp(n);
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int a,b,p; cin>>a>>b>>p;
        v.push_back({b,a,p});
    }
    sort(v.begin(),v.end());
    dp[0]=1ll*v[0][2];
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1];
        vector<int> z= {v[i][1],0,0};
        int ind= lower_bound(v.begin(),v.end(),z)-v.begin();
        ind--;
        if(ind<0){
            dp[i]=max(dp[i],1ll*v[i][2]);
        }
        else{
            dp[i]=max(dp[i],1ll*v[i][2]+dp[ind]);
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}