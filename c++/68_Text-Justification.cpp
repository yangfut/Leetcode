class Solution {
private:
    void append_to_list(string &buff, int maxWidth, vector<string> &res){
        int extra_spc = maxWidth - buff.length();
        int num_spc = 0;
        for(int i = 0; i < buff.length(); ++i){
            if(buff[i] == ' ') ++num_spc;
        }

        if(num_spc == 0){
            int padding = maxWidth - buff.length();
            buff.append(padding, ' ');
        }else{
            int space_per_slot = extra_spc / num_spc;
            int extra = extra_spc % num_spc;
            for(int i = 0; i < buff.length(); ++i){
                if(buff[i] != ' ') continue;

                int padding = space_per_slot + (extra > 0 ? 1 : 0);
                buff.insert(i, padding, ' ');
                i += padding;
                if(extra) --extra;
            }
        }

        res.push_back(buff);
        buff.clear();
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curr_len = 0;
        string buff;
        vector<string> res;
        for(string &s : words){
            if(curr_len + s.length() <= maxWidth){
                buff += s + " ";
                curr_len += s.length() + 1;
            }else{
                buff.pop_back();
                // cout << buff << endl;
                append_to_list(buff, maxWidth, res);
                buff += s + " ";
                curr_len = s.length() + 1;
            }
        }

        if(curr_len){
            buff.pop_back();
            // cout << buff << endl;
            int extra_spc = maxWidth - buff.length();
            buff.append(extra_spc, ' ');
            res.push_back(buff);
        }

        return res;
    }
};