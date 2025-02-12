class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> my;
        for(int i : asteroids){
            if(my.empty()){
                my.push(i);
            }else{
                bool destroy = false;
                while(!my.empty() && i < 0 && my.top() > 0){
                    int top = my.top();
                    int abstop = abs(top);
                    int absi = abs(i);

                    if(abstop > absi){
                        destroy = true;
                        break;
                    }else if(abstop < absi){
                        my.pop();
                    }else{
                        my.pop();
                        destroy = true;
                        break;
                    }
                }
                
                if(!destroy){
                    my.push(i);
                }
            } 
        }

        while(!my.empty()){
            ans.push_back(my.top());
            my.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
