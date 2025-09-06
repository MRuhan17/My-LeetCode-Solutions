#include <deque>
using namespace std;

class RecentCounter {
    deque<int> requests;

public:
    RecentCounter() {}

    int ping(int t) {
        requests.push_back(t);
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop_front();
        }
        return requests.size();
    }
};

/* Usage example:
RecentCounter* obj = new RecentCounter();
int param_1 = obj->ping(t);
*/
