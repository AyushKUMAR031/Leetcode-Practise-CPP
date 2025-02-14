//working code //not best //but easiest
class Solution {
private:
    vector<int>nextSmallerElement(vector<int>& heights,int n){
        stack<int> nst;
        vector<int> nse(n);
        nst.push(-1);
        for(int i = n-1;i>=0;i--){
            while(nst.top() != -1 && heights[nst.top()] >= heights[i]){
                nst.pop();
            }
            nse[i] = nst.top();
            nst.push(i);
        }
        return nse;
    }

    vector<int> prevSmallerElement(vector<int>& heights,int n){
        stack<int> pst;
        vector<int> pse(n);
        pst.push(-1);
        for(int i=0;i<n;i++){
            while(pst.top() != -1 && heights[pst.top()] >= heights[i]){
                pst.pop();
            }
            pse[i] = pst.top();
            pst.push(i);
        }
        return pse;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;
        int maxArea = INT_MIN;

        vector<int> next(n);
        next = nextSmallerElement(heights,n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);

        for(int i=0;i<n;i++){
            int length = heights[i];

            //edge case
            if(next[i] == -1){ //coz if all heights are same there will be no smaller element.
                next[i] = n;
            }

            //calculating the width with index of nextSmaller and prevSmaller element.
            int width = next[i]-prev[i] - 1;

            area = length*width;
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};
