// 2022-07-29
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

// 강한 연결 요소
int id{0};
int d[10001]{}; // id
int sccNum; // scc 개수
int sn[10001]; // i가 속한 SCC의 번호
vector<int> graph[10001];
bool finished[10001]; // SCC 성립되면 true
stack<int> s;
vector<vector<int>> SCC;

int dfs(int c) {
	d[c] = ++id; // 정점에 고유 id 할당
	s.push(c); // 스택에 자신을 삽입

	int result = d[c];
	for (int next : graph[c]) {
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
        graph[a].push_back(b);
    }
    for(int i{1}; i <= n; ++i){
        if(d[i] == 0){
            dfs(i);
        }
    }
    sort(SCC.begin(), SCC.end());
    cout << SCC.size() << "\n";
    for(auto& i : SCC){
        for(auto& j : i){
            cout << j << " ";
        }
        cout << "-1\n";
    }
}

