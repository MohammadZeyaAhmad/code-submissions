/* Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> curr;
        int result = 0;
        
        for (int i = 0; i <= heights.size(); i++) { // Include the end boundary
            int currHeight = (i == heights.size()) ? 0 : heights[i]; // Treat end as height 0

            while (!curr.empty() && heights[curr.top()] > currHeight) { // Corrected condition
                int height = heights[curr.top()];
                curr.pop();
                int width = curr.empty() ? i : i - curr.top() - 1; // Corrected width calculation
                result = max(result, height * width);
            }
            
            curr.push(i); // Push index instead of height
        }

        return result;
    }
};
