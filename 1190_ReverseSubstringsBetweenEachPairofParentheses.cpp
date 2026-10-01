#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string answer, rev;
    answer.reserve(2000);
    rev.reserve(2000);

    stack<char> mystack;


    int i = 0;

    while (i < s.size()) {
        // (1) no reverse => put into answer
        while (i < s.size() && s[i] != '(') {
            answer.push_back(s[i]);
            i++;
            cout << "(1) answer = " << answer << endl;
        }

        cout << "(1) check\n";

        if (s[i] == '(') {
            mystack.push(s[i]);
            i++;
        }

        while (!mystack.empty()) {
            // (2) push into stack
            while (i < s.size() && s[i] != ')') {
                mystack.push(s[i]);
                i++;
            }

            // (3) reverse one () into rev
            while (!mystack.empty() && mystack.top() != '(') {
                rev.push_back(mystack.top());
                mystack.pop();
            }
            i++; // count ')'
            mystack.pop(); // pop one '('
            cout << "(3) rev = " << rev << endl;

            // (3.1) stack not empty => put rev into stack
            if (!mystack.empty()) {
                for (int j = 0; j < rev.size(); j++) {
                    mystack.push(rev[j]);
                }
                rev.clear();
            }
            // conti push into stack => comeback to (2)
        }
        // (3.2) stack is empty => put rev into answer
        answer += rev;
        rev.clear();
        cout << "(3.2) ans = " << answer << endl;
        // stack is clear => comeback to (1)
    }

    cout << "\nFinal answer = " << answer << endl;
    return 0;
}