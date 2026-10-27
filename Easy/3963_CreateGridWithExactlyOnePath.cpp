#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> createGrid(int m, int n) {
	vector<string> ans;
	
	string first(n, '.');
	ans.push_back(first);

	string line(n, '#');
	line[n - 1] = '.';

	for (int i = 1; i < m; i++) {
		ans.push_back(line);
	}

	return ans;
}

int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<string> ans = createGrid(m, n);
		cout << "Grid = \n";
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[0].size(); j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}