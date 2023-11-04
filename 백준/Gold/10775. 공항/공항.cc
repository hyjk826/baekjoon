// 2022-07-28
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
    int g, p;
    cin >> g >> p;
    vi vec(p);
    for(int i{0}; i < p; ++i){
        cin >> vec[i];
    }
    set<int> s;
    for(int i{1}; i <= g; ++i){
        s.insert(i);
    }
    for(int i{0}; i < p; ++i){
        auto it = s.upper_bound(vec[i]);
        if(it == s.begin()){
            cout << i;
            return 0;
        }
        else s.erase(prev(it));
    }
    cout << p;
}

