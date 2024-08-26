#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(k==1){
        for(auto x: v){
            cout<<x<<" ";
        }
        return 0;
    }
    multiset<int> low;
    multiset<int> high;
    vector<int> temp;
    for(int i=0;i<k;i++) temp.push_back(v[i]);
    sort(temp.begin(),temp.end());
    int sz1= (k+1)/2; int sz2= k/2;
    for(int i=0;i<k;i++){
        if(i<(k+1)/2) low.insert(temp[i]);
        else high.insert(temp[i]);
    }
    int ans= *(low.rbegin());
    cout<<ans<<" ";
    for(int i=0;i<n-k;i++){
        if(low.find(v[i])!=low.end()){
            low.erase(low.find(v[i]));
            if(v[i+k]<= *(high.begin())){
                low.insert(v[i+k]);
            }
            else{
                low.insert(*(high.begin()));
                high.erase(high.begin());
                high.insert(v[i+k]);
            }
        }
        else{
            high.erase(high.find(v[i]));
            if(v[i+k]>= *(low.rbegin())){
                high.insert(v[i+k]);
            }
            else{
                high.insert(*(low.rbegin()));
                auto it=low.end(); it--;
                low.erase(it);
                low.insert(v[i+k]);
            }
        }
        int ans= *(low.rbegin());
        cout<<ans<<" ";
    }
}