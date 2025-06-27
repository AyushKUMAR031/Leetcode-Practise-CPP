class Solution {
public:
    int maxDistance(string s, int k) {
        int dis = 0;
        int north = 0, south = 0, east = 0, west = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else if (c == 'W') west++;
            
            int x = abs(north - south);
            int y = abs(east - west);
            int MD = x + y;

            int availchange = min(2*k,(i+1)-MD); 
            dis = max(dis,MD + availchange);
            //2*k - a single change will alter value by 2 (say if x = -1 changing it to n will make x = +1 thats a change of 2)
            //and (i+1) is the current index of string used to calc what could be a max val if we only move in one direction lets say i=2 then index = i+1 = 3 ,lets say if we move only north then MD would be +3 (but if we changed the direction it will not be upto 3, say we moved to s))
            // hence we check min of (what changes of value is possible by 2*k and what is possible at current index with i+1 - MD)
        }
        return dis;
    }
};