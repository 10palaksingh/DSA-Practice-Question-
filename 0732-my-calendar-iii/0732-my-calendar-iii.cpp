class MyCalendarThree {
public:
    map<int, int> events;
    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;
        int count = 0;
        int maxi = 0;
        for (auto& it : events) {
            count += it.second;
            maxi = max(maxi, count);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */