#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define PI 3.141592653589793238

using namespace std;

struct Edge{
    int l, r;
    double wt;
};

struct Subsets{
    int parent;
    ll rank;
    Subsets(): parent{-1}, rank{1} {}
};

int find(Subsets sub[],int i){
    if(sub[i].parent==-1){
        return i;
    }else{
        int x = find(sub, sub[i].parent);
        sub[i].parent = x;
        return x;
    }
}

void unionD(Subsets sub[], int x, int y){
    int xset = find(sub, x);
    int yset = find(sub, y);

    if(xset!=yset){
        if(sub[xset].rank<sub[yset].rank){
            sub[xset].parent = yset;
            sub[yset].rank += sub[xset].rank;
        }else{
            sub[yset].parent = xset;
            sub[xset].rank += sub[yset].rank;
        }
    }
}

int comp(const Edge &lhs, const Edge &rhs){
    return lhs.wt < rhs.wt;
}

int main(){
    fast;
    int v; cin>>v;
    int m; cin>>m;
    vector<Edge> edges(m);
    FOR(i, 0, m){
        cin>>edges[i].l>>edges[i].r>>edges[i].wt;
    }

    Subsets sub[v+1];

    vector<Edge> res;

    sort(edges.begin(), edges.end(), comp);

    int j=0;
    while(res.size()<v-1 && j<edges.size()){
        int xset = find(sub, edges[j].l);
        int yset = find(sub, edges[j].r);

        if(xset!=yset){
            res.PB(edges[j]);
            unionD(sub, edges[j].l, edges[j].r);
        }
        j++;
        //else continue
    }

    //print the edges
    FOR(i, 0, (int)res.size()){
        cout<<res[i].l<<" "<<res[i].r<<"--"<<res[i].wt<<endl;
    }

    return 0;
}