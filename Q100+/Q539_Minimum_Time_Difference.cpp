class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> times;
        for(auto i : timePoints){
            int time = ((i[0]-'0')*10 + (i[1]-'0'))*60 + ((i[3]-'0')*10 + (i[4]-'0'));
            times.push_back(time);
        }
        int diff;
        int min_diff = 720;
        for(int i=0;i<times.size();i++){
            for(int j=i+1;j<times.size();j++){
                // cout<<times[i]<<" "<<times[j]<<endl;
                if(abs(times[i]-times[j])>720){
                    if(times[i]<times[j]){
                        int a = times[i]+1440;
                        diff = a - times[j];
                    }else{
                        int a = times[j]+1440;
                        diff = a - times[i];
                    }
                    min_diff = min(diff, min_diff);
                }else{
                    diff = abs(times[i]-times[j]);
                    min_diff = min(diff, min_diff);
                }
            }
        }
        return min_diff;
    }
};
