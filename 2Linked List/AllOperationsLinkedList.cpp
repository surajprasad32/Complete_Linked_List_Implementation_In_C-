#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;
};


// Creating the head pointer to the linked list, making it global so that everyone can access it
node* head = nullptr;

void insertAtEnd(){
	
	// Taking Data input
	int data;
	cout<<"Enter the Data You want to insert\n";
	cin>>data;

	// Making New node for insertion
	node* newNode = new node();
	newNode->data = data;
	newNode->next = nullptr;
	

	// Checking wheather it is the frist node or not 
	if(head == nullptr){
		head = newNode;
		return;
	}


	// If it is not the first node traversing to the end of the linked list
	node* temp = head;
	while(temp->next != nullptr){
		temp = temp->next;
	}

	// Setting the link to add the node in the linked lsit
	temp->next = newNode;

}

void print(){
	if(head == nullptr){
		cout<<"List is empty\n";
		return;
	}
	// Assigining head to new pointer to traverse the linked list
	node* temp = head;
	while(temp!=nullptr){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

void insertAtBegining(){

	// Taking input data to insert
	int data;
	cout<<"Enter the data you want to insert\n";
	cin>>data;

	// Making new node and setting it's data and next member
	node* newNode = new node();
	newNode->data = data;
	newNode->next = nullptr;

	// Checking wheather the new node is first node or not
	if(head == nullptr){
		head = newNode;
		return;
	}

	// If it is not new node setting the Links
	newNode->next = head;
	head = newNode;
}

void deleteAtend(){

	// Checking whether list is empty or not
	if(head == nullptr){
		return;
	}

	// If only one node then
	if(head->next == nullptr){
		delete head;
		head = nullptr;
		return;
	}
	// Making new pointer to praverse the list till end
	node* temp = head;
	while(temp->next->next!=nullptr){
		temp = temp->next;
	}

	// Updating pointers and deleting the heap memory
	node* free = temp->next;
	temp->next = nullptr;
	delete free;

}

void deleteAtBegining(){

	// Checking if list is empty
	if(head == nullptr){
		cout<<"List is empty\n";
		return;
	}

	// Move the head to the next node and delete the old head
	node* temp = head;
	head = temp->next;
	delete temp;
}

int length(){
	if(head == nullptr){
		cout<<"List is empty\n";
		return 0;
	}
	node* temp = head;
	int count = 0;
	while(temp!=nullptr){
		count++;
		temp = temp->next;
	}

	return count;
}

void insertAtKthPositionFromBegining(int k){
	if(k > length()+1 || k <= 0){
		cout<<"Out of length insertion\n";
		return;
	}
	if(k == length() || k == length() + 1){
		insertAtEnd();
		return;
	}
	if(k == 1){
		insertAtBegining();
		return;
	}
	int count = 1; // keep trak of the position
	int data; // To insert the elment;
	cout<<"Enter the Data you want to insert\n";
	cin>>data;
	node* newNode = new node();
	newNode->data = data;
	newNode->next = nullptr;

	if(head == nullptr){
		head = newNode;
		return;
	}

	node* temp = head;
	while(count < k-1){
		temp = temp->next;
		count++;
	}
	newNode->next = temp->next;
	temp->next = newNode;

}

void insertAtKthPositionFromEnd(int k , int length){
	if(k <= 0 || k > length + 1){
		cout<<"Invalid Insert operation\n";\
		return;
	}
	int finalPosition = length - k + 2;
	insertAtKthPositionFromBegining(finalPosition);
}

void deleteAtKthPositionFromBegining(int k){
	if(k <=0 || k > length()){
		cout<<"Invalid Delete operation";
		return;
	}
	if(k == 1){
		deleteAtBegining();
		return;
	}
	if(k == length()){
		deleteAtend();
		return;
	}

	int count = 1;
	node* pointer = head;
	while(count < k - 1){
		pointer = pointer->next;
		count++;
	}
	node* temp = pointer->next;
	pointer->next = pointer->next->next;
	delete temp;
}

void deleteAtKthPositionFromEnd(int k, int length){
	if(k <= 0 || k > length){
		cout<<"Invalid Delete operation\n";
		return;
	}
	int finalPosition = length - k + 1;
	deleteAtKthPositionFromBegining(finalPosition);
}

int main(){

	insertAtEnd();
	insertAtEnd();
	insertAtEnd();
	insertAtEnd();
	print();
	// insertAtBegining();
	// print();
	// cout<< length();
	// print();
	// deleteAtend();
	// print();
	// deleteAtBegining();
	// print();
	int k;
	cout<<"Enter the position from End where you want to insert\n";
	cin>>k;
	// insertAtKthPositionFromBegining(k);
	// print();
	// insertAtKthPositionFromEnd(k,length());
	// print();
	// deleteAtKthPositionFromBegining(k);
	// print();
	deleteAtKthPositionFromEnd(k,length());
	print();

	return 0;
}