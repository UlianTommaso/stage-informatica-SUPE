#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> e(n);
    for(auto& x:e)cin>>x;
    for(int qq=0;qq<q;qq++){
        char c;
        cin>>c;
        if(c=='!'){
            int x,v;
            cin>>x>>v;
            x--;
            e[x]=v;
        }else{
            int a,b;
            cin>>a>>b;
            int res=0;
            for(int i=0;i<n;i++)res+=(e[i]>=a)&&(e[i]<=b);
            cout<<res<<endl;
        }
    }
}