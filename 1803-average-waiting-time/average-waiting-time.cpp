class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWaitingTime = 0;
        int currentTime = 0;

        for (const auto& customer : customers) {
            int arrivalTime = customer[0];
            int cookingTime = customer[1];

            // Update current time to when the chef starts this customer's order
            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }
            
            // Calculate the finish time for this order
            currentTime += cookingTime;
            
            // Calculate the waiting time for this customer
            totalWaitingTime += (currentTime - arrivalTime);
        }

        // Calculate and return the average waiting time
        return (double)totalWaitingTime / customers.size();
    }
};