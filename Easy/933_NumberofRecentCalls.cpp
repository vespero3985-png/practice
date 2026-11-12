#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        
    }

    int ping(int t) {
        requests.push(t);
        while (!requests.empty() && requests.front() < (t - 3000)) {
            requests.pop();
        }
        return requests.size();
    }
private:
    queue<int> requests;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */