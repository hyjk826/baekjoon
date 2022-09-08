// 2022-09-09
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n, m;
    cin >> n >> m;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int mx{0};
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            for(int k{j + 1}; k < n; ++k){
                int sum = vec[i] + vec[j] + vec[k];
                if(sum <= m){
                    mx = max(mx, sum);
                }
            }
        }
    }
    cout << mx;
}