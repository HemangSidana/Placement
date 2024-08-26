#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
    int n; ll x;
    cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<pair<ll,ll>> v;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            v.push_back({a[i]+a[j],i*n+j});
        }
    }
    sort(v.begin(),v.end());
    int i=0; int j=v.size()-1;
    while(i<j){
        if(v[i].first+v[j].first==x){
            int a= v[i].second/n +1;
            int b= v[i].second%n +1;
            int c= v[j].second/n +1;
            int d= v[j].second%n +1;
            if(a!=c && a!=d && b!=c && b!=d){
                cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                return 0;
            }
            else if(v[i+1].first==v[i].first){
                i++; continue;
            }
        }
        if(v[i].first+v[j].first<x) i++;
        else j--;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}