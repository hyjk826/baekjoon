// 2022-07-16
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define vs vector<string>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    vs vec(4);
    for(int i{0}; i < 4; ++i){
        cin >> vec[i];
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        a--;
        vi dir(4);
        dir[a] = b;
        for(int i{a - 1}; i >= 0; --i){
            if(vec[i][2] != vec[i + 1][6]){
                dir[i] = dir[i + 1] * -1;
            }
        }
        for(int i{a + 1}; i < 4; ++i){
            if(vec[i][6] != vec[i - 1][2]){
                dir[i] = dir[i - 1] * -1;
            }
        }
        for(int i{0}; i < 4; ++i){
            if(dir[i] == 0) continue;
            if(dir[i] == -1){
                rotate(vec[i].begin(), vec[i].begin() + 1, vec[i].end());
            }
            else{
                rotate(vec[i].rbegin(), vec[i].rbegin() + 1, vec[i].rend());
            }
        }
    }
    int ans{0};
    vi score = {1, 2, 4, 8};
    for(int i{0}; i < 4; ++i){
        if(vec[i][0] == '1') ans += score[i];
    }
    cout << ans;
}
