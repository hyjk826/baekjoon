// 2022-12-24
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi tmp(n + 1);
    int cnt{0};
    function<void(int,int,int)> merg = [&](int p, int q, int r){
        int i = p; int j = q + 1; int t = 1;
        while(i <= q && j <= r){
            if(vec[i] <= vec[j])  tmp[t++] = vec[i++];
            else tmp[t++] = vec[j++];
        }
        while(i <= q) tmp[t++] = vec[i++];
        while(j <= r) tmp[t++] = vec[j++];
        i = p; t = 1;
        while(i <= r){
            vec[i++] = tmp[t++];
            cnt++;
            if(cnt == k){
                cout << vec[i - 1];
                exit(0);
            }
        }
    };
    function<void(int, int)> merge_sort = [&](int l, int r){
        if(l < r){
            int mid = (l + r) >> 1;
            merge_sort(l, mid);
            merge_sort(mid + 1, r);
            merg(l, mid, r);
        }
    };
    merge_sort(0, n - 1);
    cout << -1;
}
