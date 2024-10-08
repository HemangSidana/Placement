#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void generate(vector<int> &z){
    do{
        for(auto x: z) cout<<x<<" ";
        cout<<endl;
    } while(next_permutation(z.begin(),z.end()));
}

// Print Permutations in sorted order given sorted array

int main(){
    vector<int> z{1,2,3,4};
    generate(z);
}