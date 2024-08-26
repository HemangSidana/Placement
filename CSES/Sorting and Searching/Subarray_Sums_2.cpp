#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long

int main(){
    int n; ll x;
    cin>>n>>x;
    vector<ll> v;
    ll val=0;
    map<ll,ll> m;
    m[val]=1;
    ll ans=0;
    ll mini=0;
    ll maxi=0;
    for(int i=0;i<n;i++){
        ll z; cin>>z; val+=z;
        mini=min(val,mini);
        maxi=max(val,maxi);
        if(maxi>=(val-x) && mini<=(val-x) && m.find(val-x)!=m.end()){
            ans+=m[val-x];
        }
        if(m.find(val)==m.end()) m[val]=1;
        else m[val]++;
    }
    cout<<ans<<endl;
    return 0;
}