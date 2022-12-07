// 2022-12-07
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
int d[200001]{}; // id
int sccNum; // scc 개수
int sn[200001]; // i가 속한 SCC의 번호
vector<vi> g((int)2e5 + 1);
bool finished[200001]; // SCC 성립되면 true
stack<int> s;
vector<vector<int>> SCC;

int dfs(int c) {
	d[c] = ++id; // 정점에 고유 id 할당
	s.push(c); // 스택에 자신을 삽입

	int result = d[c];
	for (int next : g[c]) {
		// 아직 방문하지 않은 정점이면
		if (d[next] == 0) result = min(result, dfs(next));
		// 방문은 했으나 아직 SCC로 성립하지 않은 정점이면
		else if (!finished[next]) result = min(result, d[next]);
	}

	// 자신과 자신의 자식 정점들이 갈 수 있는 가장 높은 정점이 자신일 경우 SCC 추출
	if (result == d[c]) {
		vector<int> scc;
		// 스택에서 자신이 나올 때까지 pop
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			sn[t] = sccNum;
			if (t == c) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc); // SCC 추출
		sccNum++;
	}
	return result;
}

int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i{1}; i <= n; ++i){
        if(d[i] == 0) dfs(i);
    }
    vector<vi> g2(sccNum);
    vi degree(sccNum);
    for(int i{1}; i <= n; ++i){
        for(auto& j : g[i]){
            if(sn[i] != sn[j]){
                g2[sn[i]].push_back(sn[j]);
                degree[sn[j]]++;
            }
        }
    }
    queue<int> Q;
    int k{-1};
    for(int i{0}; i < sccNum; ++i){
        if(degree[i] == 0) {
            Q.push(i);
            k = i;
        }
    }
    if(Q.size() == 1){
        vi A;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            A.push_back(x);
            int cnt{0};
            for(auto& i : g2[x]){
                degree[i]--;
                if(degree[i] == 0){
                    Q.push(i);
                    cnt++;
                }                
            }
            if(cnt >= 2){
                A.clear();
                break;
            }
        }
        if(A.size() == sccNum){
            vi ans;
            for(int i{1}; i <= n; ++i){
                if(sn[i] == k){
                    ans.push_back(i);
                }
            }
            cout << ans.size() << "\n";
            for(auto& i : ans) cout << i << " ";
        }
        else cout << 0;
    }
    else cout << 0;
}
	
