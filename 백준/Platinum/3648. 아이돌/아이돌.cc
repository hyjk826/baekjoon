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
int d[3001]{};
int sccNum; 
int sn[3001]; 
vector<int> graph[3001];
bool finished[3001]; 
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
    while(cin >> n >> m){
        // X, ~X
        id = sccNum = 0;
        SCC.clear();
        for(int i{1}; i <= 2 * n; ++i){
            graph[i].clear();
            finished[i] = 0;
            sn[i] = 0;
            d[i] = 0;
        }
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
        bool ok = true;
        for(int i{1}; i <= 2 * n - 1; i += 2){
            if(sn[i] == sn[i + 1]){
                ok = false;
                break;
            }
        }   
        if(ok && sn[1] < sn[2]) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}
	

