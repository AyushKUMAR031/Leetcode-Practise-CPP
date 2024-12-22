class MyCalendar {
public:
    set<pair<int,int>> set;
    MyCalendar(){
    }
    
    bool book(int start, int end) {

        for( auto interval : set){
            if(end > interval.first && start < interval.second){
                return false;
            }
        }
        set.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
