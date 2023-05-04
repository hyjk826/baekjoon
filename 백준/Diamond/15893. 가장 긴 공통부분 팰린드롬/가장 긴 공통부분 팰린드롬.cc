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

vector<vi> A(50);

vi manacher(string& str){
    string s;
    for(int i{0}; i < (int)str.size(); ++i){
        s += '#';
        s += str[i];
    }
    s += '#';
    int n = (int)s.size();
    int r{0}, p{0};
    vi A(n);
    for(int i{0}; i < n; ++i){
        if(i <= r) A[i] = min(r - i, A[2 * p - i]);
        else A[i] = 0;
        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < n && s[i - A[i] - 1] ==s[i + A[i] + 1]) A[i]++;
        if(r < i + A[i]){
            r = i + A[i];
            p = i;
        }
    }
    return A;
}

// 0_based
bool is_palin(int l, int r, int idx){
    if(A[idx][l + r + 1] >= r - l + 1) return true;
    else return false;
}

const ll p1 = 179, mod1 = 1e9 - 63;
const ll p2 = 917, mod2 = 1e9 + 7;

const int sz = 1e6 + 10;

ll pw1[sz], pw2[sz];
vector<vl> ha1(50);
vector<vl> ha2(50);

void power(){
    pw1[0] = pw2[0] = 1;
    for(int i{1}; i < sz; ++i){
        pw1[i] = pw1[i - 1] * p1 % mod1;
        pw2[i] = pw2[i - 1] * p2 % mod2;
    }
}

void hashing(string& str, int idx){
    int n = (int)str.size();
    ha1[idx].resize(n + 1);
    ha2[idx].resize(n + 1);
    for(int i{n - 1}; i >= 0; --i) ha1[idx][i] = (ha1[idx][i + 1] * p1 + str[i]) % mod1;
    for(int i{n - 1}; i >= 0; --i) ha2[idx][i] = (ha2[idx][i + 1] * p2 + str[i]) % mod2;
}

ll substr(int l, int r, int idx){
    ll r1 = ha1[idx][l] - ha1[idx][r + 1] * pw1[r - l + 1]; r1 %= mod1; if(r1 < 0) r1 += mod1;
    ll r2 = ha2[idx][l] - ha2[idx][r + 1] * pw2[r - l + 1]; r2 %= mod2; if(r2 < 0) r2 += mod2;
    return (r1 << 32 | r2);
}

// {
//     if((i & 1)) s = i/2-dp[i]/2, e = i/2+dp[i]/2;
//     else{
//         s = (i - 1) / 2;
//         e = (i + 1) / 2;
//         s -= dp[i] / 2 - 1;
//         e += dp[i] / 2 - 1;
//     }
// }


int main(){
    power();
	fastio;
    int n;
    cin >> n;
    int mn{MAX};
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        hashing(vec[i], i);
        A[i] = manacher(vec[i]);
        mn = min(mn, (int)vec[i].size());
    }    
    set<pl> st;
    for(int i{0}; i < n; ++i){
        set<pl> temp;
        for(int j{0}; j < (int)A[i].size(); ++j){
            if(A[i][j] == 0) continue;
            int s, e;
            if(j & 1) s = j / 2 - A[i][j] / 2, e = j / 2 + A[i][j] / 2;
            else{
                s = (j - 1) / 2;
                e = (j + 1) / 2;
                s -= A[i][j] / 2 - 1;
                e += A[i][j] / 2 - 1;
            }  
            if(i == 0){
                while(s <= e){
                    ll k = substr(s, e, i);
                    temp.insert({k, e - s + 1});
                    s++;
                    e--;
                }   
            }
            else{
                while(s <= e){
                    ll k = substr(s, e, i);
                    if(st.count({k, e - s + 1})){
                        temp.insert({k, e - s + 1});                      
                    }
                    s++;
                    e--;
                }
            }
        }
        swap(st, temp);
        if(st.empty()) break;
    }
    ll ans{0};
    for(auto& i : st) ans = max(ans, i.second);
    cout << ans;
}
