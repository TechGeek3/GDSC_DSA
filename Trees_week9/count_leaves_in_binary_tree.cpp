//Given a Binary Tree of size N , You have to count leaves in it. For example, there are two leaves in following tree

#include <bits/stdc++.h>
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
    if(str.length() == 0 || str[0] == 'N')                                          //Corner Case
            return NULL;
    
    vector<string> ip;                                                              //Creating vector of strings from input string after spliting by space
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    
    Node* root = newNode(stoi(ip[0]));                                              //Create the root of the tree
   
    queue<Node*> queue;                                                             //Push the root to the queue
    queue.push(root);  
    
    int i = 1;                                                                      //Starting from the second element
    while(!queue.empty() && i < ip.size()) {  
        
        Node* currNode = queue.front();                                             //Get and remove the front of the queue
        queue.pop();  
        
        string currVal = ip[i];                                                     //Get the current node's value from the string
        
        if(currVal != "N") {                                                        //If the left child is not null
            
            currNode->left = newNode(stoi(currVal));                                //Create the left child for the current node
           
            queue.push(currNode->left);                                             //Push it to the queue
        }  
       
        i++;                                                                        //For the right child
        if(i >= ip.size())
            break;
        currVal = ip[i];  
        
        if(currVal != "N") {                                                        //If the right child is not null
            
            currNode->right = newNode(stoi(currVal));                               //Create the right child for the current node
            
            queue.push(currNode->right);                                            //Push it to the queue
        }
        i++;
    }
    
    return root;
}
int countLeaves(struct Node* root);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<< countLeaves(root)<<endl;
    }
    return 0;
}

int countLeaves(Node* root)
{
    if(root)
    {
        if(!root->left && !root->right)
            return 1;
        
        return countLeaves(root->left) + countLeaves(root->right);
    }
    return 0;
}