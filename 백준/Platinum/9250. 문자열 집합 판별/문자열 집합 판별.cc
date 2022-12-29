// 2022-12-29
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
    Trie* fail;
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
    void makeFail(Trie* root){
        queue<Trie*> Q;
        root->fail = root;
        Q.push(root);
        while(!Q.empty()){
            Trie* x = Q.front();
            Q.pop();
            for(int i{0}; i < 26; ++i){
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
    bool find(const char* s, Trie* root){
        Trie* x = root;
        while(1){
            if(*s == '\0') break;
            int nx = *s - 'a';
            while(x != root && !x->ch[nx]){
                x = x->fail;
            }
            if(x->ch[nx]){
                x = x->ch[nx];
            }
            if(x->end){
                return true;
            }
            s++;
        }
        return false;
    }
};


int main(){
	fastio;
    int n;
    cin >> n;
    Trie* root = new Trie();
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        root->insert(str.c_str());;
    }
    root->makeFail(root);
    int m;
    cin >> m;
    for(int i{0}; i < m; ++i){
        string str;
        cin >> str;
        if(root->find(str.c_str(), root)) cout << "YES\n";
        else cout << "NO\n";
    }
    delete root;
}
