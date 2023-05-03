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
    vi ch(1000001);
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        ch[a]++;
        ch[b]--;
    }
    for(int i{1}; i <= 1000000; ++i){
        ch[i] += ch[i - 1];
    }
    for(int i{1}; i <= 1000000; ++i){
        ch[i] += ch[i - 1];
    }
    auto it = lower_bound(ch.begin(), ch.end(), k);
    if(it != ch.end() && *it == k){
        cout << 0 << " " << it - ch.begin() + 1; return 0;
    }
    for(int i{0}; i <= 1000000; ++i){
        it = lower_bound(ch.begin(), ch.end(), ch[i] + k);
        if(it != ch.end() && *it == ch[i] + k){
            cout << i + 1 << " " << it - ch.begin() + 1; return 0;
        }
    }
    cout << 0 << " " << 0;
}
