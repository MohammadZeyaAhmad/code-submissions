/*Given an integer numRows, return the first numRows of Pascal's triangle.*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i<numRows; i++){
            vector<int> temp;
            int result_size=result.size();
            for(int j = 0; j <= i; j++){
                temp.push_back((j>0 && j<i)?result[result_size-1][j-1]+result[result_size-1][j]:1);
            }
            result.push_back(temp); 
        }
        return result;
        }
};
