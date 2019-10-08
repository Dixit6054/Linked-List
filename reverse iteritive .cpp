#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void print(void);
Node* head=NULL;

main()
{
	int i;
	Node* temp;
	for(i=0;i<4;i++)
	{
		temp = new Node;
		temp->data = i+12;
		temp->next = head;
		head = temp;  
	cout << head << " "; 
	}
	
	print();
}
void print ()
{
	int i;
	cout << "\n\n";
	for(i=0;i<7;i++)
	{
		Node* temp = head;
		cout <<temp->data << " ";
		temp = temp->next;
	}
}
