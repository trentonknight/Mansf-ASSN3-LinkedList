#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Letter {
	char let;
	Letter *next;
};
void LinkedListDriver();
void enterLetters(char letters[]);
void MakeNull(Letter **newNode);
struct Letter *addLETTERS(Letter *Top, Letter **head, char letters[]);
struct Letter *delLETTERS(Letter *Top, Letter **head);
struct Letter *printLinkedList(Letter *Top);

int main() {
	LinkedListDriver();
	system("PAUSE");
	return 0;
}
void LinkedListDriver(){
	Letter *Top = 0;
	Letter *head = 0;
	char letters[200] = {0};
	head = new Letter;
	Top = new Letter;
	MakeNull(&head);
	MakeNull(&Top);
    enterLetters(letters);
	addLETTERS(Top, &head,letters);
	cout << "Full Linked List: " << endl;
	printLinkedList(head);
	Top = head;
	MakeNull(&head);
	delLETTERS(Top, &head);
	cout << "All Nodes Deleted in List except the last one: " << endl;
	printLinkedList(head);
}

void MakeNull(Letter **newNode) {
	*newNode = new Letter;
	(*newNode)->let = 0;
	(*newNode)->next = 0;
}
void enterLetters(char letters[]){
	cout << "Enter Under 200 Letters: " << endl;
	cin.getline(letters,200);
}

struct Letter *addLETTERS(Letter *Top, Letter **head,char letters[]) {
	if(*letters != 0){
		Top = new Letter;
		Top->let = *letters++;
		Top->next = *head;
		*head = Top;
		addLETTERS(Top,head,letters);
	}
	return Top;
}

struct Letter *printLinkedList(Letter *Top) {
	
	if (Top->next != 0) {
		cout << Top->let << endl;
		Top = Top->next;
		printLinkedList(Top);
	}
	
	return Top;
}

struct Letter *delLETTERS(Letter *Top, Letter **head) {	
	
	if (Top->next != 0) {
		*head = Top;
		Top = Top->next;
		delete *head;
		delLETTERS(Top, head);
	}
	
	return *head;
}

