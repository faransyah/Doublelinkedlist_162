#include <iostream>
#include <string>
using namespace std; 

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addnode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listempty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchdata();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addnode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node(); //Step 1
	newNode->noMhs = nim; //Step 2
	newNode->name = nm; //Step 2

	/*inset a node in the beginin of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START == NULL && nim <= START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step 3
		if (START != NULL)
			START->prev = newNode; //step 4
		newNode->prev = NULL; //step 5
		START = newNode; //step 6
		return;
	}	

	/*Intersting a Node Between Two Nodes in the list*/
	Node* current = START; // step 1.a
	Node* previous = NULL; // step 1.b
	while (current->next != NULL && current->next->noMhs < nim) // step 1.c
	{
		previous = current; // 1.d
		current = current->next; // 1.e
	}
	
	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}



}
