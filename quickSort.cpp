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

int partition(vector<int> &A, int l, int r){
    int pivot = A[r];

    int i=l-1, j=l;
    while(j<r){
        if(A[j]<=pivot){
            i++;
            swap(A[i], A[j]);
        }
        j++;
    }
    i++;
    swap(A[i], A[r]);
    return i;
}

void quickSort(vector<int> &A, int l, int r){
    if(l>r){
        return;
    }
    int p = partition(A, l, r);
    quickSort(A, l, p-1);
    quickSort(A, p+1, r);
}

int main(){
    fast;
    int n; cin>>n;
    vector<int> arr(n);
    FOR(i, 0, n){
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    FOR(i, 0, n){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}