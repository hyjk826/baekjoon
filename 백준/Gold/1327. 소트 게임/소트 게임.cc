// 2022-11-25
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

int main() {
	fastio;	
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    queue<vi> Q;
    Q.push(vec);
    map<vi, int> mp;
    mp[vec] = 0;
    while(!Q.empty()){
        vi v =Q.front();
        int a= mp[v];
        Q.pop();
        for(int i{0}; i + k - 1 < n; ++i){
            reverse(v.begin() + i, v.begin() + i + k);
            if(!mp.count(v)) {
                mp[v] = a + 1;
                Q.push(v);
            }
            reverse(v.begin() + i, v.begin() + i + k);
        }
    }
    vi A;
    for(int i{1}; i <= n; ++i) A.push_back(i);
    if(mp.count(A)) cout << mp[A];
    else cout << -1;
}
	
