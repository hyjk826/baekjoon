// 2022-12-14
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
    int a, b, c;
    cin >> a >> b >> c;
    map<string, int> A, B, C;
    for(int i{0}; i < a; ++i){
        string str; int cost;
        cin >> str >> cost;
        A[str] = cost;
    }
    for(int i{0}; i < b; ++i){
        string str; int cost;
        cin >> str >> cost;
        B[str] = cost;
    }
    for(int i{0}; i < c; ++i){
        string str;
        cin >> str;
        C[str] = 0;
    }
    int n;
    cin >> n;
    vl cost(3);
    vi cnt(3);
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        if(A.count(str)) {
            cost[0] += A[str];
            cnt[0]++;
        }
        if(B.count(str)) {
            cost[1] += B[str];
            cnt[1]++;
        }
        if(C.count(str)) {
            cnt[2]++;
        }
    }
    bool ok = true;
    if(cnt[1] && cost[0] < 20000) ok = false;
    if(cnt[2] > 0){
        if(cost[0] + cost[1] < 50000) ok = false;
    }
    if(cnt[2] > 1) ok = false;
    if(ok) cout << "Okay";
    else cout << "No";
}
	
