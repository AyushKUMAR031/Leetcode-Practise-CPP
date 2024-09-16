//my method -> time 652ms (6.28)% beats
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

//pro method 
//chatgpt method
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Helper function to convert time string "HH:MM" to total minutes from midnight
int convertToMinutes(const string &time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;

    // Convert each time point to minutes and store in the vector
    for (const string& time : timePoints) {
        minutes.push_back(convertToMinutes(time));
    }

    // Sort the time points in minutes
    sort(minutes.begin(), minutes.end());

    int n = minutes.size();
    int minDifference = 1440; // Max difference possible is 1440 minutes (24 hours)

    // Calculate the minimum difference between adjacent time points
    for (int i = 1; i < n; ++i) {
        minDifference = min(minDifference, minutes[i] - minutes[i - 1]);
    }

    // Check the difference between the last and the first time point across midnight
    minDifference = min(minDifference, 1440 - (minutes[n - 1] - minutes[0]));

    return minDifference;
}
