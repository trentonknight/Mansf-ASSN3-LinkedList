///////////////////////////////////////////////////////////////////////
///  CODE FILENAME:	Mansfield-Assn3-LLProg2.cpp
///  DESCRIPTION:	Simple Node deletion Program. Program run a variety
///                 of Recursive functions to obtain and delete Nodes in
///
///  DATE:		03OCT10
///  DESIGNER:	Jason N Mansfield (mansf843)
///  FUNCTIONS:	LinkedListDriver - contains recursive functions and other functions.
///             MakeNull - Nullifies Nodes.
///             enterLetters - simple char array creator.
///             addLETTERS - recurses through linked list and adds char array to new nodes.
///             delLETTERS - recurses and deletes nodes while traversing linked list.
///             printLinkedList - traverses list and prints out to user.
///////////////////////////////////////////////////////////////////////
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <iostream>

using namespace std;
///structure for single linked list
struct Letter {
	char let;
	Letter *next;
};
void LinkedListDriver();//function for containing recursive functions
void enterLetters(char letters[]);//simple char array
void MakeNull(Letter **newNode);//nullify nodes
struct Letter *addLETTERS(Letter *Top, Letter **head, char letters[]);
struct Letter *delLETTERS(Letter *Top, Letter **head);
struct Letter *printLinkedList(Letter *Top);
///////////////////////////////////////////////////////////////////////
///  FUNCTION: main()
///  DESCRIPTION: contains single function
///  INPUT: LinkedListDriver
///  CALLS TO: LinkedListDriver
////////////////////////////////////////////////////////////////////////

int main() {
	LinkedListDriver();//call driver function
	system("PAUSE");
	return 0;
}
///////////////////////////////////////////////////////////////////////
//  FUNCTION: LinkedListDriver
//  DESCRIPTION: cycles through all other functions
//  CALLS TO: MakeNull, enterLetters, addLETTERS, delLETTERS, printLinkedList
////////////////////////////////////////////////////////////////////////
void LinkedListDriver(){
	Letter *Top = 0;///node 1
	Letter *head = 0;///node 2
	char letters[200] = {0};///character string
	head = new Letter;
	Top = new Letter;
	MakeNull(&head);//nullify
	MakeNull(&Top);//nullify
    enterLetters(letters);///get letter string for recursive function
	addLETTERS(Top, &head,letters);///first recursive function
	cout << "Full Linked List: " << endl;
	printLinkedList(head);///recursive print function
	Top = head;
	MakeNull(&head);///clean up head before next function
	delLETTERS(Top, &head);///recursive deletion of nodes
	cout << "All Nodes Deleted in List except the last one: " << endl;
	printLinkedList(head);///recursive print again
}
///////////////////////////////////////////////////////////////////////
//  FUNCTION: MakeNull
//  DESCRIPTION: nullifies node	
//  INPUT:
//      Parameters: one Letter *node
//  OUTPUT:	
//      Return Val: one NULL Letter *node
////////////////////////////////////////////////////////////////////////
void MakeNull(Letter **newNode) {
	*newNode = new Letter;
	(*newNode)->let = 0;
	(*newNode)->next = 0;
}
///////////////////////////////////////////////////////////////////////
//  FUNCTION: enterLetters	
//  DESCRIPTION: gets char from user input
//  INPUT:
//      Parameters: getline
//  OUTPUT:	
//      Return Val: letters[] with characters
////////////////////////////////////////////////////////////////////////

void enterLetters(char letters[]){
	cout << "Enter Under 200 Letters: " << endl;
	cin.getline(letters,200);
}
///////////////////////////////////////////////////////////////////////
//  FUNCTION:	addLETTERS
//  DESCRIPTION: traverses linked list and recieves characters for each node
//  INPUT:
//      Parameters: Top->let = new character
//  OUTPUT:	
//      Return Val: Top[0] - Top[200] with characters
//  CALLS TO: addLETTERS (recursive)
////////////////////////////////////////////////////////////////////////

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
///////////////////////////////////////////////////////////////////////
//  FUNCTION: printLinkedList
//  DESCRIPTION: traverses linked list and prints out characters
//  INPUT:
//      Parameters: Top->let
//  CALLS TO: printLinkedList (recursive)
////////////////////////////////////////////////////////////////////////
struct Letter *printLinkedList(Letter *Top) {
	
	if (Top->next != 0) {
		cout << Top->let << endl;
		Top = Top->next;
		printLinkedList(Top);
	}	
	return Top;
}
///////////////////////////////////////////////////////////////////////
//  FUNCTION: delLETTERS
//  DESCRIPTION: traverses linked list up in till the last node deleting each
//  INPUT:
//      Parameters: *head becomes Top and is then deleted
//  OUTPUT:	
//      Return Val: head[0]
//  CALLS TO: delLETTERS (recursive)
////////////////////////////////////////////////////////////////////////

struct Letter *delLETTERS(Letter *Top, Letter **head) {		
	if (Top->next != 0) {
		*head = Top;
		Top = Top->next;
		delete *head;
		delLETTERS(Top, head);
	}	
	return *head;
}

