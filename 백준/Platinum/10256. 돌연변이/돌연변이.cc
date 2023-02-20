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
	Trie* ch[4];
    Trie* fail;
	bool end;
    string str = "ACGT";
	Trie() {
		end = false;
		for (int i = 0; i < 4; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 4; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (*s == '\0') {
			this->end = true;
			return;
		}		
        int now = str.find(*s);
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
    void makeFail(Trie* root){
        queue<Trie*> Q;
        root->fail = root;
        Q.push(root);
        while(!Q.empty()){
            Trie* x = Q.front();
            Q.pop();
            for(int i{0}; i < 4; ++i){
                Trie* nx = x->ch[i];
                if(!nx) continue;
                if(x == root) nx->fail = root;
                else{
                    Trie* dst = x->fail;
                    while(dst != root && !dst->ch[i]){
                        dst = dst->fail;                        
                    }
                    if(dst->ch[i]) dst = dst->ch[i];
                    nx->fail = dst;
                }
                if(nx->fail->end) nx->end = true;
                Q.push(nx);
            }
        }
    }
    void find(const char* s, Trie* root, int& ans){
        Trie* x = root;
        while(1){
            if(*s == '\0') break;
            int nx = str.find(*s);
            while(x != root && !x->ch[nx]){
                x = x->fail;
            }
            if(x->ch[nx]){
                x = x->ch[nx];
            }
            if(x->end){
                ans++;
            }
            s++;
        }
    }
};

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        vs vec;
        Trie* root = new Trie();
        vec.push_back(t);
        for(int i{0}; i < m; ++i){
            for(int j{i + 1}; j < m; ++j){
                reverse(t.begin() + i, t.begin() + j + 1);
                vec.push_back(t);
                reverse(t.begin() + i, t.begin() + j + 1);
            }
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        for(auto& i : vec){
            root->insert(i.c_str());
        }
        root->makeFail(root);
        int ans{0};
        root->find(s.c_str(), root, ans);
        cout << ans << "\n";
        root->~Trie();
    }
}
