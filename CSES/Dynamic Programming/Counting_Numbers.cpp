#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

ll comp(string a){
    int n= a.size();
    ll dp1[n][10][2][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                    dp1[i][j][k][l]=0;
                }
            }
        }
    }
    dp1[0][0][0][1]=1;
    for(int i=1;i<10;i++){
        if(a[0]-'0'>i){
            dp1[0][i][0][0]=1;
        }
        if(a[0]-'0'==i){
            dp1[0][i][1][0]=1;
        }
    }
    for(int i=1; i<n; i++){
        for(int k=0; k<10; k++){
            if(a[i]-'0'==k && a[i]!=a[i-1]){
                dp1[i][k][1][0]=dp1[i-1][a[i-1]-'0'][1][0];
            }
            if(k==0){
                dp1[i][k][0][1]=dp1[i-1][k][0][1];
            }
            ll cur=0;
            for(int j=0; j<10; j++){
                if(j==k) continue;
                cur+= dp1[i-1][j][0][0];
            }
            if(k!=0) cur+= dp1[i-1][0][0][1];
            if(a[i]-'0'>k && (a[i-1]-'0')!=k){
                cur+= dp1[i-1][a[i-1]-'0'][1][0];
            }
            dp1[i][k][0][0]=cur;
        }
    }
    ll ans=0;
    for(int j=0;j<10;j++){
        ans+=dp1[n-1][j][0][0];
        ans+=dp1[n-1][j][1][0];
        ans+=dp1[n-1][j][0][1];
    }
    return ans;
}

int main(){
    string a,b; cin>>a>>b;
    ll ans1= comp(b);
    ll ans2= comp(a);
    ll ans= ans1-ans2;
    bool add=true;
    for(int i=0;i+1<a.size();i++){
        if(a[i]==a[i+1]) add=false;
    }
    if(add) ans++;
    cout<<ans<<endl;
    return 0;
}