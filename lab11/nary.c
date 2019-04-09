#include"nary.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(NODE root, char* domain, char* ip);
void insertWord(char* word, NODE trav);

NODE readData(FILE* input, NODE root, int n){
	
	char domain[100];
	char ip[50];
	for ( int i=0; i< n; i++){
		fscanf(input, "%s %s", domain, ip);
		insert( root, domain, ip);
		//printf("%s ,%s, %d\n", domain, ip, i);
	}
}

void insert(NODE root, char* domain, char* ip){
	printf("**%s**%s**\n", domain, ip);
	NODE trav = root;
	char word[100];
	int len = strlen(domain);
	int j=0;
	for(int i =len-1; i>=0 ; i--){
		if(domain[i] == '.'){
			word[j+1] = '\0';
			insertWord(word, trav);
			j=0;
		}else{
			word[j] = domain[i];
			j++;
			//printf("\n%c  %d",word[j],j);
		}
	}
	word[j] = '\0';
	insertWord(word, trav);
	NODE nodeIP = (NODE) malloc(sizeof(struct node));
	strcpy(nodeIP->key, ip);
	nodeIP->child = NULL;
	modeIP->sibling = NULL;
	trav->child=nodeIP;
}

void insertWord(char* word, NODE trav){
	printf("word:%s\t", word);
	NODE newNode = (NODE) malloc(sizeof(struct node));
	strcpy(newNode->key, word);
	newNode->child = NULL;
	newNode->sibling = NULL;
	if (trav->child == NULL){
		//printf("parent:%s", trav->key);
		trav->child = newNode;
		trav= trav->child;
		return;
	}
	trav = trav->child;
	while(trav->sibling != NULL){
		if(strcmp(trav->key, word) == 0){
			return;
		}
		trav= trav->sibling;
	}
	trav->sibling = newNode;
	trav= trav->sibling;	
}
