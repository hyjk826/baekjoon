// 2022-12-07
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
	int n, k;
    cin >> n >> k;
    vector<vi> vec(n);
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        vec[i].push_back(a);
        vec[i].push_back(b);
    }
    if(k <= 2 * n){
        for(int i{0}; i < k; ++i){
            vector<vi> A(n);
            for(int j{0}; j < n; ++j){
                if(j == 0){
                    A[0].push_back(max(vec[j][0], vec[j][1]));
                    A[n - 1].push_back(min(vec[j][0], vec[j][1]));
                }
                else{
                    A[j - 1].push_back(max(vec[j][0], vec[j][1]));
                    A[j].push_back(min(vec[j][0], vec[j][1]));
                }
            }
            swap(A, vec);
        }
        for(int i{0}; i < n; ++i){
            cout << min(vec[i][0], vec[i][1]) << " " << max(vec[i][0], vec[i][1]) << "\n";
        }
    }
    else{
        for(int i{0}; i < 2 * n; ++i){
            vector<vi> A(n);
            for(int j{0}; j < n; ++j){
                if(j == 0){
                    A[0].push_back(max(vec[j][0], vec[j][1]));
                    A[n - 1].push_back(min(vec[j][0], vec[j][1]));
                }
                else{
                    A[j - 1].push_back(max(vec[j][0], vec[j][1]));
                    A[j].push_back(min(vec[j][0], vec[j][1]));
                }
            }
            swap(A, vec);
        }
        k -= 2 * n;
        k %= n;
        for(int i{0}; i < k; ++i){
            vector<vi> A(n);
            for(int j{0}; j < n; ++j){
                if(j == 0){
                    A[0].push_back(max(vec[j][0], vec[j][1]));
                    A[n - 1].push_back(min(vec[j][0], vec[j][1]));
                }
                else{
                    A[j - 1].push_back(max(vec[j][0], vec[j][1]));
                    A[j].push_back(min(vec[j][0], vec[j][1]));
                }
            }
            swap(A, vec);
        }
        for(int i{0}; i < n; ++i){
            cout << min(vec[i][0], vec[i][1]) << " " << max(vec[i][0], vec[i][1]) << "\n";
        }
    }
}
	
