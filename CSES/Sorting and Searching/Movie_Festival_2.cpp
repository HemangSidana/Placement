#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<vector<int>> time;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        time.push_back({y,x});
    }
    sort(time.begin(),time.end());
    multiset<int> last;
    for(int i=0;i<k;i++) last.insert(0);
    int ans=0;
    for(int i=0;i<n;i++){
        int z=time[i][1];
        auto it = last.upper_bound(z);
        if(it==last.begin()) continue;
        it--;
        last.erase(it);
        last.insert(time[i][0]);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}