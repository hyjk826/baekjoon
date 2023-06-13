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

struct Trie {
	Trie* ch[26];
	bool end;
    int cnt{0};
	Trie() {
		end = false;
		for (int i = 0; i < 26; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}
};

void solve(){
    int n;
    cin >> n;
    vs vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    Trie* root = new Trie;
    for(int i{0}; i < n; ++i){
        Trie* cur = root;
        for(int j{0}; j < (int)vec[i].size(); ++j){
            int now = vec[i][j] - 'a';
            if(!cur->ch[now]) cur->ch[now] = new Trie;
            cur = cur->ch[now];
            cur->cnt++;
        }
    }
    string str;
    cin >> str;
    vl dp((int)str.size() + 1);
    dp.back() = 1;
    for(int i{(int)str.size() - 1}; i >= 0; --i){
        Trie* cur = root;
        for(int j{i}; j < (int)str.size(); ++j){
            int now = str[j] - 'a';
            if(!cur->ch[now]) break;
            cur = cur->ch[now];
            dp[i] = (dp[i] + dp[j + 1] * cur->cnt) % MOD;
        }
    }
    cout << dp[0];
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}