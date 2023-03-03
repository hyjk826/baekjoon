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

vi A;

vi manacher(string str){
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
bool is_palin(int l, int r){
    if(A[l + r + 1] >= r - l + 1) return true;
    else return false;
}



int main(){
	fastio;
    int n;
    cin >> n;
    string str;
    cin >> str;
    A = manacher(str);
    int idx{n - 1};
    for(int i{0}; i < n; ++i){
        if(is_palin(i, n - 1)){
            cout << i; return 0;
        }
    }
}
