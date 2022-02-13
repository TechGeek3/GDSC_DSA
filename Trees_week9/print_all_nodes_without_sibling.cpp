//Given a Binary Tree of size N, find all the nodes which don't have any sibling. You need to return a list of integers containing all 
//the nodes that don't have a sibling in sorted order.
//Note: Root node can not have a sibling so it cannot be included in our answer.

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    if(str.length() == 0 || str[0] == 'N')             //Corner Case
            return NULL;
    
    vector<string> ip;                                 //Creating vector of strings from input string after spliting by space
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
vector<int> noSibling(Node *root);

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        vector<int> res = noSibling(root);
        for (int i = 0; i < res.size(); ++i)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
  }
  return 0;
}

void auxFunc(Node* node, vector<int>& vec)
{
    if(node == NULL)
        return;
        
    if(!node->left && node->right)
        vec.push_back(node->right->data);
        
    else if(!node->right && node->left)
        vec.push_back(node->left->data);
        
    auxFunc(node->left, vec);
    auxFunc(node->right, vec);
}

vector<int> noSibling(Node* node)
{
    vector<int> vec;
    
    auxFunc(node, vec);
    sort(vec.begin(), vec.end());
    if(vec.size()==0)
        return {-1};
        
    return vec;
}