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
	int cnt[2];
	Trie() {
		cnt[0] = cnt[1] = 0;
		for (int i = 0; i < 2; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (*s == '\0') {
			return;
		}
		int now = *s - '0';
        cnt[now]++;
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
    void erase(const char* s){
        if(*s == '\0') return;
        int now = *s - '0';
        cnt[now]--;
        if(cnt[now] == 0) {
            delete ch[now];
            ch[now] = NULL;
        }
        else ch[now]->erase(s + 1);
    }
    void query(const char* s, int& ans){
        int now = *s - '0';
        if(*s == '\0') return;
        ans <<= 1;
        if(ch[!now]) {
            ans |= 1;
            ch[!now]->query(s + 1, ans);
        }
        else{
            ch[now]->query(s + 1, ans);
        }
    }
};

int main(){
	fastio;
    Trie* root = new Trie;
    bitset<31> bs(0); 
    string str = bs.to_string();
    root->insert(str.c_str());
    int q;
    cin >> q;
    while(q--){
        int op, x;
        cin >> op >> x;
        bitset<31> b(x);
        str = b.to_string();
        if(op == 1){
            root->insert(str.c_str());
        }
        else if(op == 2){
            root->erase(str.c_str());
        }
        else{
            int ans{0};
            root->query(str.c_str(), ans);
            cout << ans << "\n";
        }
    }
}
