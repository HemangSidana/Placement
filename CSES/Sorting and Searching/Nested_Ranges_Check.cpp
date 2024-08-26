#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int> &v1, const vector<int> &v2){
    if(v1[0]<v2[0]) return true;
    if(v1[0]==v2[0] && v1[1]>v2[1]) return true;
    return false;
}

int main(){
    int n; cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),compare);
    vector<int> contains(n,0);
    vector<int> contained(n,0);
    int right=0;
    for(int i=0;i<n;i++){
        if(v[i][1]<=right){
            contained[v[i][2]]=1;
        }
        else right=v[i][1];
    }
    right=1e9 +1;
    for(int i=n-1;i>=0;i--){
        if(v[i][1]>=right){
            contains[v[i][2]]=1;
        }
        else right=v[i][1];
    }
    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }
    cout<<endl;
    return 0;
}