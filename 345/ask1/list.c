/*Anastasios Gialamoudis 2910 (gialamoud) */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	char *data;
	char *var_name;
	struct node *next;
}nd;

struct node *head=NULL;
struct node *current=NULL;

/*display */
void printList(){
	struct node *ptr=head;
	if(isEmpty()){
		printf("No variables found \n");
	}else{
		while(ptr!=NULL){
			printf("%s %s \n",ptr->var_name,ptr->data);
			ptr=ptr->next;
		}
	}
}

/*insert */
void insertFirst(char *var_name,char *data){
	struct node *link=(struct node *) malloc(sizeof(struct node));
	link->var_name=var_name;
	link->data=data;
	link->next=head;
	head=link;
	
}

int isEmpty()
{
   return head == NULL;
}

char *find(char * key){

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL)
	{
	printf("No variables found \n");
      return NULL;
   }

   //navigate through list
   while(strcmp(current->var_name,key)!=0){

      //if it is last node
      if(current->next == NULL){
	printf("Variable does not exist \n");
         return NULL;
      }else {
         //go to next link
         current = current->next;
      }
   } 
   //if data found, return the current Link
   return current->data;
}


struct node* delete(char * key){

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL){
      return NULL;
   }

   //navigate through list
   while(strcmp(current->var_name,key)!=0){
	
      //if it is last node
      if(current->next == NULL){
	printf("variable does not exist \n");
         return NULL;
      }else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;             
      }
		
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   }else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

