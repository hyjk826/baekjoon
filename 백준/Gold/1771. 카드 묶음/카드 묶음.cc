// 2022-08-17
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

struct st{
    int l, r, num;
};

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    vi index(n + 1);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vector<st> A;
    vi ans;
    for(int i{0}; i < n; ++i){
        if(A.empty()) A.push_back({vec[i], vec[i], i});
        else{
            A.push_back({vec[i], vec[i], i});
            while(A.size() >= 2){
                auto X = A.back();
                auto Y = A[(int)A.size() - 2];
                if(Y.r + 1 == X.l){
                    A.pop_back();
                    A.pop_back();
                    A.push_back({Y.l, X.r, X.num});
                    ans.push_back(Y.num);
                }
                else if(X.r + 1 == Y.l){
                    A.pop_back();
                    A.pop_back();
                    A.push_back({X.l, Y.r, X.num});
                    ans.push_back(Y.num);
                }
                else break;
            }
        }
    }
    for(auto& i : ans){
        cout << i + 1 << "\n";
    }
    
}