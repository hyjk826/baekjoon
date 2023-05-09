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

vi Z_algorithm(string str){
    int l{0}, r{0};
    vi z((int)str.size());
    for(int i{1}; i < (int)str.size(); ++i){
        if(i > r){
            l = r = i;
            while(r < (int)str.size() && str[r - l] == str[r]) r++;
            z[i] = r - l; r--;
        }
        else{
            int k = i - l;
            if(z[k] < r - i + 1) z[i] = z[k];
            else{
                l = i;
                while(r < (int)str.size() && str[r - l] == str[r]) r++;
                z[i] = r - l; r--;
            }
        }
    }
    return z;
}

int main(){
	fastio;
    int n; string str;
    cin >> n >> str;
    auto Z = Z_algorithm(str);
    vi ans(n, -1);
    vi jump(n);
    for(int i{n - 1}; i >= 1; --i){
        if(Z[i]){
            for(int j{i}; j < i + Z[i];){
                if(ans[j] != -1) {
                    j += jump[j];
                    continue;
                }
                jump[j] = Z[i] - (j - i);                
                ans[j] = i;
                j++;
            }
        }
    }
    for(auto& i : ans){
        if(i == -1) i = 0;
    }
    cout << accumulate(ans.begin(), ans.end(), 0LL);
}
