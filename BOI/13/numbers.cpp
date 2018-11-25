/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author win11905
 * reduce to number of palin free(b) - number of palin free(a-1)
 * I use dynamic programming to count how many way that before
 * if the number is palin free -> A[i] != A[i-1] and A[i] != A[i-2]
 * dp[n][a][b][st] = position n, A[i-1] = a, A[i-2] = b, can fill with another number? 
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


class numbers {
private:
	long a, b;
    char inp[25];
    long dp[25][11][11][2];
   	long solve(int n, int a, int b, bool st) {
		long &val = dp[n][a][b][st];
		if(~val) return val;
		if(inp[n] == 10) return val = 1;
		val = 0;
		for(int i = 0; i <= (st ? 9 : inp[n]); ++i) {
			if(i == a || i == b) continue;
			if(i == 0 && a == 10 && b == 10) val += solve(n+1, a, b, true);
			else val += solve(n+1, i, a, st || i != inp[n]);
		}
		return val;
   	}
	long get(long val) {
		if(val == -1) return 0;
		sprintf(inp, "%lld", val);
		for(int i = 0; ; ++i) {
			if(inp[i]) inp[i] -= '0';
			else {
				inp[i] = 10;
				break;
			}
		}
		memset(dp, -1, sizeof dp);
		return solve(0, 10, 10, false);
	}
public:
	void solve(istream& cin, ostream& cout) {
		cin >> a >> b;
		cout << get(b) - get(a-1) << endl;
	}
};

class Solver {
public:
	void solve(std::istream& in, std::ostream& out) {
		numbers *obj = new numbers();
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
