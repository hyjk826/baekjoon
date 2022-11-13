// 2022-11-13
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int id{0};
int d[30000]{}; // id
int sccNum; // scc 개수
int sn[30000]; // i가 속한 SCC의 번호
vector<int> graph[30000];
bool finished[30000]; // SCC 성립되면 true
stack<int> s;
vector<vector<int>> SCC;

int dfs(int c) {
	d[c] = ++id; 
	s.push(c); 

	int result = d[c];
	for (int next : graph[c]) {
		if (d[next] == 0) result = min(result, dfs(next));
		else if (!finished[next]) result = min(result, d[next]);
	}

	if (result == d[c]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			sn[t] = sccNum;
			if (t == c) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc); 
		sccNum++;
	}
	return result;
}

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b, na, nb;
        cin >> a >> b;
        if(a < 0){
            a = (-a) * 2;
            na = a - 1;
        }
        else{
            a = a * 2 - 1;
            na = a + 1;
        }
        if(b < 0){
            b = (-b) * 2;
            nb = b - 1;
        }
        else{
            b = b * 2 - 1;
            nb = b + 1;
        }
        graph[na].push_back(b);
        graph[nb].push_back(a);
    }
    for(int i{1}; i <= 2 * n; ++i){
        if(d[i] == 0){
            dfs(i);
        }
    }
    for(int i{1}; i <= 2 * n - 1; i += 2){
        if(sn[i] == sn[i + 1]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}
	

