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

#include<bits/stdc++.h>
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
	bool find(const char* s) {
		if (!*s) {
			if (end) return true;
			return false;
		}
		int now = *s - '0';
		if (!ch[now]) return false;
		return ch[now]->find(s + 1);
	}
    void solve(const char* s, int& res, int idx){
        int now = *s - '0';
        if(!*s) return;
        if(ch[now ^ 1]){
            res |= (1 << idx);
            ch[now ^ 1]->solve(s + 1, res, idx - 1);
        }
        else ch[now]->solve(s + 1, res, idx - 1);
    }
};

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> vec[i];
            vec[i] ^= vec[i - 1];
        }
        vs A;
        Trie* root = new Trie;
        for(int i{0}; i <= n; ++i){
            string str;
            for(int j{30}; j >= 0; --j){
                if((vec[i] >> j) & 1) str += '1';
                else str += '0';
            }
            root->insert(str.c_str());
            A.push_back(str);
        }
        int ans{0};
        for(auto& i : A){
            int res{0};
            root->solve(i.c_str(), res, 30);
            ans = max(ans, res);
        }
        cout << ans << "\n";
        root->~Trie();
    }
}
