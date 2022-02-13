//Given a binary tree, find its height.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

Node* buildTree(string str)                                               //Function to Build Tree
{   
    if(str.length() == 0 || str[0] == 'N')                                //Function to Build Tree
            return NULL;
    
    vector<string> ip;                                                    //Creating vector of strings from input string after spliting by space
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    Node *root = new Node(stoi(ip[0]));                                   //Create the root of the tree
        
    queue<Node*> queue;                                                   //Push the root to the queue
    queue.push(root);
        
    int i = 1;                                                            //Starting from the second element
    while(!queue.empty() && i < ip.size()) {
        
        Node* currNode = queue.front();                                   //Get and remove the front of the queue
        queue.pop();
        
        string currVal = ip[i];                                           //Get the current node's value from the string
        
        if(currVal != "N") {                                              //If the left child is not null

            currNode->left = new Node(stoi(currVal));                     //Create the left child for the current Node
                
            queue.push(currNode->left);                                   //Push it to the queue
        }
            
        i++;                                                              //For the right child
        if(i >= ip.size())
            break;
        currVal = ip[i];
        
        if(currVal != "N") {                                              //If the right child is not null
        
            currNode->right = new Node(stoi(currVal));                    //Create the right child for the current node
                
            queue.push(currNode->right);                                  //Push it to the queue
        }
        i++;
    }
    
    return root;
}

class Solution{
    public:
    int height(struct Node* node){                                        //Function to find the height of a binary tree.
        if(node == NULL)
            return 0;
        
        return max(height(node->left), height(node->right)) + 1;
    }
};

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
        Solution ob;
		cout<<ob.height(root)<<endl;
    }
    return 0;
}