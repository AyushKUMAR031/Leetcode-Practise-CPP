//1st method
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayLen = haystack.length();
        int needleLen = needle.length();

        if (needleLen == 0) return 0;
        if (needleLen > hayLen) return -1;


        int a = 0;
        int index = -1;
        int first = 0;
        int lastIndex = needleLen - 1;
        int i =0;
        int count = 0;
        while(i<=haystack.length()){
            if(haystack[i] == needle[a]){
                if(first == 0){
                    first++;
                    index = i;
                }
                if(a == lastIndex){
                    break;
                }
                a++;
                i++;
            }else{
                count++;
                i=0+count;
                index = -1;
                first = 0;
                a=0;
            }
        }
        return index;
    }
};


//2nd method
//optimized method
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayLen = haystack.length();
        int needleLen = needle.length();

        if (needleLen == 0) return 0;
        if (needleLen > hayLen) return -1;

        for (int i = 0; i <= hayLen - needleLen; i++) {
            int j;
            for (j = 0; j < needleLen; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needleLen) {
                return i;
            }
        }

        return -1;
    }
};
