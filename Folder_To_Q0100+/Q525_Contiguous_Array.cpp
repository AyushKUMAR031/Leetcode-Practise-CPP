class Solution {
public:

    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> prefix; //basically we are storing sum, index of where that sum lies
        int sum = 0;
        int maxLength = 0;
        prefix[0] = -1; //maanlo agar kabhi sum = 0 hua hi nahi phele seedhe end mei hua array ke toh 
        //if waale part mei .find se kabhi nahi milega jabki whole array is giving the max length issliye phele se sum 0       // at -1 index
        for(int i=0;i<nums.size();i++){
            sum += (nums[i] == 0) ? -1 : 1; // for 0 we push -1 and for 1 we pull 1 so that they sum up to 0 when equal in count
            if(prefix.find(sum) != prefix.end()){ 
                // if we get same sum two time i.e, all the element in b/w are nullifying giving a length of equal count.
                maxLength = max(maxLength,i-prefix[sum]); 
                // i(current occurence of sum)-prefix[sum](same sum jo phele bhi tha)
            }else{
                prefix[sum] = i; //agar koi sum phele bhi tha toh and wo phir mila toh usse update nahi karenge 
                //kyuki aage phir agar woi sum mila tho longest length phele wala index dega.
                //isliye else mei prefix sum update kiya.
                //taki jo sum nahi mila phele kabhi woi add ho map mei.//koi update na ho taki max length mile
            }
        }
        return maxLength;
    }
};
