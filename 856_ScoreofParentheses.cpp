#include <iostream>
#include <string>
#include <stack>
using namespace std;

int scoreOfParentheses(string s) {
    stack<int> mystack;
    int n = s.size();
    int top1, top2;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            mystack.push(0); // 0 == '('
        }
        else {  // s[i] == ')'
            top1 = mystack.top();
            mystack.pop();
            if (top1 == 0) {
                mystack.push(1);
            }
            else {
                top2 = mystack.top();
                mystack.pop();
                // A + B
                while (top2 != 0) {
                    mystack.push(top1 + top2);
                    cout << "(1) after + => " << mystack.top() << endl;
                    top1 = mystack.top();
                    mystack.pop();
                    top2 = mystack.top();
                    mystack.pop();
                }
                // 2 * A
                mystack.push(top1 * 2);
                cout << "(2) after * => " << mystack.top() << endl;
            }
        }
    }

    top1 = mystack.top();
    mystack.pop();
    // A + B
    while (!mystack.empty()) {
        top2 = mystack.top();
        mystack.pop();
        mystack.push(top1 + top2);
        cout << "(3) after + => " << mystack.top() << endl;
        top1 = mystack.top();
        mystack.pop();
    }
    return top1;
}

int main()
{
    string s;
    while (cin >> s) {
        cout << scoreOfParentheses(s) << endl;
    }

    return 0;
}