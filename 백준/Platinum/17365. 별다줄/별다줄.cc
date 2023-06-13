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
	void insert(string& str, int idx) {
        if(idx) cnt++;
		if (idx == (int)str.size()) {
			this->end = true;
			return;
		}
		int now = str[idx] - 'a';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(str, idx + 1);
	}
	void find(string& str,  vi& v, int idx) {
        if(idx) v.push_back(cnt);
		if (idx == (int)str.size()) return;
		int now = str[idx] - 'a';
		if (!ch[now]) return;
		ch[now]->find(str, v, idx + 1);
	}
};




void solve(){
    int n;
    cin >> n;
    vs vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    Trie* root = new Trie;
    for(int i{0}; i < n; ++i){
        root->insert(vec[i], 0);
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
