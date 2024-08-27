#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    int m= 1e5;
    vector<int> v(m+1,0);
    v[0]=1;
    for(int i=0;i<n;i++){
        int z=x[i];
        for(int j=m;j>=z;j--){
            if(v[j-z]==1) v[j]=1;
        }
    }
    int count=0;
    for(int i=1;i<=m;i++) count+=v[i];
    cout<<count<<endl;
    for(int i=1;i<=m;i++){
        if(v[i]) cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}