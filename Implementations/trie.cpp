#include <iostream>
#include <vector>
using namespace std;

struct trie {
    trie *child[26];
    bool end;
    trie(){
        end=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

void insert(trie* root, string s){
    trie* cur=root;
    for(char c: s){
        if(cur->child[c-'a']==NULL){
            cur->child[c-'a']= new trie();
        }
        cur= cur->child[c-'a'];
    }
    cur->end=true;
}

bool search(trie* root, string s){
    trie* cur=root;
    for(char c: s){
        if(cur->child[c-'a']==NULL){
            return false;
        }
        cur= cur->child[c-'a'];
    }
    return cur->end;
}

int main(){
    trie* root= new trie();
    vector<string> v {"ant", "ball", "animal", "cat", "dog", "dad", "anime", "bald", "do"};
    for(auto x: v) insert(root,x);
    vector<string> q {"hemang","iit", "dog", "dad", "anime", "bald", "do"};
    for(auto x: q){
        cout<<search(root,x)<<endl;
    }
}