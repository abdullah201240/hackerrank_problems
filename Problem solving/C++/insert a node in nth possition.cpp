#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node)
{
    while (node)
    {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

 SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data)
{
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL)
    {
        head = newNode;
    }
    else
    {
        SinglyLinkedListNode *temp=head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return head;
}
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    newNode->data=data;
    newNode->next=NULL;
    if(llist==NULL){
        llist=newNode;
    }
    else{
        newNode->next=llist;
        llist=newNode;
    }
return llist;
}
int list_size(SinglyLinkedListNode *temp)
{
    int i=0;
    while(temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{
    SinglyLinkedListNode *temp;
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    newNode->data=data;
    newNode->next=NULL;
    if(position==0)
    {
       llist=insertNodeAtHead(llist,data);
    }
    else if(position == list_size(llist)+1)
    {
        llist=insertNodeAtTail(llist,data);
    }
    else
    {
        temp=llist;

        while(position-1 > 0)
        {
            temp=temp->next;
            position--;
        }
        newNode->next = temp->next;
        temp->next = newNode;

    }
    return llist;
}
void printLinkedList(SinglyLinkedListNode* head) {
    while(head !=NULL){
            cout<<head->data<<endl;
        head=head->next;
    }


}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);
    printLinkedList(llist->head);

    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();

    return 0;
}

