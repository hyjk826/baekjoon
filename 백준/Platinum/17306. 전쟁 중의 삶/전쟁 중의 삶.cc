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
	Trie* ch[2];
	bool end;
	Trie() {
		end = false;
		for (int i = 0; i < 2; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (*s == '\0') {
			this->end = true;
			return;
		}
		int now = *s - '0';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
};

int main(){
	fastio;
    Trie* root = new Trie();
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        ll a;
        cin >> a;
        string str;
        while(a){
            str += char('0' + a % 2);
            a /= 2;
        }
        reverse(str.begin(), str.end());
        root->insert(str.c_str());
    }
    ll ans{0};
    function<int(Trie*)> dfs = [&](Trie* cur){
        ll ret{0};
        if(cur->end) ret++;
        for(int i{0}; i < 2; ++i){
            if(cur->ch[i] == NULL) continue;
            ret += dfs(cur->ch[i]);
        }
        if(1 <= ret && ret <= n - 1) ans++;
        return ret;
    };
    dfs(root);
    cout << ans + 1;
}
