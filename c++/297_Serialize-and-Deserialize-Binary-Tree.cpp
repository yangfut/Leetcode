/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {        
        string data="";
        queue<TreeNode*>que;
        que.push(root);

        //Level order traversal
        while(!que.empty()){
            TreeNode* curNode = que.front();
            que.pop();

            if(curNode){
                data+=to_string(curNode->val);
                data+=",";

                que.push(curNode->left);
                que.push(curNode->right);
            }else{
                data+="N,";
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='N') return nullptr;
        queue<TreeNode*> que;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        que.push(root);
        while(!que.empty()){
            TreeNode* curNode = que.front();
            que.pop();
            getline(ss, str, ',');
            if(str!="N"){
                curNode->left = new TreeNode(stoi(str));
                que.push(curNode->left);
            }
            getline(ss, str, ',');
            if(str!="N"){
                curNode->right = new TreeNode(stoi(str));
                que.push(curNode->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));