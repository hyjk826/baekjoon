// 2022-12-27
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
	int words, direct;
	Trie() {
        words = direct = 0;
		for (int i = 0; i < 26; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (*s == '\0') {
            direct++;
			return;
		}
		int now = *s - 'a';
		if (!ch[now]) {
            direct++;
            ch[now] = new Trie;
        }
        words++;
		ch[now]->insert(s + 1);
	}
	ll cnt(bool isRoot = false){
        ll ret = 0;
        if(isRoot || direct > 1) ret = words;
        for(int i{0}; i < 26; ++i){
            if(ch[i]) ret += ch[i]->cnt();
        }
        return ret;
    }
};

int main(){
	fastio;
    cout << fixed << setprecision(2);
    int n;
    while(cin >> n){
        Trie* root = new Trie();
        for(int i{0}; i < n; ++i){
            string str;
            cin >> str;
            root->insert(str.c_str());
        }
        cout << 1.0 * root->cnt(true) / n << "\n";
        root->~Trie();
    }
}
