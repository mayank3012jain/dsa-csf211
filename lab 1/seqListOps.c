/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl){
	int temp = sl.head;
	//int i = sl.head;
	while(st[temp].next != -1){
		if(compare(st[st[temp].next],j) == LESSER || compare(st[st[temp].next],j)==EQUAL){
			st[nextfreeloc].ele=j;
			st[nextfreeloc].next=st[temp].next;
			st[temp].next = nextfreeloc++;
			break;
		}else{
			temp=st[temp].next;
		}
	}
	if(st[temp].next == -1){
		st[temp].next = nextfreeloc++;
		temp = st[temp].next;
		st[temp].ele = j;
	}
}

//Implement this function
//
 }
  
void insertelements (JobList list , int size, SeqList s[3]){
	for (int i=0; i<3; i++){
		s[i] = createlist();
	}
	for (int i=0; i<size; i++){
		s[list[i].pri] = insert(list[i],s[list[i].pri]);
	}
	copy_sorted_ele(s,list);
// Implement this function

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function

}

void printlist(SeqList sl){
	int temp = sl.head;
	while(st[temp]!=-1){
		printjob(st[temp]);
		temp = st[temp].next;
	}
	printjob(st[temp]);
}

// Implement this function



void printJobList(JobList list, int size)
{

// Implement this function

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
