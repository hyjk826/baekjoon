// 2023-01-15
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

char f(int n){
    if(n < 10) return char('0' + n);
    else return char('A' + n - 10);
}



int main(){
	fastio;
    int n;
    cin >> n;
    vector<vi> g;
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        reverse(vec[i].begin(), vec[i].end());
    }
    for(int i{0}; i < 36; ++i){
        vi A(100);
        if(i < 10){
            for(int j{0}; j < n; ++j){
                for(int k{0}; k < (int)vec[j].size(); ++k){
                    if(vec[j][k] == char('0' + i)){
                        A[k] += 35 - i;
                    }
                }
            }
        }
        else{
            for(int j{0}; j < n; ++j){
                for(int k{0}; k < (int)vec[j].size(); ++k){
                    if(vec[j][k] == char('A' + i - 10)){
                        A[k] += 35 - i;
                    }
                }
            }
        }
        for(int j{0}; j < 99; ++j){
            if(A[j] >= 36){
                A[j + 1] += A[j] / 36;
                A[j] %= 36;
            }
        }
        A.back() = i;
        reverse(A.begin(), A.begin() + 99);
        g.push_back(A);
    }
    set<char> st;
    sort(g.rbegin(), g.rend());
    int k;
    cin >> k;
    for(int i{0}; i < k; ++i){
        st.insert(f(g[i].back()));
    }
    for(int i{0}; i < n; ++i){
        for(auto& j : vec[i]){
            if(st.count(j)) j = 'Z';
        }
    }
    vi A(100);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < (int)vec[i].size(); ++j){
            if(vec[i][j] >= '0' && vec[i][j] <= '9'){
                A[j] += vec[i][j] - '0';
            }
            else A[j] += vec[i][j] - 'A' + 10;
        }
    }
    for(int i{0}; i < 99; ++i){
        if(A[i] >= 36){
            A[i + 1] += A[i] / 36;
            A[i] %= 36;
        }
    }
    string ans;
    while(A.back() == 0) A.pop_back();
    for(int i{0}; i < (int)A.size(); ++i){
        ans += f(A[i]);
    }
    if(ans.empty()){
        cout << 0 << "\n";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
