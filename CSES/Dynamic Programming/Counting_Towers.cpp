#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
const ll mod= 1e9+7;

int main(){
    int t; cin>>t;
    vector<ll> dp1(1e6+5,0);
    vector<ll> dp2(1e6+5,0);
    dp1[1]=1;
    dp2[1]=1;
    for(int i=2;i<=1e6;i++){
        dp1[i]= 4*dp1[i-1]+ dp2[i-1];
        dp2[i]= dp1[i-1]+ 2*dp2[i-1];
        dp1[i] %= mod;
        dp2[i] %= mod;
    }
    while(t--){
        int n; cin>>n;
        ll ans= dp1[n]+dp2[n];
        ans %= mod;
        cout<<ans<<endl;
    }
    return 0;
}