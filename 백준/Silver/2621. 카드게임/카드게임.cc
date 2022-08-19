// 2022-08-19
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
	vector<pair<char, int> > vec(5);
    vi cnt(10);
    int mx{0};
    int ans{0};
    for(int i{0}; i < 5; ++i){
        cin >> vec[i].first >> vec[i].second;
        cnt[vec[i].second]++;
        mx = max(mx, vec[i].second);
    }
    sort(vec.begin(), vec.end());
    if(vec[0].first == vec[4].first){
        bool flag = true;
        for(int i{0}; i < 4; ++i){
            if(vec[i + 1].second == vec[i].second + 1) continue;
            flag = false;
        }
        if(flag) ans = max(ans, 900 + mx);
        else ans = max(ans, 600 + mx);
    }
    for(int i{1}; i < 10; ++i){
        if(cnt[i] == 4){
            ans = max(ans, 800 + i);
        }
    }
    for(int i{1}; i < 10; ++i){
        for(int j{i + 1}; j < 10; ++j){
            if(cnt[i] == 3 && cnt[j] == 2){
                ans = max(ans, 10 * i + j + 700);
            }
            if(cnt[i] == 2 && cnt[j] == 3){
                ans = max(ans, 10 * j + i + 700);
            }
        }
    }
    bool flag = true;
    vi A;
    for(int i{0}; i < 5; ++i){
        A.push_back(vec[i].second);
    }
    sort(A.begin(), A.end());
    for(int i{0}; i < 4; ++i){
        if(A[i + 1] == A[i] + 1) continue;
        flag = false;
    }
    if(flag){
        ans = max(ans, mx + 500);
    }
    for(int i{1}; i < 10; ++i){
        if(cnt[i] == 3){
            ans = max(ans, i + 400);
        }
    }
    for(int i{1}; i < 10; ++i){
        for(int j{i + 1}; j < 10; ++j){
            if(cnt[i] == cnt[j] && cnt[i] == 2){
                ans = max(ans, j * 10 + i + 300);
            }
        }
    }
    for(int i{1}; i < 10; ++i){
        if(cnt[i] == 2){
            ans = max(ans, 200 + i);
        }
    }
    ans = max(ans, mx + 100);
    cout << ans;
}