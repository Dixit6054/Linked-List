#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	int key;
};
Node* insert(Node**,int , Node*,int);
void Print(Node**);
void Merge_Sort(Node*,int,int);
main()
{
	Node* head = NULL;
	Node* last = head;
	int n;
	cout << "Enter the size of linked list: ";
	cin>>n;
	cout << "Yes now enter the elements: ";
	int x;
	for(int i=0; i <= n-1 ; i++)
	{
		cin>>x;
		last = insert(&head,x,last,i+1);
	}
	Print(&head);
	Merge_Sort(head,0,n);
	
}

Node* insert(Node** head , int x , Node* last ,int key)
{
	
	Node* temp = new Node;
	temp->key = key;
	temp->data = x;
	temp->next = NULL;
	if(last == NULL)
	*head = temp;
	else
	last->next = temp;
	last = temp;
	return last;
}

void Print(Node** head)
{
	Node* temp = *head;
	while(temp != NULL)
	{
		cout << temp->key <<": " << temp->data <<"      ";
		temp = temp->next;
	}
}

void Merge_Sort(Node* head, int start , int end)
{
	int mid = (start + end) / 2;
	//creating new lists;
	Node* head1 = NULL;
	Node* temp = head;
	cout <<"lol";
	while(temp->key != start)        //	for (int i=1; i < start ; i++)		//		//i<start is important;
	{
		temp = temp->next;
	}
	cout <<"lol";
	Node* last = head1;	
										//I can not make this head1 in heap beacuse ia want it to be differtent for every recrusive call;
	//for(int i= start; i <= mid ; i++)
	int j = 1;
	while(temp->key != end)
	{
		last =	insert(&head1,temp->data,last,j);
		temp = temp->next;
		j++;
	}
	Print(&head1);
	/*Node* head2 = NULL;
	last = head2;
	j=1;
	for(int i= mid+1 ; i <= end ; i++)
	{
		last = insert(&head2,temp->data,last,j);
		temp = temp->next;
		j++;
	}
	Print(&head1);cout << endl;
	Print(&head2);*/
}


















