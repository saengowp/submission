/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author win11905
 */

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};


class TaskC {
private:
	int n;
public:
	void solve(istream& cin, ostream& cout) {
		cin >> n;
		priority_queue<int> Q;
		int val; cin >> val;
		Q.emplace(val);
		long ans = 0;
		for(int i = 1; i < n; ++i) {
			cin >> val; val -= i;
			Q.emplace(val);
			if(Q.top() > val) {
				ans += Q.top() - val;
				Q.pop();
				Q.emplace(val);
			}
		}
		cout << ans << endl;
	}
};

class Solver {
public:
	void solve(std::istream& in, std::ostream& out) {
		TaskC *obj = new TaskC();
		obj->solve(in, out);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solver solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
