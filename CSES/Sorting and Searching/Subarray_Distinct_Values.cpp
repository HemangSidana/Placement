#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main(){
    int n,k; cin>>n>>k;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    int j=0; int dis=0;
    long long ans=0;
    map<int,int> m;
    for(int i=0;i<n;i++){
        while(j<n && dis<k){
            if(m.find(x[j])==m.end() || m[x[j]]==0){
                dis++;
                m[x[j]]=1;
            }
            else m[x[j]]++;
            j++;
        }
        while(j<n && (m.find(x[j])!=m.end() && m[x[j]]>0)){
            m[x[j]]++;
            j++;
        }
        ans+= 1ll*(j-i);
        if(m[x[i]]==1) dis--;
        m[x[i]]--;
    }
    cout<<ans<<endl;
    return 0;
}