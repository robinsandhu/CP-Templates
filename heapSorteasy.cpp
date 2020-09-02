#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define pll pair<ll, ll>
#define pii pair<int, int>
#define MP make_pair
#define PB push_back
#define PI 3.141592653589793238

using namespace std;

void max_heapify(ll *arr, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int lar=-1;
    if(l<n&&arr[l]>arr[i])
        lar=l;
    else
        lar=i;
    if(r<n&&arr[r]>arr[lar])
        lar=r;
    if(lar!=i){
        swap(arr[i], arr[lar]);
        max_heapify(arr, n, lar);
    }
}

void heap_sort(ll *arr, int n){
    //building the max heap
    for(int i=n/2-1;i>=0;i--){
        max_heapify(arr, n, i);
    }
    //sorting the heap
    for(int i=n-1;i>0;i--){
        swap(arr[0], arr[i]);

        max_heapify(arr, i, 0);
    }
}

int main(){
    fast;
    ll arr[100];
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    heap_sort(arr, 7);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // vector<int> vec{1,2,3,4,5,6};
    // print(vec);
    return 0;
}
