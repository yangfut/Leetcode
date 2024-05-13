class Logger {
private:
    unordered_map<string, int> expiredTime;
public:
    
    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if(expiredTime.count(message)){
            if(expiredTime[message] > timestamp) return false;
        }

        expiredTime[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */