#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct LinkedListNode
{ 
	int key; 
	struct LinkedListNode *next;
};

	int ComputeSUM(LinkedListNode *head) {
		LinkedListNode *temp = new struct LinkedListNode();
		temp = head;
		int sum = 0;

		while (temp != NULL) {
			sum += temp->key;
			temp = temp->next;
		}

		delete temp;
		return sum;
	}

	struct LinkedListNode* head = NULL;
	void insert(int new_data) {
		struct LinkedListNode* new_node = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
		new_node->key = new_data;
		new_node->next = head;
		head = new_node;
	}
	void display() {
		struct LinkedListNode* ptr;
		ptr = head;
		while (ptr != NULL) {
			cout << ptr->key << " ";
			ptr = ptr->next;
		}
		cout << ComputeSUM(head);
	}
	int main() {
		insert(0);
		insert(-20);
		insert(0);
		insert(12);
		insert(8);
		cout << "The linked list is: ";
		display();

		system("PAUSE");
	}