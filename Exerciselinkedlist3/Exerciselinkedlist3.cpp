#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode(int rollno);
	void traverse();
};

void CircularLinkedList::addNode() { //write your answer here
	int rollNumber;
	string nm;
	cout << "\nEnter the roll number :";
	cin >> rollNumber;
	cout << "\nEnter the name :";
	cin >> nm;
	Node* newNode = new Node(); //step 1
	newNode->rollNumber = rollNumber; //step 2
	newNode->name = nm; //step 2

	/*Insert a node in the beginning of a doubly - linked list*/
	if (LAST == NULL || rollNumber <= LAST->rollNumber) {
		if (LAST != NULL && rollNumber == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST; //step 3
		if (LAST != NULL)
			LAST->next = newNode; //step 4
		newNode->next = NULL; //step 5
		LAST = newNode; //step 6
		return;
	}

	/*Inserting a node between two nodes in the list*/
	Node* Arya = LAST; //step 1.a
	Node* Anugrah = NULL; //step 1.b
	while (Arya->next != NULL && Arya->next->rollNumber < rollNumber) //step 1.c
	{
		Anugrah = Arya; //step 1.d
		Arya = Arya->next; //step 1.e
	}

	if (Arya->next != NULL && rollNumber == Arya->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowed " << endl;
		return;
	}

	newNode->next = Arya->next; //step 4
	newNode->next = Arya; //step 5
	if (Arya->next != NULL)
		Arya->next->next = newNode; //step 6
	Arya->next = newNode; //step 7
}

bool CircularLinkedList::search(int rollno, Node** Anugrah, Node** Arya) {
	*Anugrah = LAST->next;
	*Arya = LAST->next;
	while (*Arya != LAST) {
		if (rollno == (*Arya)->rollNumber) {
			return true;
		}
		*Anugrah = *Arya;
		*Arya = (*Arya)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode(int rollno) { //write your answer here
	Node* Anugrah, * Arya;
	Anugrah = Arya = NULL;
	if (search(rollno, &Anugrah, &Arya) == false)
		return false;
	if (Arya->next != NULL)
		Arya->next->next = Anugrah; //step 2
	if (Anugrah != NULL)
		Anugrah->next = Arya->next; //step 3
	else
		LAST = Arya->next;

	delete Arya; //step 4
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
