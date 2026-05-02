class FileSystem {
public:
    class Tree{
    public:
        string name;
        string content;
        bool isFile = false;
        map<string, Tree*> sub;
        Tree(){}
        Tree(string s): name(s) {}
        ~Tree(){
            for(auto& [name, child] : sub) delete child;
        }
    };
    
    Tree* root = new Tree("root");
    FileSystem() {
    }
    Tree* cd(string& path, bool mkdir){
        Tree* curr = root;
        for(int i = 0, j = 1; i < path.length(); ++i){
            if(path[i] != '/') continue;
            string next = path.substr(j, i-j);
            if(i - j > 0){
                if(!curr->sub.count(next) && mkdir){
                    curr->sub[next] = new Tree(next);
                }

                if(curr->sub.count(next)){
                    curr = curr->sub[next];
                }

                j = i + 1;
            }
        }
        return curr;
    }

    vector<string> ls(string path) {
        if(path.back() != '/') path += '/';
        Tree* curr = cd(path, false);
        vector<string> output;
        if(curr->isFile){
            // a file
            output.push_back(curr->name);
        }else{
            // a directory
            for(const auto obj : curr->sub) output.push_back(obj.first);
        }
        
        return output;
    }
    
    void mkdir(string path) {
        if(path.back() != '/') path += '/';
        Tree* curr = cd(path, true);
    }
    
    void addContentToFile(string filePath, string content) {
        if(filePath.back() != '/') filePath += '/';
        Tree* curr = cd(filePath, true);
        curr->content += content;
        curr->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        if(filePath.back() != '/') filePath += '/';
        Tree* curr = cd(filePath, false);
        return curr->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */