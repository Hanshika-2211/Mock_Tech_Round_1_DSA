#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == nullptr)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; 
}

Node *removeLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head; 
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break; 
        }
    }

    if (slow != fast)
    {
        return head; 
    }

    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr; 

    return head;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void createLoop(Node *head, int loopNode)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = head->next->next; 
}

int main()
{
    Node *head = nullptr;
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        insertNode(&head, data);
    }

    cout << "Original List: ";
    printList(head);

    char choice;
    cout << "Do you want to create a loop? (y/n): ";
    cin >> choice;

    if (choice == 'y')
    {
        int loopNode;
        cout << "Enter the node number to create a loop (1-indexed): ";
        cin >> loopNode;
        createLoop(head, loopNode);
    }

    head = removeLoop(head);

    cout << "List after removing loop: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}