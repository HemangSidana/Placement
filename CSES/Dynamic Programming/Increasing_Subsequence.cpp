#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    vector<int> v;
    for(int i=0;i<n;i++){
        if(v.size()==0 || v.back()<x[i]){
            v.push_back(x[i]);
        }
        else{
            int ind= lower_bound(v.begin(),v.end(),x[i])-v.begin();
            v[ind]=x[i];
        }
    }
    cout<<v.size()<<endl;
    return 0;
}