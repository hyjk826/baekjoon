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
    int cnt;
	bool end;
	Trie() {
		end = false;
        cnt = 0;
		for (int i = 0; i < 2; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (*s == '\0') {
			this->end = true;
            this->cnt++;
			return;
		}
		int now = *s - '0';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
        cnt = 0;
        if(ch[0]) cnt += ch[0]->cnt;
        if(ch[1]) cnt += ch[1]->cnt;
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
    void solve(const char* s, const char* t, int& res, int idx){
        int now = *s - '0';
        int now2 = *t - '0';
        if(!*s) return;
        if(now == now2){
            if(now == 1){
                if(ch[now]) res += ch[now]->cnt;
                if(ch[now ^ 1]) ch[now ^ 1]->solve(s + 1, t + 1, res, idx - 1);
            }
            else{
                if(ch[now]) ch[now]->solve(s + 1, t + 1, res, idx - 1);
            }
        }    
        else{
            if(now == 0){
                if(ch[now]) res += ch[now]->cnt;
                if(ch[now ^ 1]) ch[now ^ 1]->solve(s + 1, t + 1, res, idx - 1);
            }
            else{
                if(ch[now]) ch[now]->solve(s + 1, t + 1, res, idx - 1);
            }
            
        }
    }
};

int main(){
	fastio;
    int n, k;
    cin >> n >> k;    
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] ^= vec[i - 1];
    }
    string t;
    for(int i{20}; i >= 0; --i){
        if((k >> i) & 1) t += '1';
        else t += '0';
    }
    Trie* root = new Trie;
    ll ans{0};
    for(int i{0}; i <= n; ++i){
        int res{0};
        string str;
        for(int j{20}; j >= 0; --j){
            if((vec[i] >> j) & 1) str += '1';
            else str += '0';
        }
        root->solve(str.c_str(), t.c_str(), res, 20);
        ans += res;
        root->insert(str.c_str());
    }
    cout << ans;
}
