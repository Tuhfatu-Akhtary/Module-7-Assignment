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

//Function to Merge the linked lists
Node* MergeList(Node* list1,Node* list2)
{
    Node* head,*current;
    if(list1==nullptr)
    {
        return list2;
    }
    else if(list2==nullptr)
    {
        return list1;
    }

    head=list1;
    if(list2->data<head->data)
    {
        head=list2;
        list2=list2->next;
    }
    else{
        list1=list1->next;
    }
    current=head;

    while(list1!=nullptr&&list2!=nullptr){
        if(list1->data<list2->data)
        {
            current->next=list1;
            list1=list1->next;
        }
        else{
            current->next=list2;
            list2=list2->next;
        }
        current=current->next;
    }
    if(list1!=nullptr)
    {
        current->next=list1;
    }
    else if(list2!=nullptr)
    {
        current->next=list2;
    }

    return head;
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
    int n,s,i,k,j,s1;
    cin>>n>>k;
    Node* list1=nullptr;
    Node* list2=nullptr;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        append(list1,s);
    }
    for(int i=0;i<n;i++)
    {
        cin>>s1;
        append(list2,s1);
    }
    MergeList(list1,list2);
    display(head);

    return 0;
}


Time Complexity: O(n)
Space Complexity: O(1)