class Solution {
private:
    class Node{
    public:
        unordered_map<char, Node*> next;

        ~Node() {
            for (auto& [_, ptr] : next)
                delete ptr;
        }
    };
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node* head = new Node();
        for(int num : arr1){
            string s = to_string(num);
            Node* curr = head;
            for(char& c : s){
                if(curr->next.find(c) == curr->next.end()){
                    curr->next[c] = new Node();
                }
                curr = curr->next[c];
            }
        }
        int maxDepth = 0;
        for(int num : arr2){
            string s = to_string(num);
            Node* curr = head;
            int currDepth = 0;
            for(char& c : s){
                if(curr->next.find(c) == curr->next.end()) break;
                ++currDepth;
                curr = curr->next[c];
            }
            maxDepth = max(maxDepth, currDepth);
        }
        delete head;
        return maxDepth;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> pattern;
        for(int num : arr1){
            for(int x = num; x > 0; x /= 10){
                pattern.insert(x);
            }
        }

        int maxCommonDigits = 0;
        for(int num : arr2){
            int commonDigits = 0;
            for(int x = num; x > 0; x /= 10){
                if(pattern.count(x)){
                    while(x){
                        x /= 10;
                        ++commonDigits;
                    }
                    break;
                }
            }
            maxCommonDigits = max(maxCommonDigits, commonDigits);
        }
        return maxCommonDigits;
    }
};