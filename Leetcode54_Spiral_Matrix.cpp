/* Given an m x n matrix, return all elements of the matrix in spiral order. */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        while(bottom>=top && right>=left){
            if(bottom>=top){
            for(int i=left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }}
            top++;
           if(right>=left){ for(int j=top;j<=bottom && j>=top;j++){
                result.push_back(matrix[j][right]);
            }}
            right--;
            if(bottom>=top)
            {for(int k=right;k>=left;k--){
                result.push_back(matrix[bottom][k]);
            }}
            bottom--;
            if(right>=left)
            {
            for(int l=bottom;l>=top;l--){
                result.push_back(matrix[l][left]);
            }}
            left++;
           
        }
        return result;
    }
};
