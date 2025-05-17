class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> a;

        //track of all four edges
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

        while(top <= bottom && left <= right ){ // stop when top exceeds bottom or left exceed right (to avoid overlap)
        
           for(int j=left;j<=right;j++){
                a.push_back(matrix[top][j]);
           }
           top++; //shrinking top closer to mid

           for(int i=top;i<=bottom;i++){
                a.push_back(matrix[i][right]);
           }
           right--; //shrinking right closer to mid

           if(top <=bottom ){ //overlapping check
                for(int j=right;j>=left;j--){
                    a.push_back(matrix[bottom][j]);
                }
                bottom--; //shrinking bottom closer to mid
           } 
           
           if(left <=right ){ //overlapping check
            for(int i=bottom;i>=top;i--){
                a.push_back(matrix[i][left]);
            }
            left++; //shrinking left closer to mid
           }
        }
        return a;
    }
};
