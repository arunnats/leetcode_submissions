/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(!node)
            return NULL;

        unordered_map<int, Node*> nodeMap;
        queue<Node*> q;

        Node* newNode = new Node(node->val);
        nodeMap[node->val] = newNode;
        vector<Node*> nodeList;

        q.push(node);

        while(!q.empty())
        { 
            Node* tempNode = q.front();
            q.pop();
            nodeList.push_back(tempNode);
        
            for(const auto& temp: tempNode->neighbors)
            {
                if(nodeMap.find(temp->val) == nodeMap.end())
                {
                    newNode = new Node(temp->val);
                    nodeMap[temp->val] = newNode;
                    q.push(temp);
                }
            }
        }

        queue<Node*> q2;

        for(const auto& tempNode: nodeList)
        {
            newNode = nodeMap[tempNode->val];
            for(const auto& temp: tempNode->neighbors)
            {
                newNode->neighbors.push_back(nodeMap[temp->val]);
                q2.push(temp);
            }
        }

        return nodeMap[1];
    }
};