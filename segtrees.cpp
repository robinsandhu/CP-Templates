#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PB push_back
#define MP make_pair
#define FOR(i , a, b) for(int i=a;i<b;i++)
#define PI 3.141592653589793238
#define MXN 1000
using namespace std;

int n;
vector<ll> segTree(4*MXN);

void buildSegTree(vector<ll> &arr, int v, int l, int r){
    if(l==r){
        segTree[v]=arr[l];
    }else{
        int mid=(l+r)/2;
        buildSegTree(arr, 2*v, l, mid);
        buildSegTree(arr, 2*v+1, mid+1, r);
        segTree[v]=segTree[2*v]+segTree[2*v+1];
    }
}

ll sumQuery(int v, int tl, int tr, int l, int r){
    if(l>r){
        return 0;
    }
    if(l==tl&&r==tr){
        return segTree[v];
    }
    int tm=(tl+tr)/2;
    return sumQuery(2*v, tl, tm, l, min(r, tm)) + sumQuery(2*v+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, ll new_val){
    if(tl==tr){
        segTree[v]=new_val;
    }else{
        int tm=(tl+tr)/2;
        if(pos<=tm){
            update(2*v, tl, tm, pos, new_val);
        }else{
            update(2*v+1, tm+1, tr, pos, new_val);
        }
        segTree[v]=segTree[2*v]+segTree[2*v+1];
    }
}

int main(){
    fast;
    cin>>n;
    vector<ll> arr(n);
    FOR(i, 0, n){
        cin>>arr[i];
    }
    buildSegTree(arr, 1, 0, n-1);
    int u, v; cin>>u>>v;
//    update(1, 0, n-1, 4, 6);
    cout<<sumQuery(1, 0, n-1, u, v)<<endl;
	return 0;
}