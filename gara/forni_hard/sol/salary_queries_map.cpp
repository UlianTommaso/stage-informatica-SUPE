#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n,q;
    cin>>n>>q;
    vector<int> e(n);
    multiset<int> v;
    for(auto& x:e)cin>>x,v.insert(x);
    for(int qq=0;qq<q;qq++){
        char c;
        cin>>c;
        if(c=='!'){
            int x,vv;
            cin>>x>>vv;
            x--;
            v.erase(v.find(e[x]));
            e[x]=vv;
            v.insert(vv);
        }else{
            int a,b;
            cin>>a>>b;
            auto pos = v.lower_bound(a);
            int res=0;
            while(pos!=v.end() && (*pos) <=b)pos++,res++;
            cout<<res<<'\n';
        }
    }
}