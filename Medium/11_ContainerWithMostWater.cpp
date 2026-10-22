#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    bool lower = (height[r] > height[l]); // 1 : left <= right

    while (l < r) {
        // compute area & move the lower one
        if (lower) {
            cout << "area = " << r - l << " * " << height[l] << " = " << (r - l) * height[l] << "\n";
            ans = max(ans, (r - l) * height[l]);
            l++;
        }
        else {
            cout << "area = " << r - l << " * " << height[r] << " = " << (r - l) * height[r] << "\n";
            ans = max(ans, (r - l) * height[r]);
            r--;
        }
        // update lower!!
        lower = (height[r] > height[l]);
    }

    return ans;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.find_first_not_of(" \t") == string::npos) continue;

        vector<int> height;

        stringstream ss(line);
        int temp;
        
        while (ss >> temp) {
            height.push_back(temp);
        }

        cout << "ANS = " << maxArea(height) << "\n";
    }
    return 0;
}

/*
1 8 6 2 5 4 2 3 7
1 1


*/