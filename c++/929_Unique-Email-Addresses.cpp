class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        
        for(string &email : emails){
            string clean_email;
            for(char &c : email){
                if(c == '+' || c == '@') break;
                if(c == '.') continue;

                clean_email += c;
            }
            clean_email += email.substr(email.find('@'));
            st.insert(clean_email);
        }

        return st.size();
    }
};