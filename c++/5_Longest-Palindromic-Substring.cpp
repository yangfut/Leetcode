class Solution {
public:
    string bf_solution(string s){
        //base case
        if(s.size()==1) return s;
        int n=s.size();

        //If max_length==n, match(s[0], s[n-1])
        //If max_length==n-1, match(s[0], s[n-2]) && match(s[1], s[n-1])
        //If max_length==n-2, match(s[0], s[n-3]) && match(s[1], s[n-2]) && match(s[2], s[n-1])
        //If max_length==n-3, match(s[0], s[n-4]) && match(s[1], s[n-3]) && match(s[2], s[n-2]) && match(s[3], s[n-1])

        int l=n;
        while(l>=2){
            for(int i=0, j=i+l-1;j<n;++i, ++j){
                //cout << l <<":" << s[i] << ":" <<s[j] << endl;
                int tmp_i=i, tmp_j=j;
                while(s[tmp_i]==s[tmp_j]&&tmp_i<=tmp_j){
                    ++tmp_i;
                    --tmp_j;
                }

                if(tmp_i>tmp_j) return string(s.begin()+i, s.begin()+j+1); // +i to start from iterator position i, +(j+1) to end at iterator position j
            }
            l--;
        }
        return string(s.begin(), s.begin()+1);
    }
    string Manacher_solution(string s){
        int n=s.size();
        int longest_size=0, longest_center=0;

        //Padding
        string new_str="#";
        for(char c:s){
            new_str.push_back(c);
            new_str.push_back('#');
        }
        int new_n = new_str.size();
        //right is the the boundary of palindrome from center
        //Due to symmetry of plaindrome, in the range of palindrome of center, 
        //LSR[i] is definity equal to LSR[mirror] or be cut off by right
        //LSR[i] = min(LSR[mirror], right-i)
        int center=0, right=0;
        vector<int>LPS(new_n, 0);
        for(int i=0;i<new_n;i++){
            int mirror = 2*center - i;
            if(i<right) LPS[i] = min(LPS[mirror], right-i);

            //tmp_r&tmp_l is unknown for palindrone
            int tmp_r = i+LPS[i]+1;
            int tmp_l = i-LPS[i]-1;

            //Expand the palindrome boundary
            while(tmp_r<new_n&&tmp_l>=0&&new_str[tmp_r]==new_str[tmp_l]){
                tmp_r++;
                tmp_l--;
                LPS[i]++;
            }
            if(i+LPS[i]>right){
                right=i+LPS[i];
                center = i;
            }


            if(LPS[i]>=longest_size){
                longest_size = LPS[i];
                longest_center = i;
            }
        }
        string ans(new_str.begin()+longest_center-longest_size, new_str.begin()+longest_center+longest_size+1);
        ans.erase(remove(ans.begin(), ans.end(), '#'), ans.end());
        return ans;
    }
    string longestPalindrome(string s) {
        //#1 Brute-force solution
        //TC:O(N^3)
        //return bf_solution(s);

        //#1 Manacher's algorithm
        //TC:O(N)
        return Manacher_solution(s);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        // 1. Expand palindrome substring in odd length
        // 2. Expand palindrome substring in even length

        string res="";
        int n=s.length();
        for(int center=0;center<n;++center){
            int l=center, r=center;
            // for odd condition
            while(r<n && l>=0 && s[r]==s[l]){
                if(r-l+1>res.length()){
                    res=s.substr(l, r-l+1);
                }
                ++r;
                --l;
            }

            // for even condition
            l=center, r=center+1;
            while(r<n && l>=0 && s[r]==s[l]){
                if(r-l+1>res.length()){
                    res=s.substr(l, r-l+1);
                }
                ++r;
                --l;
            }
        }
        return res;
    }
};