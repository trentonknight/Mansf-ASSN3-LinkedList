#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Letter {
	char let;
	Letter *next;
};
void MakeNull(Letter *newNode);
struct Letter *addLETTERS(Letter *Top, Letter *head, char& letters);
struct Letter *delLETTERS(Letter *Top);
struct Letter *printLinkedList(Letter *Top);

int main() {
	Letter *Top = 0;
	Letter *head = 0;
	char letters = 'a';
	head = new Letter;
	Top = new Letter;
	
	MakeNull(head);
	MakeNull(Top);
	addLETTERS(Top, head,letters);
	cout << Top->let << endl;
	//printLinkedList(Top);
	return 0;
}

void MakeNull(Letter *newNode){
    
        newNode = new Letter;
        newNode->let = 0;
        newNode->next = 0;
}

struct Letter *addLETTERS(Letter *Top, Letter *head, char& letters) {

	if(letters != 'z' + 1){
		Top = new Letter;
		Top->let = letters++;
		Top->next = head;
		head = Top;
		addLETTERS(Top,head,letters);
	}
	
	return Top;
	   
}

struct Letter *printLinkedList(Letter *Top){
		Top = new Letter;
		cout << Top->let << endl;
		Top = Top->next;
		printLinkedList(Top);
	
	return Top;
}
//struct Letter *delLETTERS(Letter *TOP) {

//return Top;

//}

