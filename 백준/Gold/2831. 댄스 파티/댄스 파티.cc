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

int main(){
	fastio;
    int n;
    cin >> n;
    vi A, B, C, D;
    for(int i{0}; i < n; ++i){
        int x;
        cin >> x;
        if(x < 0) A.push_back(-x);
        else B.push_back(x);
    }
    for(int i{0}; i < n; ++i){
        int x;
        cin >> x;
        if(x < 0) C.push_back(-x);
        else D.push_back(x);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());
    int ans{0};
    int j{0};
    for(int i{0}; i < (int)D.size(); ++i){
        while(j < (int)A.size() && A[j] <= D[i]) j++;
        if(j < (int)A.size()){
            ans++; j++;
        }
    }
    j = 0;
    for(int i{0}; i < (int)B.size(); ++i){
        while(j < (int)C.size() && C[j] <= B[i]) j++;
        if(j < (int)C.size()){
            ans++; j++;
        }
    }
    cout << ans;
}
