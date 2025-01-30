#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct Event {
    int type; // 0: OFFLINE, 1: MESSAGE
    int timestamp;
    string data;
    int originalIndex;
    
    Event(int t, int ts, const string& d, int idx) : type(t), timestamp(ts), data(d), originalIndex(idx) {}
};

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<Event> sortedEvents;
        int n = events.size();
        for (int i = 0; i < n; ++i) {
            const auto& e = events[i];
            int type = (e[0] == "OFFLINE") ? 0 : 1;
            int timestamp = stoi(e[1]);
            string data = e[2];
            sortedEvents.emplace_back(type, timestamp, data, i);
        }
        
        sort(sortedEvents.begin(), sortedEvents.end(), [](const Event& a, const Event& b) {
            if (a.timestamp != b.timestamp) {
                return a.timestamp < b.timestamp;
            } else {
                if (a.type != b.type) {
                    return a.type < b.type;
                } else {
                    return a.originalIndex < b.originalIndex;
                }
            }
        });
        
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offline_end_time(numberOfUsers, 0);
        
        for (const auto& event : sortedEvents) {
            if (event.type == 0) { // OFFLINE event
                int user_id = stoi(event.data);
                offline_end_time[user_id] = event.timestamp + 60;
            } else { // MESSAGE event
                const string& mentions_str = event.data;
                istringstream iss(mentions_str);
                string token;
                vector<int> mentioned_users;
                while (iss >> token) {
                    if (token.substr(0, 2) == "id") {
                        int user = stoi(token.substr(2));
                        if (user >= 0 && user < numberOfUsers) {
                            mentioned_users.push_back(user);
                        }
                    } else if (token == "ALL") {
                        for (int u = 0; u < numberOfUsers; ++u) {
                            mentioned_users.push_back(u);
                        }
                    } else if (token == "HERE") {
                        for (int u = 0; u < numberOfUsers; ++u) {
                            if (offline_end_time[u] <= event.timestamp) {
                                mentioned_users.push_back(u);
                            }
                        }
                    }
                }
                for (int user : mentioned_users) {
                    mentions[user]++;
                }
            }
        }
        
        return mentions;
    }
};