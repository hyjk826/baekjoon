// 2022-09-01
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

int n;
vi vec(10);
vi ch(10);
int ans{0};

void dfs(int L, int sum){
    if(L == n - 2){
        ans = max(ans, sum);
    }
    else{
        for(int i{1}; i < n - 1; ++i){
            if(ch[i] == 0){
                int a, b;
                for(int j{i - 1}; j >= 0; --j){
                    if(ch[j] == 0){
                        a = vec[j];
                        break;
                    }
                }
                for(int j{i + 1}; j < n; ++j){
                    if(ch[j] == 0){
                        b = vec[j];
                        break;
                    }
                }
                ch[i] = 1;
                dfs(L + 1, sum + a * b);
                ch[i] = 0;
            }
        }
    }
}
int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    dfs(0, 0);
    cout << ans;
}

