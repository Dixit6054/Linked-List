/*
	Name: DIXT KHOSLA
	Copyright: -
	Author: -
	Date: 07-02-15 19:55
	Description: 
*/
#include<iostream>
using namespace std;
void reverse(void);
void insert(int);
void print(void);
struct Node
{
	int data;
	Node* next;
};
void printr(Node*);
void reverser(Node*);

Node* Head=NULL;
main()
{
	int i,x;
	cout << "Enter any 5 elements: ";
	for(i=0 ; i<5 ; i++)
	{
		cin>>x;
		insert(x);
	}
	cout << "\n\nHere is your list: "; 
	print();
	cout << "\n\nGetting in reverse order 1: ";
	reverse();
	print();
	cout << "\n\nGetting in reverse order 2(THIS IS JUST PRINTING): \n";		//Note: i am reversing a reversed list
	printr(Head);
	cout << "\n\nAgain, Reversing with recursion:\n ";
	reverser(Head);													//These functions should be designed s.t. you are designing the library functions
	print();															//ie no extra arguments to be taken
	
	
}
void insert(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = Head;
	Head = temp;
}

void print (void)
{
	Node* temp = Head;
	while(temp!=NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void reverse(void)
{
	cout << "\n\nThis one is through links\n\n";
	Node* temp1= Head;
	Node* temp2 = temp1->next;
	Node* temp3 = temp2->next;
	
	temp1->next = NULL;
	while(temp3 != NULL)
	{
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;
		temp3 = temp3->next;
	}
	
	temp2->next = temp1;
	Head = temp2;	
}

void printr(Node* temp)
{
	if(temp == NULL)
	return;
	printr( temp->next );
	cout << temp->data << " ";
}

void reverser(Node*temp1)			// DO check this function in other program as well;
{
	Node* temp2 = temp1->next;
	Head->next = NULL;							 		//do check the postion of this line,,,,just prfect ;using heAD is also a good one
	if(temp2 == NULL)
	{
		Head = temp1;
		return;
	}
	reverser(temp2);
	temp2->next = temp1;
}
