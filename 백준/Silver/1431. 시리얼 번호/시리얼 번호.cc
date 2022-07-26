// 2022-07-26
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vs vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end(), [&](string a, string b){
        if(a.size() == b.size()){
            int x{0}, y{0};
            for(int i{0}; i < (int)a.size(); ++i){
                if('0' <= a[i] && a[i] <= '9') x += a[i] - '0';
            }
            for(int i{0}; i < (int)b.size(); ++i){
                if('0' <= b[i] && b[i] <= '9') y += b[i] - '0';
            }
            if(x == y){
                return a < b;
            }
            else return x < y;
        }
        else return a.size() < b.size();
    });
    for(auto& i : vec) cout << i << "\n";
}

