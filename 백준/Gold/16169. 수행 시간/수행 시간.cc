// 2022-12-14
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
    int n;
    cin >> n;
    vector<vi> g(n + 2);
    vp vec(n);
    vi degree(n + 1);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        g[vec[i].first].push_back(i);
        degree[vec[i].first]++;
    }
    queue<int> Q;
    vi A(n);
    for(auto& i : g[1]){
        A[i] = vec[i].second;
        Q.push(i);
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        degree[vec[x].first]--;
        for(auto& i : g[vec[x].first + 1]){
            A[i] = max(A[i], A[x] + (i - x) * (i - x) + vec[i].second);
        }
        if(degree[vec[x].first] == 0){
            for(auto& i : g[vec[x].first + 1]){
                Q.push(i);
            }
        }
    }
    cout << *max_element(A.begin(), A.end());
}
	
