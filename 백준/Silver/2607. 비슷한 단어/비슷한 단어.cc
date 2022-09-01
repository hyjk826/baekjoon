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

int main() {
	fastio;
    int n;
    cin >> n;
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        sort(vec[i].begin(), vec[i].end());
    }
    int ans{0};
    vi cnt(26);
    for(int i{0}; i < (int)vec[0].size(); ++i){
        cnt[vec[0][i] - 'A']++;
    }
    for(int i{1}; i < n; ++i){
        vi cnt2(26);
        for(int j{0}; j < (int)vec[i].size(); ++j){
            cnt2[vec[i][j] - 'A']++;
        }
        int a{0};
        for(int j{0}; j < 26; ++j){
            if(cnt[j] == cnt2[j]) continue;
            a += abs(cnt[j] - cnt2[j]);
        }   
        if(a <= 1){
            ans++;
            continue;
        }
        if(vec[i].size() == vec[0].size()){
            vi A;
            for(int j{0}; j < 26; ++j){
                if(cnt[j] == cnt2[j]) continue;
                A.push_back(cnt[j] - cnt2[j]);
            }
            if(A.size() != 2) continue;
            sort(A.begin(), A.end());
            if(A[0] == -1 && A[1] == 1) ans++;
        }
    }
    cout << ans;
}