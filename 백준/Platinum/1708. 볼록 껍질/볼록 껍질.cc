// 2022-11-26
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

struct point{
    ll x, y, p, q;
    point(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0){}    
};

bool comp(const point& A, const point& B){
    if(A.q * B.p != A.p * B.q) {
        return A.q * B.p < A.p * B.q;
    }
    if(A.y == B.y) return A.x < B.x;
    else return A.y < B.y;
}



ll ccw(const point& A, const point& B, const point& C){
    return A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y;
}

int main() {
	fastio;	
    int n;
    cin >> n;
    vector<point> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y;
    }
    sort(vec.begin(), vec.end(), comp);
    for(int i{1}; i < n; ++i){
        vec[i].p = vec[i].x - vec[0].x;
        vec[i].q = vec[i].y - vec[0].y;
    }
    sort(vec.begin() + 1, vec.end(), comp);
    stack<int> st;
    st.push(0);
    st.push(1);
    int k = 2;
    while(k < n){
        while(st.size() >= 2){
            int first, second;
            second = st.top();
            st.pop();
            first = st.top();
            if(ccw(vec[first], vec[second], vec[k]) > 0){
                st.push(second);
                break;
            }
        }
        st.push(k++);
    }
    cout << st.size();
}
	
