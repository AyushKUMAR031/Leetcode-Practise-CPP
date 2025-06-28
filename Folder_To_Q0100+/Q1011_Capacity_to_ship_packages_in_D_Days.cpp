class Solution {
public:
    bool solve(vector<int>& weights,int days,int m){
        int sum = 0;
        int day = 1;
        for(int i : weights){
            if(sum + i > m){
                day++;
                sum = i; //reseting the sum to current value (cause at this point i can't be added in shipment of that day,so we add the i for the next day shipment).
                if(day > days) return false;
            }else{
                sum += i;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = INT_MIN,e = 0;
        for(int i : weights){
            s = max(i,s);
            e += i;
        }

        int mincapacity = INT_MAX;
        while(s <= e){
            int m = s + (e-s)/2;
            if(solve(weights,days,m)){
                mincapacity = min(mincapacity,m);
                e = m-1;
            }else{
                s = m+1;
            }
        }

        return mincapacity;
    }
};