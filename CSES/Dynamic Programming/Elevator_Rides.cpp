#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
    int n; cin>>n;
    ll x; cin>>x;
    vector<ll> w(n);
    for(int i=0;i<n;i++) cin>>w[i];
    int z= (1<<n);
    pair<int,int> temp={n+1,0};
    vector<pair<int,int>> dp(z,temp);
    dp[0]={1,0};
    for(int s=1; s<z; s++){
        for(int i=0; i<n; i++){
            if(s & (1<<i)){
                pair<int,int> p= dp[s ^ (1<<i)];
                ll val= 1ll*p.second+ w[i];
                if(val>x){
                    p.first +=1;
                    p.second = w[i];
                }
                else{
                    p.second += w[i];
                }
                dp[s]= min(dp[s],p);
            }
        }
    }
    int ans= dp[z-1].first;
    cout<<ans<<endl;
    return 0;
}