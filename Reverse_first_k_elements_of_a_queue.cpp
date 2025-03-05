class Solution {
public:
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> temp;

        // Step 1: Push first k elements into stack
        for (int i = 0; i < k; i++) {
            temp.push(q.front());
            q.pop();
        }

        // Step 2: Pop from stack and push back to queue (Reversing first k elements)
        while (!temp.empty()) {
            q.push(temp.top());
            temp.pop();
        }

        // Step 3: Move remaining (n-k) elements to the back of queue
        int size = q.size();
        for (int i = 0; i < size - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};
