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

	newNode->next = current->next; //step 4
	newNode->prev = current; //step 5
	if (current->next != NULL)
		current->next->prev = newNode; // step 6
	current->next = newNode; //step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL; // step 1.a
	*current = START; // step 1.b
	while (*curent != NULL && (current)->noMhs) {//step 1.c
		*previous = *current; //step 1.d
		*current = (*current)->next; //step1.e
	}
	retrun(*current != NULL);


}
bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;
}

bool DoubleLinkedList::ListEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (istEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (ListEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecords in a]descending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}




