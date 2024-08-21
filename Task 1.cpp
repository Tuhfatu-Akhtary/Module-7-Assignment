//Defination of structure of node
struct Node{
    int data;
    Node* next;
};

//Function to create each node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data=data;
    newNode->next=nullptr;
    return newNode;
}

//Function to append each node to the list
void append(Node*& head,int data)
{
    Node* newNode=createNode(data);
    if(head==nullptr)
    {
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next !=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;

}

//Function to reverse the linked list
void reverse(Node*& head)
{
    Node* prev=nullptr;
    Node* current=head;
    Node* next=nullptr;

    while(current!=nullptr)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }

    head=prev;
}

//Fuction to display the reversed list
void display(Node* head){
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//Main Function
int main() {
    int n,s,i;
    cin>>n;
    Node* head=nullptr;
    for(int i=0;i<n;i++)
    {
        append(head,s);
    }
    reverse(head);
    display(head);

    return 0;
}


Time Complexity: O(n)
Space Complexity: O(1)