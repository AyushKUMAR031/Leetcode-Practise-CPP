//BEATS 100% - Sliding Window
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size()-1;
        int l = 0;
        int r = 0;
        int miniRecolor = INT_MAX;
        int currentWhite = 0;
        while( r < k-1){
            if(blocks[r] == 'W'){
                currentWhite++;
            }
            r++;
        }
        
        while( r <= n ){
            if(blocks[r] == 'W'){
                currentWhite++;
            }
            miniRecolor = min(miniRecolor, currentWhite);
            r++;
            if(blocks[l] == 'W'){
                currentWhite--;
            }
            l++;
        }
        return miniRecolor;
    }
};
