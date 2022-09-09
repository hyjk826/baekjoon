// 2022-09-09
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
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    string ans;
    vi A;
    for(int i{n}; i >= 1; --i){
        A.push_back(i);
    }
    stack<int> st;
    for(int i{0}; i < n; ++i){
        int k = vec[i];
        if(!st.empty() && st.top() == k){
            ans += '-';
            st.pop();
            continue;
        }
        while(!A.empty() && A.back() != k){
            int a = A.back();
            A.pop_back();
            st.push(a);
            ans += '+';
        }
        if(!A.empty() && A.back() == k){
            ans += "+-";
            A.pop_back();
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    for(int i{0}; i < (int)ans.size(); ++i){
        cout << ans[i] << "\n";
    }
}