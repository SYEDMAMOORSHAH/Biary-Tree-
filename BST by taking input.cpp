#include <bits/stdc++.h>
 #include <string>
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<windows.h>
using namespace std;
struct node
{

	
     node *left;
    int data;
        node *right;
        node(){
        	right=NULL;
        	left=NULL;
        }
};
 node *root=NULL;
void Treecreate()  
{
	    queue<node*> q;
	    node *tmp;
		node *newnode;
	    int x;
	    cout<<"Enter root value: ";
	    cin>>x;
	    root = new node;
	    root -> data = x;
	    root->left =NULL;
		root->right = NULL;
	    q.push(root);
        while(!q.empty()){
        tmp = q.front();
        q.pop();
        cout<<"Enter left child of "<<tmp->data<<": ";
        cin>>x;
        if(x!=0){
        newnode = new node;
        newnode -> data = x;
        newnode->left =NULL;
		newnode->right = NULL;
        tmp->left = newnode;
        q.push(newnode);
    }
        cout<<"Enter right child of "<<tmp->data<<": ";
        cin>>x;
        if(x!=0){
            newnode = new node;
            newnode -> data = x;
            newnode->left = NULL;
			newnode->right = NULL;
            tmp->right = newnode;
            q.push(newnode);
        }
     }
}


//  How to serach Node in bst:
node* serch_in_BST(node *root,int c)
{
if  (root==NULL)
	{
	return NULL;
	}
if  (root->data==c)
    {
	return root;
    }
if  (root->data>c)
    {
  	return serch_in_BST(root->left,c);
    }
    return serch_in_BST(root->right,c);
    }




void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
 int countBST(node* root)
	{
    	if(root==NULL){
    		return 0;
    	}
    	return countBST(root->left)+countBST(root->right)+1;
}







void preorder(node *root){
	if (root==NULL)
	{return;
   	}
  
  {
  	cout<<root->data <<"  ";
	preorder (root->left);
  	preorder(root->right);
  }
}
void postorder(node *root)
{
	if (root== NULL)
	{
		return;
		
	}
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"  " ;
	}
}








 // How will add or sum Node in Bst:
        int sumOfBST(node* root){
        	if(root==NULL){
        		return 0;
        	}
        	return sumOfBST(root->left)+sumOfBST(root->right)+root->data;
        }
        
        // Level order Traversal :
        void Levelorder(node* root){
        	
        	if(root==NULL){
        		return ;
        	}
        	
        	queue<node*> q;
        	q.push(root);
        	q.push(NULL);
        	
        	while(!q.empty()){
        	node *node =q.front();
        	q.pop();
        	if(node!=NULL){
        	cout<<node->data<<" ";
       		if(node->left!=NULL)
       		q.push(node->left);
      		if(node->right!=NULL)
      	    q.push(node->right);	
        	}
        	else if(!q.empty())
        	q.push(NULL);
        }
    }
    // sum of node on any levle:
    int SumAtKthLEVEL(node* root,int k){
    	
    	if (root==NULL){
    		return -1 ;
    	}
    	
    	queue<node*> q;
    	q.push(root);
    	q.push(NULL);
		int level=0;
		int sum=0; 
        while (!q.empty()){
        node* node =q.front();
        q.pop();
        if(node!=NULL)
		{
        if(level==k)
		{ 	
        sum+=node->data;
        }
        if(node->left!=NULL)
        q.push(node->left);
        if(node->right!=NULL)
        q.push(node->right);
        }
        else if(!q.empty())
		{
        q.push(NULL);
        level++;
        }
        }
    	
    	return sum;
    }
    //Left view of Bst:
    	void Leftview(node* root){
    		if (root==NULL){
    			return ;
    		}
    		queue<node*>q;
    		q.push(root);
    		while (!q.empty()){
    		
    		int n =q.size();
    		for(int i=1;i<=n;i++){
    			node* temp =q.front();
    			q.pop();
    			
    			if (i==1){
    				cout<<temp->data<<" ";
    				
    				if(temp->left!=NULL){
    					q.push(temp->left);
    					if(temp->right!=NULL){
    						q.push(temp->right);
       }
       }
   	   }
       }
       }
       }
    //Right view of BST:
    	
    	
    void rightview(node* root)
	{
    	if(root==NULL){
    		return ;
    	}
    	 queue<node*> q;
    	 q.push(root);
    	
    	 while(!q.empty()){
    	 int n= q.size();
    	 for(int i=0;i<n;i++){
    	 	
    	 node* temp =q.front();
    	 	
    	 q.pop();
    	 
    	 if(i== n-1){
    	 cout<<temp->data<<" ";
    	 	
    	 }
    	 if(temp->left!=NULL){
    	 q.push(temp->left);
    	 }
    	 if(temp->right!=NULL){
    	 q.push(temp->right);
    	 }
         }
    	 	
    	 }
		 
    }
    
    
    
    
    
   // delete case 3 in bst:
 node* inordersucc(node *root)
 {
	   node* curr=root;
while  (curr&&curr->left!=NULL)
	   {
   	   curr=curr->left;
	   }
return curr;


}
	   // How to delete Node from Bst case 1&2:
node* DeleteInBST(node *root,int key){

         	
	if  (key<root->data)
		{
		root->left= DeleteInBST(root->left,key);
		}
	else if(key>root->data)
		{
		root->right=DeleteInBST(root->right,key);
		}
	else{
	
	if(root->left==NULL)
		{ 
			node *temp;
			temp=root->right;
	        free(root);
	return temp;
		}
	else if(root->right==NULL)
		{
			node *temp=root->left;
	free(root);
			return temp;
		}
	    

                        //case 3:
          node* temp=inordersucc(root->right);
		  root->data=temp->data;
		  root->right=DeleteInBST(root->right,temp->data);  
	}
    }







        int main()
{
	
	
	 cout<<"BINARY SEARCH TREE:"<<endl;
	
   cout<<"*******************"<<endl;

   cout<<"           6        "<<endl;
   cout<<"         /  |       "<<endl; 
   cout<<"        4   7       "<<endl;
   cout<<"       / |          "<<endl;
   cout<<"      2  5          "<<endl;
                
                
  cout<<"*******************"<<endl;
    // In-order:  2 4 5 6 7
    
   
    system("color 3F");
    Treecreate();
    
    
    cout<<"*******************"<<endl;
	    int a;
      	while(true)
	{
		
		
    cout<<"Press  1  for preorder Traversal :"                 <<endl;
      
	cout<<"Press  2  for inorder Traversal :"                  <<endl;
	
	cout<<"Press  3  for postorder Traversal :"                <<endl;
	  
    cout<<"press  4  for level order Traversal :"              <<endl;
    
    cout<<"press  5  to display sum at level order:"         <<endl;
      
    cout<<"press  6  to count all node in BST :"               <<endl;
     
    cout<<"Prss   7  to display sum of all nodes in BST :"     <<endl;
     
    cout<<"press  8  for  right and left veiw of BST :"      <<endl;

    cout<<"press  9  to serch any node in  BST:"            <<endl;

    cout<<"Press 10 to delete Any NOde form BST : "<<endl;
    
    
    
    cout<<"      *****************************      "        <<endl;
    cout<<"     * Enter Any NUMBER FORM ABOVE *     "        <<endl;
    cout<<"      *****************************      "        <<endl;
     
     cin>>a;
      
		switch (a)
		{
		

    case 1:
    {
    	system("CLS");
    
   	cout<<"**preorder**"<<endl;
    preorder(root);
    cout<<endl;
	cout<<"*****************"<<endl;


break;
}
case 2:{
	system("CLS");

    
    cout<<"**Inorder**"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"*****************"<<endl;
	
break;
}
	case 3:{
		system("CLS");
	
	cout<<"**postorder**"<<endl;
    postorder(root);
	cout<<endl;
	cout<<"*****************"<<endl;

break;
}
	  case 4:{
	  	
	  	cout<<endl;
	cout<<"*********************"<<endl;
	  	
	  system("CLS");
	cout<<" **Levle order **"<<endl;
	Levelorder(root);
	cout<<endl;
	cout<<"*****************"<<endl;

break;
}
	case 5:{
		cout<<endl;
	cout<<"*********************"<<endl;
		
		int L;
		system("CLS");
	cout<<"Enter level you want to sum"<<endl;
	cin>>L;
	cout<<"SUM AT level order : "<<SumAtKthLEVEL(root,L);
	cout<<endl;
	cout<<"*********************"<<endl;
break;
}

	case 6:{
		cout<<endl;
	cout<<"*********************"<<endl;
		
		system("CLS");
	cout<<"Total NODE in BST are : "; 
    cout<<countBST(root)<<endl;
	cout<<"*****************************"<<endl;
	break;
	}
	case 7:{
		cout<<endl;
	cout<<"*********************"<<endl;
		
		system("CLS");
	 cout<<"sum of all node in BST are : ";
    cout<<sumOfBST(root)<<endl;
	cout<<"*******************************"<<endl;
	break;
	}
	case 8:{
		
		cout<<endl;
	cout<<"*********************"<<endl;
		
		system("CLS");
	cout<<"*********************"<<endl;
	cout<<"Right view of BST are : ";
	        rightview(root);
	        cout<<endl;

	cout<<"*********************"<<endl;
	cout<<"Left view of BST are : ";
	Leftview(root);
	cout<<endl;
	cout<<"*********************"<<endl;
break;	
case 9:{
	
	cout<<endl;
	cout<<"*********************"<<endl;
	
	system("CLS");
	int c;
	cout<<"Enter Node You Want To Search In BST :  "<<endl;
	cin>>c;
	 if (serch_in_BST(root,c)==NULL)
	   {
	   cout<<"**Noode Are Not exist**"<<endl;
	   }
	   else
	   {
	   	cout<<"  Node are :" << c <<endl;
	   }
	break;
		cout<<endl;
	cout<<"*********************"<<endl;
}
case 10:{
	cout<<endl;
	cout<<"*********************"<<endl;
	
	int D;

	system("CLS");
	
	cout<<"Enter Node Number You want to delete form BST : "<<endl;
	cin>>D; 
	root  = DeleteInBST(root,D);  
	cout<<"Deleting Node are :"<< D <<endl;
	break;
		cout<<endl;
	cout<<"*********************"<<endl;

}
}

   default:
	cout<<endl;
	cout<<"*********************"<<endl;
	
		cout<<"\a You put Invalude number:"<<endl;
		cout<<endl<<endl<<endl;
			cout<<endl;
	cout<<"*********************"<<endl;
}

}
}



