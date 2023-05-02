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
	Trie() {
		end = false;
		for (int i = 0; i < 26; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (*s == '\0') {
			this->end = true;
			return;
		}
		int now = *s - 'a';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
	bool find(const char* s) {
		if (!*s) {
			return true;
		}
		int now = *s - 'a';
		if (!ch[now]) return false;
		return ch[now]->find(s + 1);
	}
};

int main(void) {
	Trie* root = new Trie;
    int n, m;
    cin >> n >> m;
	for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        root->insert(str.c_str());
    }
    int ans{0};
    for(int i{0}; i < m; ++i){
        string str;
        cin >> str;
        if(root->find(str.c_str())) ans++;
    }
    cout << ans;
}
