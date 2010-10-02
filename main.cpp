#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Letter {
	char let;
	Letter *next;
};
void MakeNull(Letter **newNode);
struct Letter *addLETTERS(Letter *Top, Letter **head, char& letters);
struct Letter *delLETTERS(Letter *Top,Letter **head);
struct Letter *printLinkedList(Letter *Top);

int main() {
	Letter *Top = 0;
	Letter *head = 0;
	Letter *save = 0;
	char letters = 'a';
	head = new Letter;
	Top = new Letter;
	save = new Letter;
	
	MakeNull(&head);
	MakeNull(&Top);
	MakeNull(&save);
	addLETTERS(Top, &head,letters);
	//printLinkedList(head);
	//printLinkedList(head);
	Top = head;
	//MakeNull(&head);
	*save = Top[0];
	delLETTERS(Top,&head);
	printLinkedList(save);
	return 0;
}

void MakeNull(Letter **newNode){
	*newNode = new Letter;
	(*newNode)->let = 0;
	(*newNode)->next = 0;
}

struct Letter *addLETTERS(Letter *Top, Letter **head, char& letters) {
	
	if(letters != 'z' + 1){
		Top = new Letter;
		Top->let = letters++;
		Top->next = *head;
		*head = Top;
		addLETTERS(Top,head,letters);
	}
	
	return Top;
	
}

struct Letter *printLinkedList(Letter *Top){
	
	if(Top != 0){
		cout << Top->let << endl;
		Top = Top->next;
		printLinkedList(Top);
	}
	
	return Top;
}
struct Letter *delLETTERS(Letter *Top,Letter **head) {
	
	if(Top != 0){
		*head = Top;
		Top = Top->next;
		delete *head;
		delLETTERS(Top,head);
	}
		
		return Top;
}

