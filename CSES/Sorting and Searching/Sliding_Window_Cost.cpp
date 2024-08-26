#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
    ll n,k; cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(k==1){
        for(int i=0;i<n;i++){
            cout<<0<<" ";
        }
        return 0;
    }
    multiset<ll> low;
    multiset<ll> high;
    vector<ll> temp;
    for(int i=0;i<k;i++) temp.push_back(v[i]);
    sort(temp.begin(),temp.end());
    int sz1= (k+1)/2; int sz2= k/2;
    ll sum1=0; ll sum2=0;
    for(int i=0;i<k;i++){
        if(i<(k+1)/2){sum1+=temp[i]; low.insert(temp[i]);}
        else{sum2+=temp[i]; high.insert(temp[i]);}
    }
    ll ans= (sz1-sz2)*(*(low.rbegin())) - sum1 + sum2 ;
    cout<<ans<<" ";
    for(int i=0;i<n-k;i++){
        if(low.find(v[i])!=low.end()){
            low.erase(low.find(v[i]));
            sum1-=v[i];
            if(v[i+k]<= *(high.begin())){
                low.insert(v[i+k]);
                sum1+=v[i+k];
            }
            else{
                low.insert(*(high.begin()));
                sum1+= *(high.begin());
                sum2-= *(high.begin());
                sum2+= v[i+k];
                high.erase(high.begin());
                high.insert(v[i+k]);
            }
        }
        else{
            high.erase(high.find(v[i]));
            sum2-=v[i];
            if(v[i+k]>= *(low.rbegin())){
                high.insert(v[i+k]);
                sum2+=v[i+k];
            }
            else{
                high.insert(*(low.rbegin()));
                sum2+= *(low.rbegin());
                sum1-= *(low.rbegin());
                sum1+= v[i+k];
                auto it=low.end(); it--;
                low.erase(it);
                low.insert(v[i+k]);
            }
        }
        ll ans= (sz1-sz2)*(*(low.rbegin())) - sum1 + sum2 ;
        cout<<ans<<" ";
    }
}