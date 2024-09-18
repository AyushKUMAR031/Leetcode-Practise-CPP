//my method -> noob method
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string str1,str2;
        string largest_num = "";
        for(int i=0;i<nums.size()-1;i++){
            bool swapped = false;
            for(int j=0;j<nums.size()-i-1;j++){
                string str1 = to_string(nums[j]) + to_string(nums[j+1]);
                string str2 = to_string(nums[j+1]) + to_string(nums[j]);
                if (str1 > str2 ){
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
            if(!swapped){
                break;
            }
        }

        for(int i=nums.size()-1;i>=0;i--){
            largest_num += to_string(nums[i]);
        }

        if(largest_num[0] == '0'){
            largest_num = "0";
            return largest_num;
        }

        return largest_num;
    }
};

//pro method
bool cmp(string& s1, string& s2) { return s1 + s2 > s2 + s1; }

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

        bool zero = true;
        vector<string> str;

        for (auto i : nums) {
            if (i != 0)
                zero = false;
            str.push_back(to_string(i));
        }

        if (zero)
            return "0";

        sort(str.begin(), str.end(), cmp);

        string ans = "";

        for (auto i : str) {
            ans += i;
        }

        return ans;
    }
};
