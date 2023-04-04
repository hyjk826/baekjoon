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
    void solve(const char* s, int& res, int idx){
        int now = *s - '0';
        if(!*s) return;
        if(ch[now]){
            ch[now]->solve(s + 1, res, idx - 1);
        }
        else {
            res |= (1 << idx);
            ch[now^1]->solve(s + 1, res, idx - 1);
        }
    }
};

int main(){
	fastio;
    int n;
    cin >> n;
    vi A(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    vs vec(n);
    for(int i{0}; i < n; ++i){
        string str;
        for(int j{29}; j >= 0; --j){
            if((A[i] >> j) & 1) str += '1';
            else str += '0';
        }
        vec[i] = str;
    }
    ll ans{0};
    function<void(int,int,int)> f = [&](int L, int l, int r){
        if(L == -1 || l == r) return;
        int m = l;
        while(m <= r && ((A[m] >> L) & 1)) m++;
        Trie* root = new Trie();
        for(int i{m}; i <= r; ++i){
            root->insert(vec[i].c_str());
        }
        int mn{MAX};
        if(m <= r){
            for(int i{l}; i < m; ++i){
                int res{0};
                root->solve(vec[i].c_str(), res, 29);
                mn = min(mn, res);
            }
        }
        root->~Trie();
        if(mn != MAX) ans += mn;
        if(m - 1 >= l) f(L - 1, l, m - 1);
        if(m <= r) f(L - 1, m, r);
    };
    f(29, 0, n - 1);
    cout << ans;
}
