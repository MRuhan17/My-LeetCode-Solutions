class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
      
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        string serializedResult;
      
        while (!nodeQueue.empty()) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();
          
            if (currentNode) {
                serializedResult += to_string(currentNode->val) + " ";
                nodeQueue.push(currentNode->left);
                nodeQueue.push(currentNode->right);
            } else {
                serializedResult += "# ";
            }
        }
      
        serializedResult.pop_back();
        return serializedResult;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
      
        stringstream stringStream(data);
        string token;
      
        stringStream >> token;
        TreeNode* root = new TreeNode(stoi(token));
      
        queue<TreeNode*> parentQueue;
        parentQueue.push(root);
      
        while (!parentQueue.empty()) {
            TreeNode* parentNode = parentQueue.front();
            parentQueue.pop();
          
            stringStream >> token;
            if (token != "#") {
                parentNode->left = new TreeNode(stoi(token));
                parentQueue.push(parentNode->left);
            }
          
            stringStream >> token;
            if (token != "#") {
                parentNode->right = new TreeNode(stoi(token));
                parentQueue.push(parentNode->right);
            }
        }
      
        return root;
    }
};
