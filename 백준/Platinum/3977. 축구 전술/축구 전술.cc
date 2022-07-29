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
int d[100001]{}; // id
int sccNum{0}; // scc 개수
int sn[100001]; // i가 속한 SCC의 번호
vector<int> graph[100001];
bool finished[100001]; // SCC 성립되면 true
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
	int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i{0}; i < n; ++i){
            graph[i].clear();
            d[i] = 0;
            finished[i] = 0;
        }
        id = 0;
        sccNum = 0;
        SCC.clear();
        for(int i{0}; i < m; ++i){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }
        for(int i{0}; i < n; ++i){
            if(d[i] == 0) dfs(i);
        }
        vi indegree(sccNum);
        for(int i{0}; i < n; ++i){
            for(auto& j : graph[i]){
                if(sn[i] != sn[j]){
                    indegree[sn[j]]++;
                }
            }
        }
        int cnt{0};
        int k{-1};
        for(int i{0}; i < sccNum; ++i){
            if(indegree[i] == 0) {
                cnt++;
                k = i;
            }
        }
        if(cnt == 1){
            for(int i{0}; i < n; ++i){
                if(sn[i] == k) cout << i << "\n";
            }
            cout << "\n";
        }
        else{
            cout << "Confused\n\n";
        }
    }
}

