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

void merge(vector<ll> &arr, int l, int m, int r){
    int ls = m - l + 1;
    int rs = r - m;
    vector<ll> lft(ls), rgt(rs);
    for(int i=0;i<ls;i++){
        lft[i] = arr[l + i];
    }
    for(int i=0;i<rs;i++){
        rgt[i] = arr[m + i + 1];
    }
    int i=0, j=0, k=l;
    while(i<ls && j<rs){
        if(lft[i]>rgt[j]){
            arr[k]=rgt[j];
            j++;
        }else{
            arr[k]=lft[i];
            i++;
        }
        k++;
    }
    
    while(i<ls){
        arr[k]=lft[i];
        i++; k++;
    }

    while(j<rs){
        arr[k]=rgt[j];
        j++; k++;
    }
}

void mergeSort(vector<ll> &arr, int l, int r){
    if(l>=r){
        return;
    }
    int m = l + (r - l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main(){
    fast;
    vector<ll> arr{10,9,8,7,6,5,4,3,2,1};
    mergeSort(arr, 0, 9);
    for(auto c: arr){
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}