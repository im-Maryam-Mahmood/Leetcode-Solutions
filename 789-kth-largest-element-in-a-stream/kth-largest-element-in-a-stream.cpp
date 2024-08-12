#include <queue>
#include <vector>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for (int num : nums) add(num);
    }
    
    int add(int val) {
        if (minHeap.size() < k) minHeap.push(val);
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};
