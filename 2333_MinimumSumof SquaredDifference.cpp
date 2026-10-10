#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    vector<int> diff((int)1e5 + 1, 0);
    long long sum = 0;
    
    int maxium = 0, temp;
    for (int i = 0; i < nums1.size(); i++) {
        temp = abs(nums1[i] - nums2[i]);
        diff[temp]++;
        sum += temp;
        maxium = max(temp, maxium);
    }

    long long k = k1 + k2;
    if (sum <= k) return 0;

    long long move;
    while (k > 0 && maxium > 0) {
        move = min(k, (long long)diff[maxium]);
        diff[maxium] -= move;
        diff[maxium-1] += move;
        k -= move;
        if (!diff[maxium])
            maxium--;
    }

    long long ans = 0;
    for (int i = 0; i <= maxium; i++) {
        ans += (long long) i * i * diff[i];
    }

    return ans;
}

int main() {
    // 輔助函式：用來將輸入字串（支援空白、逗號、中括號）解析成 vector<int>
    auto parseVector = [](const string& s) {
        vector<int> v;
        string temp = "";
        for (char c : s) {
            if (isdigit(c) || c == '-') {
                temp += c;
            }
            else {
                if (!temp.empty()) {
                    v.push_back(stoi(temp));
                    temp = "";
                }
            }
        }
        if (!temp.empty()) {
            v.push_back(stoi(temp));
        }
        return v;
    };

    string line1;
    // 使用 while 迴圈實現重複執行，直到輸入結束 (EOF，例如 Windows 下按 Ctrl+Z，Mac/Linux 下按 Ctrl+D)
    while (getline(cin, line1)) {
        // 過濾空白行
        if (line1.find_first_not_of(" \t\n\r") == string::npos) continue;

        string line2;
        if (!getline(cin, line2)) break;

        int k1, k2;
        if (!(cin >> k1 >> k2)) break;

        // 讀取完 k1, k2 後清除緩衝區的換行符號
        string dummy;
        getline(cin, dummy);

        vector<int> nums1 = parseVector(line1);
        vector<int> nums2 = parseVector(line2);

        // 執行並輸出結果
        long long ans = minSumSquareDiff(nums1, nums2, k1, k2);
        cout << "Minimum Sum of Squared Difference: " << ans << "\n\n";
    }

    return 0;
}