// 2022-08-31
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
    set<int> s;
    s.insert(1);
    s.insert(2);
    while(1){
        auto it = prev(s.end());
        int a = *it;
        it--;
        int b = *it;
        if(a + b > (int)1e9) break;
        s.insert(a + b);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi ans;
        while(n){
            auto it = s.lower_bound(n);
            if(it == s.end() || *it > n) it--;
            ans.push_back(*it);
            n -= *it;
        }
        reverse(ans.begin(), ans.end());
        for(auto& i : ans){
            cout << i << " ";
        }
        cout << "\n";
    }
}

