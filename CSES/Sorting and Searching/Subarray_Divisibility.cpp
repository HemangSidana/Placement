#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n; cin>>n;
    vector<int> v(n,0);
    v[0]++;
    int cur=0; long long ans=0;
    for(int i=0;i<n;i++){
        int x; cin>>x; x%=n;
        x+=n; x%=n;
        cur=(cur+x)%n;
        ans+=1ll*v[cur];
        v[cur]++;
    }
    cout<<ans<<endl;
    return 0;
}