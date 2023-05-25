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

vi pre;

struct Trie {
	vector<pair<char, Trie*>> vec;
    Trie* fail;
    int len;
	Trie() {
        len = 0;
	}
	~Trie() {
		vec.clear();
	}
	void insert(const char* s, int sz, Trie* root) {
        Trie* cur = root;
        while(1){
		    if (*s == '\0') {
		    	cur->len = sz;
		    	return;
		    }
            bool ok = false;
            for(auto& i : cur->vec){
                if(i.first == *s){
                    cur = i.second;
                    ok = true; break;
                }
            }
            if(!ok) {
                cur->vec.push_back({*s, new Trie});
                cur = cur->vec.back().second;
            }
            s++;
        }
	}
    void makeFail(Trie* root){
        queue<Trie*> Q;
        root->fail = root;
        Q.push(root);
        while(!Q.empty()){
            Trie* x = Q.front();
            Q.pop();
            for(auto& i : x->vec){
                Trie* nx = i.second;
                if(x == root) nx->fail = root;
                else{
                    Trie* dst = x->fail;
                    while(dst != root){
                        bool ok = false;
                        for(auto& j : dst->vec){                            
                            if(i.first == j.first){
                                ok = true; break;
                            }
                        }
                        if(ok) break;
                        dst = dst->fail;                        
                    }
                    for(auto& j : dst->vec){
                        if(j.first == i.first){
                            dst = j.second; break;
                        }
                    }
                    nx->fail = dst;
                }
                if(nx->fail->len){
                    if(nx->len < nx->fail->len) nx->len = nx->fail->len;
                }
                Q.push(nx);
            }
        }
    }
    bool find(const char* s, Trie* root){
        Trie* x = root;
        int idx{0};
        while(1){
            if(*s == '\0') break;
            while(x != root){
                bool ok = false;
                for(auto& j : x->vec){
                    if(*s == j.first){
                        ok = true; break;
                    }
                }
                if(ok) break;
                x = x->fail;
            }
            for(auto& j : x->vec){
                if(j.first == *s){
                    x = j.second; break;
                }
            }
            if(x->len){
                pre[idx - x->len + 1]++;
                pre[idx + 1]--;
            }
            idx++;
            s++;
        }
        return false;
    }
};

int main(){
	fastio;
    int n, m;
    cin >> n;
    Trie* root = new Trie;
    string str;
    cin >> str;    
    cin >> m;
    for(int i{0}; i < m; ++i){
        string s;
        cin >> s;
        root->insert(s.c_str(), (int)s.size(), root);        
    }
    pre.resize(n + 1);
    root->makeFail(root);
    root->find(str.c_str(), root);
    for(int i{1}; i < n; ++i){
        pre[i] += pre[i - 1];
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        if(pre[i] == 0) ans++;
    }
    cout << ans;
    delete root;
}
