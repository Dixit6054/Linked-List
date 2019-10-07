#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

void print(node* head)
{
	if(!head)
	return;
	while(head)
	{
		cout << head->data <<" ";
		head= head->next;
	}
	cout <<endl;
}

void insert(node** head, node** last, int data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	
	if(!*head)
	*head = temp;
	if(*last)
	(*last)->next = temp;
	*last = temp;
}
bool result =true;

bool ispalindrom(node** head, node* temp)
{
//	if(*head==NULL || (*head) ->next == NULL)
//	return true;
	if(temp ==NULL)
	return true;
	
	result = result & ispalindrom(head, temp->next);
	
	if((*head)->data != temp->data )
	result= false;
	
	if(*head == temp)		// for odd linked list
	result= true;
	
	if((*head)->next == temp)		//for even list
	result= true;
	
	*head = (*head)->next;
	
	return result;
}
main()
{
	node* head = NULL;
	node* last = NULL;
	insert(&head, &last, 1);
	insert(&head, &last, 2);
	insert(&head, &last, 3);
	insert(&head, &last, 2);
	insert(&head, &last, 1);
//	insert(&head, &last, 1);
//	insert(&head, &last, 1);
	print(head);
	cout << "\n" << ispalindrom(&head,head)<<endl;
//	print(head);
	
		
}

