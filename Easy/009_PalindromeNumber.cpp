#include <iostream>
using namespace std;

int main() {
	int x;

	while (cin >> x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        if (x % 10 == 0) {
            return false;
        }

        // reverse half of x
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x = x / 10;
        }

        // check
        cout << "x = " << x << endl;
        cout << "re = " << reversed << endl;

        // compare
        if (x == reversed || x == reversed / 10) {
            return true;
        }
        else {
            return false;
        }
	}

	return 0;
}