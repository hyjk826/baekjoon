// 2022-11-13
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

bool check_prime(int n){
    if(n == 1) return 0;
    for(int i{2}; i * i <= n; ++i){
        if(n % i == 0) return 0;
    }
    return 1;
}


int main() {
	fastio;
    int a, b;
    cin >> a >> b;
    vi ans;
    vi A;
    A.push_back(2);
    A.push_back(3);
    A.push_back(5);
    A.push_back(7);
    for(int i{1}; i <= 9999; ++i){
        int k{0};
        string str = to_string(i);
        string t = str;
        reverse(t.begin(), t.end());
        k = stoi(str + t);       
        if(check_prime(k)) {
            A.push_back(k);
        }
        if(i < 1000){
            for(char c{'0'}; c <= '9'; ++c){
                str += c;
                k = stoi(str + t);
                if(check_prime(k)) A.push_back(k);        
                str.pop_back();
            }
        }
    }
    sort(A.begin(), A.end());
    // for(auto& i : A){
    //     cout << i << "\n";
    // }
    auto l = lower_bound(A.begin(), A.end(), a);
    auto r = upper_bound(A.begin(), A.end(), b);
    for(auto i{l}; i < r; ++i){
        cout << *i << "\n";
    }
    cout << -1;
}
	

