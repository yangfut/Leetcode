class Solution {
    unordered_map<string, string> dict;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string prefix = getPrefix(longUrl);
        int prefix_size = prefix.length();

        string key = getRandom();
        dict[key] = longUrl.substr(prefix_size);
        return prefix + "tinyUrl/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string prefix = getPrefix(shortUrl);
        int prefix_size = prefix.length();

        string key = shortUrl.substr(prefix_size+8);
        return prefix + dict[key];
    }
    string getPrefix(string& url){
        int i = 1;
        while(i < url.length()){
            if(url[i] == '/' && url[i] == url[i-1]) break;
            ++i;
        }
        return url.substr(0, i+1);
    }
    string getRandom(){
        return to_string(rand());
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));