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

int main(){
    fast;
    Subsets sub[10];
    unionD(sub, 0, 1);
    unionD(sub, 1, 2);
    unionD(sub, 4, 5);
    unionD(sub, 7, 5);
    FOR(i, 0, 10){
        cout<<sub[i].parent<<" ";
    }
    cout<<endl;
    return 0;
}