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

vector<int> g[501];
vector<int> ch(501);
vector<int> match(501, -1);

bool bipartiteMatching(int x)
{
    for(auto& nx : g[x]){
        if (ch[nx] == 0)
        {
            ch[nx] = 1;
            if (match[nx] == -1 || bipartiteMatching(match[nx]))
            {
                match[nx] = x;
                return true;
            }
        }
    }
    return false;
}

struct st{
    int x, y;
    string str;
};

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i{0}; i < n; ++i) {
        g[i].clear();
    }
    fill(match.begin(), match.end(), -1);
    vector<st> A(n), B(m);
    for(int i{0}; i < n; ++i){
        cin >> A[i].x >> A[i].y >> A[i].str;
        swap(A[i].x, A[i].y);
    }
    for(int i{0}; i < m; ++i){
        cin >> B[i].x >> B[i].y >> B[i].str;
        swap(B[i].x, B[i].y);
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            int l = A[i].y; int r = A[i].y + (int)A[i].str.size() - 1;
            if(l <= B[j].y && B[j].y <= r){
                if(B[j].x <= A[i].x && A[i].x <= B[j].x + (int)B[j].str.size() - 1){
                    if(A[i].str[B[j].y - A[i].y] != B[j].str[A[i].x - B[j].x]){
                        g[i].push_back(j);
                    }
                }
            }
        }
    }
    int cnt{0};
    for(int i{0}; i < n; ++i){
        fill(ch.begin(), ch.begin() + m, 0);
        if(bipartiteMatching(i)) cnt++;
    }
    cout << n + m - cnt << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
