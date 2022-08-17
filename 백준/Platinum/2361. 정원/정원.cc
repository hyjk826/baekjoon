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

double dis(pair<double, double>  a, pair<double, double> b){
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(x * x + y * y);
}

int main() {
	fastio;
    int n;
    cin >> n;
    vector<pair<double, double> > vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    int sz = (n + 1) / 2;
    sort(vec.begin(), vec.end());
    double mn{MAX};
    double ansx, ansy;
    ansx = ansy = -1;
    set<pair<double, double> > st;
    for(int i{0}; i < sz - 1; ++i){
        st.insert({vec[i].second, vec[i].first});
    }
    int index{0};
    for(int i{sz - 1}; i < n; ++i){
        while(index < i){
            if(vec[i].first - vec[index].first < mn) break;
            st.erase({vec[index].second, vec[index].first});
            index++;
        }
        st.insert({vec[i].second, vec[i].first});
        auto l = st.lower_bound({vec[i].second - mn, -MAX});
        auto r = st.lower_bound({vec[i].second + mn, MAX});
        vector<pair<double, double> > A;
        for(auto j{l}; j != r; ++j){
            A.push_back({j->first, j->second});
        }        
        if(A.size() < sz) continue;
        set<pair<double, double> > st2;
        for(int j{0}; j < sz; ++j){
            st2.insert({A[j].second, A[j].first});
        }
        for(int j{sz - 1}; j < (int)A.size(); ++j){
            double mm = max(A[j].first - A[j - sz + 1].first, vec[i].first - st2.begin()->first);
            if(mm < mn){
                mn = mm;
                ansx = st2.begin()->first;
                ansy = A[j- sz + 1].first;
            }
            st2.insert({A[j].second, A[j].first});
            st2.erase({A[j - sz + 1].second, A[j - sz + 1].first});
        }
    }
    cout << fixed << setprecision(8);
    cout << mn << "\n";
    cout << ansx << " " << ansy;
}

