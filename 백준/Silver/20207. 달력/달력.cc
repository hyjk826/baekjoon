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
    vi cnt(367);
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        cnt[vec[i].second + 1]--;
        cnt[vec[i].first]++;
    }
    for(int i{1}; i <= 365; ++i){
        cnt[i] += cnt[i - 1];
    }
    for(int i{1}; i <= 365; ++i){
        if(cnt[i] != 0 && cnt[i - 1] != 0) cnt[i] = max(cnt[i], cnt[i - 1]);
    }
    sort(vec.begin(), vec.end());
    vp A;
    A.push_back({vec[0].first, vec[0].second});
    int ans{0};
    for(int i{1}; i < (int)vec.size(); ++i){
        if(vec[i].first > A.back().second){
            ans += (A.back().second - A.back().first + 1) * cnt[A.back().second];
            A.push_back({vec[i].first, vec[i].second});
        }
        else{ 
            A.back().second = max(A.back().second, vec[i].second);
        }
    }
    ans += (A.back().second - A.back().first + 1) * cnt[A.back().second];
    cout << ans;
}
	
