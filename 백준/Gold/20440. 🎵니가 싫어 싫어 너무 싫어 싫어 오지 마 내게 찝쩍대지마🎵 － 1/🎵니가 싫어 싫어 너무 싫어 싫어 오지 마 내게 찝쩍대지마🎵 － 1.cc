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
    vp vec(n);
    vi A;
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        A.push_back(vec[i].first);
        A.push_back(vec[i].second);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vi ch((int)A.size());
    for(int i{0}; i < n; ++i){
        vec[i].first = lower_bound(A.begin(), A.end(), vec[i].first) - A.begin();
        vec[i].second = lower_bound(A.begin(), A.end(), vec[i].second) - A.begin();
        ch[vec[i].first]++;
        ch[vec[i].second]--;
    }
    for(int i{1}; i < (int)A.size(); ++i){
        ch[i] += ch[i - 1];
    }
    int mx{0};
    int l, r;
    for(int i{0}; i < (int)A.size(); ++i){
        if(ch[i] > mx){
            mx = ch[i];
            l = i;
            while(ch[i] == mx) i++;
            r = i;
            i--;
        }
    }
    cout << mx << "\n";
    cout << A[l] << " " << A[r];
    
}
