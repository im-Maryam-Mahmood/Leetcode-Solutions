class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> queue;
        for (int i = 0; i < tickets.size(); i++) queue.push(i);
        int time = 0;
        while (!queue.empty()) {
            time++;
            int front = queue.front();
            queue.pop();
            tickets[front]--;
            if (k == front && tickets[front] == 0) return time;
            if (tickets[front] != 0) queue.push(front);
        }
        return time;
    
    }
};