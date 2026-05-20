#include <bits/stdc++.h>

using namespace std;

const int nax = 6e5+5;

int ft[nax];

int n;

void update(int k, int v){
    k++;
    while(k<nax){
        ft[k]+=v;
        k+= k & (-k);
    }
}

int query(int k){
    k++;
    int res =0;
    while(k>0){
        res+=ft[k];
        k-= k & (-k);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>n>>q;
    map<int,int> m;
    vector<int> e(n);
    vector<array<int,3>> qq(q);
    for(auto &x:e)cin>>x,m[x]=0;

    for(int i=0;i<q;i++){
        char c;
        int a,b;
        cin>>c>>a>>b;
        qq[i][0]=c;
        qq[i][1]=a;
        qq[i][2]=b;
    }

    for(auto x:qq)if((char)x[0] == '!')m[x[2]]=0;


    int p=0;
    for(auto &x:m)x.second = p++;//,cout<<x.first<<" "<<x.second<<endl;

    for(int i=0;i<n;i++)update(m[e[i]],1);

    for(int j=0;j<q;j++){
        auto x=qq[j];
        char c=x[0];

        if(c=='!'){
            int xx,v;
            xx=x[1];
            v=x[2];
            xx--;
            update(m[e[xx]],-1);
            e[xx]=v;
            update(m[e[xx]],1);
        }else{
            int a,b;
            a=x[1];
            b=x[2];
            //cout<<a<<" "<<b<<endl;
            a=(*m.lower_bound(a)).second;
            b=(*(--m.upper_bound(b))).second;
            //cout<<a<<" "<<b<<endl;
            cout<<query(b)-( a==0 ?0:query(a-1))<<"\n";
        }
    }

}