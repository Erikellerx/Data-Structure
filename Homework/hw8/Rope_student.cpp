/*
Write your Rope implementation in this file. 
You do not have to keep any of the code that is already in this file.
Functions that are required that you have not implemented have an assert 0
meaning they will always crash. This should help you make sure you implement
everything.
*/

#include <cassert>
#include "Rope.h"

//Should advance to the next Node using in-order traversal
//It can point at any Node, not just leaves
rope_iterator rope_iterator::operator++(){
	//loop through all the leafs 
	//basically same code as lecture note
	if(ptr_->right!= NULL){
		//if there is no right sub trees, go back to top 
		//and find next left sub trees
		ptr_ = ptr_ -> right;
		while(ptr_ -> left != NULL){
			ptr_ = ptr_ -> left;
		}
	} else{//find next right sub tree
		while(ptr_->parent&&ptr_ -> parent ->right == ptr_){
			ptr_ = ptr_->parent;
		}
		ptr_=ptr_->parent;
	}
	return rope_iterator(ptr_);
}

//Point to the first Node for in-order traversal
rope_iterator Rope::begin() const{
	//go very left leaf
	if(!root) return rope_iterator(NULL);
	Node* p = root;
	while(p->left) p = p->left;
	return rope_iterator(p);
}
//set everything to 0
Rope::Rope(){
	root = NULL;
	size_ = 0;	
}

//Should make the root = p and adjust any member variables
//This should not make a copy of the rope with root at p,
//it should just "steal" the Node*
//steal the root and count its size
Rope::Rope(Node* p){
	root = p;
	size_ = find_size(p);
}
//destructor
Rope::~Rope(){
	destroy_rope(root);
}
//copy constructor
//copy the root top from bottom and copy the size
Rope::Rope(const Rope& r){
	root = copy_rope(r.root,NULL);
	size_ = r.size();
}
//besically as copy constructor
Rope& Rope::operator= (const Rope& r){
	root = copy_rope(r.root,NULL);
	size_ = r.size();
	return *this;
}

//MUST BE ITERATIVE
//Get a single character at index i
bool Rope::index(int i, char& c) const{	
	//if invalid index
	if(i >= size_ || i<0) return false;
	c = 0;//initialize char
	Node * temp = root;
	//go to the very bottom base on the index until reach the leaf
	while(temp->value =="" ){
		if(temp->weight > i) temp = temp->left;
		else{
			//basic calculation base on rope propority
			i = i - temp->weight;
			temp = temp->right;
		}
	}
	//find the specific char on that value
	c = temp->value[i];
	return true;
}

//Add the other rope (r)'s string to the end of my string
void Rope::concat(const Rope& r){
	//corner case, 
	if(!r.root) return;
	if(!root){
		root = copy_rope(r.root,NULL);
		return;
	}
	//create a new root and connect its right and left
	Node *new_root = new Node();
	new_root->weight = find_size(root);//find its size
	//making the connection and making the rhs copy
	new_root->left = root;
	root->parent = new_root;
	new_root->right = copy_rope(r.root,NULL);
	new_root->right->parent = new_root;
	//assign the root to new root
	root = new_root;
	//update the size
	size_ = find_size(root);

}

//Get a substring from index i to index j.
//Includes both the characters at index i and at index j.
//String can be one character if i and j match
//Returns true if a string was returned, and false otherwise
//Function should be written with efficient running time.

bool Rope::report (int i, int j, std::string& s) const{
	//all the cornor case I can think about
	if(j<i) return false;
	if((j-i)>=size_) return false;
	if(j>size_) return false;
	//initialize the string
	s = "";
	//size is how many character we need to get 
	int size = j-i;
	//loop through the very bottom of tree to locate that leaf
	Node* temp = root;
	while(temp->value =="" ){
		if(temp->weight > i) temp = temp->left;
		else{
			i = i - temp->weight;
			temp = temp->right;
		}
	}
	
	
	//whole node or just some of it
	//then s+ the substring where we needed
	if(temp->weight - i > size+1){
		s += temp->value.substr(i,size+1);		
	}
	else{
		s+= temp->value.substr(i,temp->weight - i);
	}
	//update the size
	size -= temp->weight-i;
	//if we are good with it, then return
	if(size <= 0) return true;

	
	//go to the next leaf node with iterator
	rope_iterator itr = rope_iterator(temp);
	itr++;
	//loop through each node until it reach the end or the size is satisfied
	//basically same as top part except the the start is 0
	while(size>=0 && itr.ptr_!= NULL){
		if(itr.ptr_ -> value != ""){
			if(itr.ptr_->weight - i > size+i){
				s += itr.ptr_->value.substr(0,size+1);				
			}
			else{
				s+= itr.ptr_->value.substr(0,itr.ptr_->weight - i);				
			}
			size -= itr.ptr_->weight-i;


		}
		itr++;
	}
	return true;

}

//The first i characters should stay in the current rope, while a new
//Rope (rhs) should contain the remaining size_-i characters.
//A valid split should always result in two ropes of non-zero length.
//If the split would not be valid, this rope should not be changed,
//and the rhs rope should be an empty rope.
//The return value should be this rope (the "left") part of the string
//This function should move the nodes to the rhs instead of making new copies.
Rope& Rope::split(int i, Rope& rhs){
	//locate the the index node
	Node* temp = root;
	while(temp->value == ""){
		if(temp->weight > i) temp = temp->left;
		else{
			i = i - temp->weight;
			temp = temp->right;
		}
	}
	
	//if is in the middle of the node, then cut it in half
	if(i != 0 ){
		//create two new node
		temp->left = new Node();
		temp->right = new Node();
		//making connection
		temp->left ->parent = temp;
		temp->right -> parent = temp;
		//cut the string in half and copy them
		temp->left->value = temp->value.substr(0,i);
		temp->right->value = temp->value.substr(i,temp->value.size()-1);
		//update the weight
		temp->left->weight = i;
		temp->right->weight = temp->value.size() - i;
		//relocate the temp value to the right leaf
		temp->value = "";
		temp->weight = i;
		temp = temp-> right;
	}
	
	Node* temp2 = temp;
	Node* cut1 = NULL;
	Node* cut2 = NULL;
	Node* change1 = NULL;
	Node* change2 = NULL;
	//first going up to find if the parent's left tree is itself 
	//then make the cut
	while(temp->parent){
		if(temp->parent->left != temp){
			cut1 = temp;
			break;
		}
		temp = temp->parent;
	}

	temp2 = cut1->parent;
	//then make the cut and update the weight
	if(cut1){
		cut1->parent->right = NULL;
		change1 = cut1->parent;
		change1->weight = find_size(change1->left);
		cut1->parent = NULL;
	}

	//std::cout<<"cut1 "<<cut1->weight<<cut1->value<<std::endl;
	//keep going up, finding all the right trees where we need to cut
	//bseically if the parent have right sub, then decide if right is itself
	//if it's not, make the cut, 
	//then connect with cut1, where cut1 is lhs and new cut is rhs, 
	//then keep looking up until the parent and the one we just 
	//connected will become cut1, the new one(if it exists) will
	//become cut2, then keep making connection.
	while(temp2->parent&& temp2->parent != root){

		if(temp2->parent->right&&temp2->parent->right != temp2){
			//create new node
			Node* output = new Node();			
			cut2 = temp2;
			//making the cut
			if(cut2){
				cut2 = cut2->parent;
				cut2 = cut2->right;
				//making connection and update its weight
				change2 = cut2->parent;
				change2->weight = find_size(change2->left);
				cut2->parent->right = NULL;
				cut2->parent = NULL;
			}
			//making connection and the whole thing become cut1
			output->right = cut2;
			output->left = cut1;
			//connect back to parent
			cut1->parent = output;
			cut2->parent = output;
			output->weight = find_size(output->left);//update the weight
			cut1 = output;
		
		}
		//going up
		temp2->weight = find_size(temp2->left);
		temp2 = temp2->parent;	
	}
	//std::cout<<"cut2 "<<cut2->weight<<cut2->value<<std::endl;
	//create a new class which is the right hand sub
	root->weight= find_size(root->left);
	rhs = Rope(cut1);
	size_ = root->weight;
	return *this;
}

//destroy the entire thing
//same as lecture note
//using recursion
void destroy_rope(Node *p){
	if(!p) return;
	destroy_rope(p->right);	
	destroy_rope(p->left);	
	delete p;
}
//deep copy of rope starting from root to bottom
//recursively
Node* copy_rope(Node* old_p, Node* parent_p){
	if(!old_p) return NULL;
	Node* output = new Node();
	output->weight = old_p->weight;
	output->value = old_p->value;
	output->left = copy_rope(old_p->left, output);
	output->right = copy_rope(old_p->right,output);
	output->parent = parent_p;
	return output;
}
//help to find weight given the root of node
//the calculation is the properity of rope structure
int find_size(Node* temp){
	int output = temp->weight;
	while(temp->right){
		temp = temp->right;
		output += temp->weight;
	}
	return  output;
}