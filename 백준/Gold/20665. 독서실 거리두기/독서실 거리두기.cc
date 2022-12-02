// 2022-12-02
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


int main() {
	fastio;
	int n, m, k;
    cin >> n >> m >> k;
    vector<vi> ch(12 * 60 + 1, vi(n + 1));
    vp vec;
    for(int i{0}; i < m; ++i){
        string s, t;
        cin >> s >> t;
        int h1 = stoi(s.substr(0, 2));
        int m1 = stoi(s.substr(2, 2));
        int h2 = stoi(t.substr(0, 2));
        int m2 = stoi(t.substr(2, 2));
        vec.push_back({h1 * 60 + m1 - 540, h2 * 60 + m2 - 1 - 540});
    }   
    sort(vec.begin(), vec.end(), [&](pi a, pi b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        else return a.first < b.first;
    });
    for(int i{0}; i < m; ++i){
        int l = vec[i].first;
        int r = vec[i].second;
        vi A;
        for(int j{1}; j <= n; ++j){
            if(ch[l][j]){
                A.push_back(j);
            }
        }
        if(A.size() == 0){
            for(int j{l}; j <= r; ++j){
                ch[j][1] = 1;
            }
        }
        else{
            vp B;
            if(A.front() != 1){
                B.push_back({1, A.front() - 1});
            }
            for(int j{0}; j < (int)A.size() - 1; ++j){
                int dist = A[j + 1] - A[j];
                if(dist == 1) continue;
                B.push_back({(A[j] + A[j + 1]) / 2, dist / 2});
            }
            if(A.back() != n){
                B.push_back({n, n - A.back()});
            }
            sort(B.begin(), B.end(), [&](pi a, pi b){
                if(a.second == b.second) return a.first < b.first;
                else return a.second > b.second;
            });
            for(int j{l}; j <= r; ++j){
                ch[j][B[0].first] = 1;
            }
        }
    }
    int ans{0};
    for(int i{0}; i < 12 * 60; ++i){
        if(ch[i][k] == 0) ans++;
    }
    cout << ans << "\n";
}
	
