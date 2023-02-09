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

const int sz = 1e5 + 10;
int id{0};
int d[sz]{};
int sccNum; 
int sn[sz]; 
vector<int> g[sz];
bool finished[sz]; 
stack<int> s;

int dfs(int c) {
	d[c] = ++id; 
	s.push(c); 

	int result = d[c];
	for (int next : g[c]) {
		if (d[next] == 0) result = min(result, dfs(next));
		else if (!finished[next]) result = min(result, d[next]);
	}

	if (result == d[c]) {
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			sn[t] = sccNum;
			if (t == c) break;
		}
		sccNum++;
	}
	return result;
}

int n, m;

void init(){
    sccNum = id = 0;
    for(int i{0}; i < 2 * n; ++i){
        d[i] = sn[i] = finished[i] = 0;
        g[i].clear();
    }
}

int inv(int x){
    if(x >= n) return x - n;
    else return x + n;
}

void addEdge(int a, int b){
    g[a].push_back(b);
}

void addCNF(int a, int b){
    addEdge(inv(a), b);
    addEdge(inv(b), a);
}

int main(){
	fastio;
    cin >> n;
    vector<vi> board(n, vi(n));
    vi team(n);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(j == 0) team[i] = board[i][j];
            else board[i][j]--;
        }
    }
    int l{0}, r{n - 1};
    int ans{0};
    while(l <= r){
        init();
        int mid{(l + r) / 2};
        for(int i{0}; i < n; ++i){
            for(int j{mid + 1}; j < n; ++j){
                int a = team[i];
                int b = team[board[i][j]];
                int c = board[i][j];
                if(a == b){
                    addEdge(i, inv(c)); addEdge(c, inv(i));
                    addEdge(inv(i), c); addEdge(inv(c), i);
                }
                else if((a + 1) % 3 == b){
                    addEdge(inv(i), inv(c)); addEdge(c, i);
                }
                else{
                    addEdge(i, c); addEdge(inv(c), inv(i));
                }
            }
        }
        for(int i{0}; i < 2 * n; ++i){
            if(d[i] == 0) dfs(i);
        }
        bool ok = true;
        for(int i{0}; i < n; ++i){
            if(sn[i] == sn[inv(i)]){
                ok = false;
                break;
            }
        }
        if(ok){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans;
}
