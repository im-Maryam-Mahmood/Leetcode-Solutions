class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWaitingTime = 0;
        int currentTime = 0;

        for (const auto& customer : customers) {
            int arrivalTime = customer[0];
            int cookingTime = customer[1];
            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }
            currentTime += cookingTime;
            totalWaitingTime += (currentTime - arrivalTime);
        }
        return (double)totalWaitingTime / customers.size();
    }
};