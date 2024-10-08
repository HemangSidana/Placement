#include <iostream>
#include <vector>
using namespace std;

vector<int> comb;

void generate(vector<int> &v, int ind, int r){
    if(r==0){
        for(auto x: comb){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    int n=v.size();
    for(int j=ind;j+r<=n;j++){
        comb.push_back(v[j]);
        generate(v,ind+1,r-1);
        comb.pop_back();
    }
}

// Print Combinations in sorted order given sorted array

int main(){
    vector<int> z{1,2,3,4,5,6,7};
    int r=3;
    generate(z,0,3);
}