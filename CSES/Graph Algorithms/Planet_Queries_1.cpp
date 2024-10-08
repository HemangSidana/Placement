#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n,q; cin>>n>>q;
    int z=30;
    int par[n][z];
    for(int i=0;i<n;i++){
        int r; cin>>r;
        par[i][0]=r-1;
    }
    for(int j=1;j<z;j++){
        for(int i=0;i<n;i++){
            par[i][j]=par[par[i][j-1]][j-1];
        }
    }
    while(q--){
        int x,k; cin>>x>>k;
        x--;
        for(int i=0;i<30;i++){
            if(k & (1<<i)){
                x=par[x][i];
            }
        }
        cout<<x+1<<endl;
    }
}