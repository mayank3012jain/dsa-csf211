#include"bst.h"

//balance info not added
NODE addUB(NODE root, int value){
	if (root == NULL){
		root = (NODE) malloc( sizeof(node));
		root->value = value;
		root->hleft = 0;
		root->hright = 0;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		return root;
	}
	NODE temp = root;
	NODE parent = NULL:
	while(temp != NULL){
		parent = temp;
		if (temp->value >= value){
			temp->helft +=1;
			temp = temp->left;
		}else{
			temp->hright +=1;
			temp = temp->right;
		}
	}
	temp = (NODE)malloc(sizeof(node));
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;
	temp->hleft = 0;
	temp->hright = 0;
	if(parent->value >= value){
		parent->left = temp;
		temp->parent = parent;
	}else{
		parent->right = temp;
		temp->parent = parent;
	}
	return root;
}

NODE find(NODE root, int value){
	NODE temp = root;
	while(temp != NULL){
		if(temp->value = value){
			return temp;
		}else if(temp->value >= value){
			temp = temp->left;
		}else{
			temp = temp->right;
		}
	}
	printf("Not found\n");
	return NULL;
}

NODE inOrderSuccessor(NODE root, NODE given){
	
}

NODE deleteNode(NODE root, NODE toDelete){
	NODE temp = toDelete;
	while(!(toDelete->left == NULL && toDelete->right == NULL)){
		temp=inOrderSuccessor(root, toDelete);
		toDelete->value = temp->value;
		toDelte = temp;
	}
	if(toDelete == toDelete->parent->left){
		toDelete->parent->left = NULL;
	}else{
		toDelete->parent->right = NULL;
	}
	free(toDelete);
}




