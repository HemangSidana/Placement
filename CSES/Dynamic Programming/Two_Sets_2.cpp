#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
const ll mod= 1e9+7;

int main(){
    int n; cin>>n;
    int z=n*(n+1)/2;
    if(z%2){
        cout<<0<<endl; return 0;
    }
    z/=2;
    vector<ll> dp(z+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=z;j>=i;j--){
            dp[j]=(dp[j]+dp[j-i])%mod;
        }
    }
    ll ans=dp[z];
    // Cannot divide by 2 directly. Use inverse modulo.
    ans*=500000004;
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}