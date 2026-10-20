#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int compress(vector<char>& chars) {
    int left = 0; // right = i
    char now = chars[0];
    int count = 0;
    

    for (int i = 0; i < chars.size(); i++) {
        cout << "TURN " << i << "\n";
        if (chars[i] == now) {
            count++;
            cout << "count++\n";
        }
        else { // compress
            cout << "turn " << left << "-th from \"" << chars[left];
            chars[left] = now;
            cout << "\" into \"" << chars[left] << "\"\n";
            if (count != 1) {
                string count_str = to_string(count);
                for (int j = 0; j < count_str.size(); j++) {
                    left++;
                    cout << "turn " << left << "-th from \"" << chars[left];
                    chars[left] = count_str[j];
                    cout << "\" into \"" << chars[left] << "\"\n";
                }
            }
            // to this & reset count
            left++;
            now = chars[i];
            count = 1;  // count this!
            cout << "next = " << now << " at " << left << "\n";
        }
    }
    
    
    cout << "turn " << left << "-th from \"" << chars[left];
    chars[left] = now;
    cout << "\" into \"" << chars[left] << "\"\n";
    // compress
    if (count != 1) {
        string count_str = to_string(count);
        for (int j = 0; j < count_str.size(); j++) {
            left++;
            cout << "turn " << left << "-th from \"" << chars[left];
            chars[left] = count_str[j];
            cout << "\" into \"" << chars[left] << "\"\n";
        }
    }
    left++;

    chars.resize(left);
    return left;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.find_first_not_of(" \t") == string::npos) continue;

        vector<char> chars;

        // 解析測資：過濾掉 JSON 格式符號與引號、空白
        for (char c : line) {
            if (c != '[' && c != ']' && c != ',' && c != '"' && c != '\'' && !isspace(static_cast<unsigned char>(c))) {
                chars.push_back(c);
            }
        }

        int len = compress(chars);

        // 輸出測試結果
        cout << "Length: " << len << ", Chars: [";
        for (int i = 0; i < len; ++i) {
            cout << "\"" << chars[i] << "\"" << (i == len - 1 ? "" : ",");
        }
        cout << "]" << endl;
    }
    return 0;
}

// ["a","b","b","b","b","b","b","b","b","b","b","b","b","c","c","c","d","d","e","f"]