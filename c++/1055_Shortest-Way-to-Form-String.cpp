class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_set<char> uniqueChar;
        for(char& c: source) uniqueChar.insert(c);
        for(char& c: target){
            if(!uniqueChar.count(c)) return -1;
        }

        int counter = 1;
        for(int srcIdx = 0, tarIdx = 0; tarIdx < target.size(); ++tarIdx){
            if(srcIdx == source.size()) {
                srcIdx = 0;
                ++counter;
            }

            while(source[srcIdx] != target[tarIdx]){
                if(srcIdx+1 == source.size()){
                    srcIdx = 0;
                    ++counter;
                } else ++srcIdx;
            }

            ++srcIdx;
        }
        return counter;
    }
};