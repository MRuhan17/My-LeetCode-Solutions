using ll = long long;
using pii = pair<ll, int>;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> availableRooms;
      
        priority_queue<pii, vector<pii>, greater<pii>> occupiedRooms;
      
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }
      
        vector<int> meetingCount(n);
      
        sort(meetings.begin(), meetings.end());
      
        for (auto& meeting : meetings) {
            int startTime = meeting[0];
            int endTime = meeting[1];
          
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= startTime) {
                availableRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }
          
            int assignedRoom = 0;
          
            if (!availableRooms.empty()) {
                assignedRoom = availableRooms.top();
                availableRooms.pop();
                occupiedRooms.push({endTime, assignedRoom});
            }
            else {
                auto earliestFreeRoom = occupiedRooms.top();
                occupiedRooms.pop();
              
                assignedRoom = earliestFreeRoom.second;
                ll delayedEndTime = earliestFreeRoom.first + (endTime - startTime);
                occupiedRooms.push({delayedEndTime, assignedRoom});
            }
          
            ++meetingCount[assignedRoom];
        }
      
        int mostUsedRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingCount[mostUsedRoom] < meetingCount[i]) {
                mostUsedRoom = i;
            }
        }
      
        return mostUsedRoom;
    }
};
