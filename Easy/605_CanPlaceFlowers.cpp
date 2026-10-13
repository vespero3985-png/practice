#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void printFlowerbed(vector<int> flowerbed, int n) {
    cout << "flowerbed = [";
    for (int s : flowerbed) {
        cout << s << ", ";
    }
    cout << "],  ";
    cout << "n = " << n << "\n";
}

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;
    int len = flowerbed.size();
    // size = 1
    if (len == 1) {
        if (flowerbed[0] == 0 && n == 1)
            return true;
        else
            return false;
        
    }
    // size >= 2
    else if (len > 1) {
        // first
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        cout << "first end\n";
        printFlowerbed(flowerbed, n);
        // mid
        for (int i = 1; i < len - 1; i++) {
            if (n == 0) return true;
            if (flowerbed[i] == 1) {
                i++;
                continue;
            }
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                cout << "i = " << i << ", n--\n";
                printFlowerbed(flowerbed, n);
                i++;
                n--;
            }
        }
        // last
        if (n != 0 && flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0) {
            flowerbed[len - 1] = 1;
            n--;
            cout << "last--\n";
            printFlowerbed(flowerbed, n);
        }
    }

    if (n == 0)
        return true;
    return false;
}

int main()
{
    vector<int> flowerbed;
    int n;
    string line;
    while(getline(cin, line)) {
        // 過濾空白行
        if (line.find_first_not_of(" \t") == string::npos) continue;
        
        stringstream ss(line);
        int temp;
        while (ss >> temp) {
            flowerbed.push_back(temp);
        }

        if (getline(cin, line)) {
            n = stoi(line);
        }

        cout << "ANSWER = " << canPlaceFlowers(flowerbed, n) << endl;
        flowerbed.clear();
    }

    return 0;
}