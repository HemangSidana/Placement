#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main(){
    int n; ll t;
    cin>>n>>t;
    vector<ll> k(n);
    for(int i=0;i<n;i++) cin>>k[i];
    ll lo=0; ll hi=1e18;
    ll ans;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        ll p=0;
        for(int i=0;i<n;i++){
            p+= mid/k[i];
            if(p>=t) break;
        }
        if(p>=t){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}