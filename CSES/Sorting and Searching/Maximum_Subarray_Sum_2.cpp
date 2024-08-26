#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
    int n,a,b; cin>>n>>a>>b;
    a--; b--;
    multiset<ll> m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<ll> pref(n+1,0);
    for(int i=0;i<n;i++) pref[i+1]=pref[i]+v[i];
    ll ans=-1e15;
    m.insert(0);
    for(int i=a;i<n;i++){
        ll cur= pref[i+1]-*(m.begin());
        m.insert(pref[i+1-a]);
        if(i>=b){
            m.erase(m.find(pref[i-b]));
        }
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
    return 0;
}