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
		if (START == NULL && nim <= START->noMhs)
	}
	
}
neNode->next = 