#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main(){
    int n,k; cin>>n>>k;
    vector<ll> v(n);
    ll lo=0; 
    for(int i=0;i<n;i++){cin>>v[i]; lo=max(lo,v[i]);}
    ll hi=1e15; ll ans;
    while(lo<hi){
        ll mid= (lo+hi)/2;
        int z=0; ll cur=1e15;
        for(int i=0;i<n;i++){
            if(cur+v[i]>mid){
                z++; cur=0;
            }
            cur+=v[i];
        }
        if(z>k){
            lo=mid+1;
        }
        else{hi=mid; ans=mid;}
    }
    cout<<ans<<endl;
    return 0;
}