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
	unordered_map<char, Trie*> mp;
    Trie* fail;
	bool end;
	Trie() {
		end = false;
	}
	~Trie() {
		mp.clear();
	}
	void insert(const char* s) {
		if (*s == '\0') {
			this->end = true;
			return;
		}
		if (!mp.count(*s)) mp[*s] = new Trie;
        mp[*s]->insert(s + 1);
	}
    void makeFail(Trie* root){
        queue<Trie*> Q;
        root->fail = root;
        Q.push(root);
        int cnt{0};
        while(!Q.empty()){
            Trie* x = Q.front();
            Q.pop();            
            cnt++;
            for(auto& i : x->mp){
                Trie* nx = i.second;
                
                if(x == root) {
                    nx->fail = root;
                }
                else{                                        
                    Trie* dst = x->fail;
                    while(dst != root && !dst->mp.count(i.first)){
                        dst = dst->fail;                        
                    }
                    if(dst->mp.count(i.first)) dst = dst->mp[i.first];
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
            while(x != root && !x->mp.count(*s)){
                x = x->fail;
            }
            if(x->mp.count(*s)){
                x = x->mp[*s];
            }
            if(x->end){
                x = root;
                ans++;
            }
            s++;
        }
    }
};

int main(){
	fastio;
    while(1){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        Trie* root = new Trie;
        string str;
        for(int i{0}; i < n; ++i){            
            cin >> str;
            root->insert(str.c_str());
        }
        root->makeFail(root);
        int ans{0};
        getline(cin, str);
        for(int i{0}; i < m; ++i){
            getline(cin, str);
            root->find(str.c_str(), root, ans);
        }
        cout << ans << "\n"; 
        delete root;
    }
}
