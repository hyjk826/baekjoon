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

int n;

int inv(int x){
    if(x >= 3 * n) return x - 3 * n;
    else return x + 3 * n;
}

void addEdge(int a, int b){
    g[a].push_back(b);
}

void addCNF(int a, int b){
    addEdge(inv(a), b);
    addEdge(inv(b), a);
}

int ccw(pl a, pl b, pl c){
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pl, pl> x, pair<pl, pl> y){
    pl a = x.first;
    pl b = x.second;
    pl c = y.first;
    pl d = y.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

struct line{
    pl A, B;
};

int main(){
	fastio;
    cin >> n;
    vector<line> vec(3 * n);
    for(int i{0}; i < 3 * n; ++i){
        cin >> vec[i].A.first >> vec[i].A.second >> vec[i].B.first >> vec[i].B.second;
    }
    for(int i{0}; i < n; ++i){
        addEdge(3 * i, inv(3 * i + 1));
        addEdge(3 * i, inv(3 * i + 2));
        addEdge(3 * i + 1, inv(3 * i));
        addEdge(3 * i + 1, inv(3 * i + 2));
        addEdge(3 * i + 2, inv(3 * i));
        addEdge(3 * i + 2, inv(3 * i + 1));
    }
    for(int i{0}; i < 3 * n; ++i){
        for(int j{i + 1}; j < 3 * n; ++j){
            if(isIntersect({vec[i].A, vec[i].B}, {vec[j].A, vec[j].B})){
                addCNF(i, j);
            }
        }
    }
    for(int i{0}; i < 6 * n; ++i){
        if(d[i] == 0) dfs(i);
    }
    bool ok = true;
    vi ans;
    for(int i{0}; i < 3 * n; ++i){
        if(sn[i] == sn[inv(i)]){
            ok = false;
        }
        if(sn[i] < sn[(inv(i))]){
            ans.push_back(i + 1);
        }
    }
    if(ok){
        cout << ans.size() << "\n";
        for(auto& i : ans) cout << i << " ";
    }
    else cout << -1;
}
