#include <iostream>
#include <vector>
using namespace std;

bool dead(int pos, vector<int> &vis){
    if(pos<0 || pos>48) return false;
    if(vis[pos]) return false;
    int block=0;
    if(pos%7>0 && vis[pos-1]) block++;
    if(pos%7<6 && vis[pos+1]) block++;
    if(pos>6 && vis[pos+7]) block++;
    if(pos<42 && vis[pos-7]) block++;
    if(block==3) return true;
    return false;
}

bool valid(int pos, vector<int> &vis){
    if(pos%7==6 && pos>=7 && pos<42){
        if(vis[pos-1] && !vis[pos-7] && !vis[pos+7]) return false;
    }
    if(pos%7==0 && pos>=7 && pos<42){
        if(vis[pos+1] && !vis[pos-7] && !vis[pos+7]) return false;
    }
    if(pos<7 && pos%7!=0 && pos%7!=6){
        if(vis[pos+7] && !vis[pos+1] && !vis[pos-1]) return false;
    }
    if(pos>=42 && pos%7!=0 && pos%7!=6){
        if(vis[pos-7] && !vis[pos+1] && !vis[pos-1]) return false;
    }
    if(pos%7!=0 && pos%7!=6 && pos>=7 && pos<42){
        if(vis[pos+1] && vis[pos-1] && !vis[pos+7] && !vis[pos-7]) return false;
        if(!vis[pos+1] && !vis[pos-1] && vis[pos+7] && vis[pos-7]) return false;
    }
    if(dead(pos+8,vis) || dead(pos+6,vis) || dead(pos-6,vis) || dead(pos-8,vis)) return false;
    return true;
}

int path(string s, int ind, int pos, vector<int> &vis){
    if(pos==42){
        if(ind==s.size()) return 1;
        else return 0;
    }
    if(ind==s.size()) return 0;
    if(!valid(pos,vis)) return 0;
    vis[pos]=1;
    bool ques= (s[ind]=='?');
    int ans=0;
    if((s[ind]=='R' || ques) && pos%7<6 && !vis[pos+1]){
        s[ind]='R';
        ans+=path(s,ind+1,pos+1,vis);
    }
    if((s[ind]=='L' || ques) && pos%7>0 && !vis[pos-1]){
        s[ind]='L';
        ans+=path(s,ind+1,pos-1,vis);
    }
    if((s[ind]=='U' || ques) && pos>=7 && !vis[pos-7]){
        s[ind]='U';
        ans+=path(s,ind+1,pos-7,vis);
    }
    if((s[ind]=='D' || ques) && pos<42 && !vis[pos+7]){
        s[ind]='D';
        ans+=path(s,ind+1,pos+7,vis);
    }
    vis[pos]=0;
    return ans;
}

int main(){
    string s; cin>>s;
    vector<int> vis(49,0);
    int ans= path(s,0,0,vis);
    cout<<ans<<endl;
    return 0;
}