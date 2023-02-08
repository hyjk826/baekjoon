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
    int v;
	int end;
    unordered_map<int, Trie*> next;
	Trie() {
        v = 0;
		end = 0;
	}
	void insert(vi& vec, int idx) {
		if(idx == (int)vec.size()){
            end++;
            return;
        }
        if(!next.count(vec[idx])){
            next[vec[idx]] = new Trie();
            next[vec[idx]]->v = vec[idx];
        }
        next[vec[idx]]->insert(vec, idx + 1);
	}
};


int main(){
	fastio;
    int n, q;
    cin >> n >> q;
    Trie* root = new Trie();
    for(int i{0}; i < n; ++i){
        int m;
        cin >> m;
        vi vec(m);
        for(int j{0}; j < m; ++j){
            cin >> vec[j];
        }
        root->insert(vec, 0);
    }
    vi ans(10001);
    function<int(Trie*)> f = [&](Trie* cur){
        int sum{0};
        int cnt = cur->end;
        for(auto& i : cur->next){
            int k = f(i.second);
            ans[cur->v] += k * sum;
            sum += k;
            cnt += k;
        }
        return cnt;
    };
    f(root);
    while(q--){
        int a;
        cin >> a;
        cout << ans[a] << "\n";
    }
}
