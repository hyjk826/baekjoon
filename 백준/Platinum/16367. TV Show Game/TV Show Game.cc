// 2022-12-24
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


int id{0};
int d[10001]{};
int sccNum; 
int sn[10001]; 
vector<int> g[10001];
bool finished[10001]; 
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

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    function<int(int)> inv = [&](int x){
        if(x > n) return x - n;
        return x + n;
    };
    function<void(int,int)> addEdge = [&](int a, int b){
        g[a].push_back(b);
    };
    function<void(int, int)> addCNF = [&](int s, int e){
        if(s < 0) s = inv(-s);
        if(e < 0) e = inv(-e);
        addEdge(inv(s), e);
        addEdge(inv(e), s);
    };
    for(int i{0}; i < m; ++i){
        vi A(3);
        vc B(3);
        for(int j{0}; j < 3; ++j){
            cin >> A[j] >> B[j];
            if(B[j] == 'B') A[j] *= -1;
        }
        for(int j{0}; j < 3; ++j){
            addCNF(A[j], A[(j + 1) % 3]);
        }
    }
    for(int i{1}; i <= 2 * n; ++i){
        if(d[i] == 0) dfs(i);
    }
    string ans;
    for(int i{1}; i <= n; ++i){
        if(sn[i] < sn[inv(i)]) ans += 'R';
        else if(sn[i] > sn[inv(i)]) ans += 'B';
        else{
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}
