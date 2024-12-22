class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> missing_vector;
        int sum_of_m = 0;
        for(int a : rolls){
            sum_of_m += a;
        }
        int m = rolls.size();
        int total_element = m + n;
        long sum_of_total = mean * total_element;
        int sum_of_n = sum_of_total - sum_of_m;

        if(sum_of_n> 6*n || sum_of_n<1*n){
            return missing_vector;
        }else{
            int middle_value = sum_of_n / n;
            if(middle_value<=6){
                bool check = n*middle_value == sum_of_n ? true : false;
                if(check){
                    missing_vector.insert(missing_vector.begin(),n,middle_value);
                }else{
                    int remaining = sum_of_n - (n*middle_value);
                    missing_vector.insert(missing_vector.begin(),n-remaining,middle_value);
                    middle_value++;
                    missing_vector.insert(missing_vector.begin(),remaining,middle_value);
                }
            }
        }
        return missing_vector;
    }
};
