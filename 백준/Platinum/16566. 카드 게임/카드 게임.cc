// 2022-12-09
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

vi uni;

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}



int main() {
	fastio;
    int N, M, K;
    cin >> N >> M >> K;
    vi vec(M);
    uni.resize(M);
    for(int i{0}; i < M; ++i){
        cin >> vec[i];
        uni[i] = i;
    }
    sort(vec.begin(), vec.end());
    for(int i{0}; i < K; ++i){
        int a;
        cin >> a;
        int idx = upper_bound(vec.begin(), vec.end(), a) - vec.begin();
        int k = find(idx);
        cout << vec[k] << "\n";
        if(k < N - 1){
            uni[k] = k + 1;
        }
    }
}
	
