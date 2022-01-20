#include <iostream>

using namespace std;

class Node {
public:

    Node *next;
    int data;

    Node() = default;

    static Node *create_list(Node *head);

    static Node *create_list();

    static void print(Node *head);

    static void reversePrint(Node *head);

    static int size(Node *head);

    static bool equality(Node *head1, Node *head2);

    static bool search(Node *head, int x);

    static void split(Node *source, Node **frontsp, Node **backsp);

    static Node *mergeSorted(Node *head1, Node *head2);

    static Node *mergeSort(Node *head);

//    static bool searchUnsorted(Node *head, int x);

    static void appendList(Node *head1, Node *head2);

    static Node *deleteNth(Node *head, int n);

    static Node *deleteFront(Node *head);

    static Node *deleteLast(Node *head);

    static bool isAscending(Node *head);

    static bool isDescending(Node *head);

    static bool isSorted(Node *head);

    static Node *insertAtFront(Node *head, int x);

    static Node *insertAtN(Node *head, int data, int position);

    static Node *insertAtEnd(Node *head1, int x);

    static Node *removeDup(Node *head);

    static Node *moveLtoF(Node *head);

    static Node *delAlternative(Node *head);

    static Node *moveFtoL(Node *head);

    static void rotate(Node *head);

    void delList(Node *head);

    static Node *recursive(Node *head);

    static bool notEqual(Node *head1, Node *head2);

    static void deleteByValue(Node *head, int value);


};

Node *Node::create_list(Node *head) {
    Node *temp;
    string input;
    try {
        while (true) {
            cout << "Enter data\n";
            cin >> input;
            int num = stoi(input);
            if (head == nullptr) {
                head = (Node *) malloc(sizeof(Node));
                head->data = num;
                head->next = nullptr; // nexts the address field to nullptr
                temp = head;
            } else {
                Node *temp1 = (Node *) malloc(sizeof(Node));
                temp1->data = num;      // nexts the num field of fnNode with num
                temp1->next = nullptr; // nexts the address field of fnNode with nullptr

                temp->next = temp1; // nexts previous Node i.e. tmp to the fnNode
                temp = temp->next;
            }
        }
    } catch (...) {
        return head;
    }

}

Node *Node::create_list() {
    Node *temp = nullptr;
    Node *head = temp;
    string input;
    try {
        while (true) {
            cout << "Enter data\n";
            cin >> input;
            int num = stoi(input);
            if (head == nullptr) {
                head = (Node *) malloc(sizeof(Node));
                head->data = num;
                head->next = nullptr; // nexts the address field to nullptr
                temp = head;
            } else {
                Node *temp1 = (Node *) malloc(sizeof(Node));
                temp1->data = num;      // nexts the num field of fnNode with num
                temp1->next = nullptr; // nexts the address field of fnNode with nullptr

                temp->next = temp1; // nexts previous Node i.e. tmp to the fnNode
                temp = temp->next;
            }
        }
    } catch (...) {
        return head;
    }

}

void Node::print(Node *head) {
    if (head == nullptr) return;
    Node *temp = head;
    cout << "List is :\n";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void Node::reversePrint(Node *head) {
    if (head == nullptr) return;
    reversePrint(head->next);
    cout << head->data << " ";
}

int Node::size(Node *head) {
    if (head == nullptr) return 0;
    int i = 0;
    while (head != nullptr) {
        head = head->next;
        i++;
    }
    cout << i << endl;
    return i;
}

bool Node::equality(Node *head1, Node *head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) { return false; }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == nullptr && head2 == nullptr);
}


void Node::split(Node *source, Node **frontsp, Node **backsp) {
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontsp = source;
    *backsp = slow->next;
    slow->next = nullptr;
}

Node *Node::mergeSorted(Node *head1, Node *head2) {
    Node *temp;
    Node *newHead;
    if (head1->data >= head2->data) {
        temp = head2;
        head2 = temp->next;
    } else {
        temp = head1;
        head1 = temp->next;
    }
    newHead = temp;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data >= head2->data)  //big
        {
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        } else {//small
            temp->next = head1;    // temp->next = head2;
            temp = head1;   // temp = head2;
            head1 = head1->next;

        }
    }
    if (head1 == nullptr) temp->next = head2;
    if (head2 == nullptr) temp->next = head1;
    return newHead;
}

Node *Node::mergeSort(Node *head) {
    Node *temp = head;
    Node *a;
    Node *b;

    if ((temp == nullptr) || (temp->next == nullptr)) {
        return head;
    }
    split(head, &a, &b);
    a = mergeSort(a);
    b = mergeSort(b);
    head = mergeSorted(a, b);
    return head;
}

bool Node::search(Node *head, int x) {
    Node *current = head;  // Initialize current
    while (current != nullptr) {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

/*
bool Node::searchUnsorted(Node *head, int x) {
    head = mergeSort(head);
    return search(head, x);
}*/

void Node::appendList(Node *head1, Node *head2) {
    Node *temp = head1;
    while (temp->next != nullptr) { temp = temp->next; }
    temp->next = head2;
    print(head1);
}

Node *Node::insertAtFront(Node *head, int x) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = x;
    temp->next = nullptr;
    if (head != nullptr) {
        temp->next = head;
    }
    head = temp;
    return head;
}

Node *Node::insertAtN(Node *head, int data, int position) {
    int size = Node::size(head);
    if (position > size + 1) {
        cout << "List has length of " << size;
        return head;
    }
    int i;
    Node *temp1 = (Node *) malloc(sizeof(Node));
    temp1->data = data;
    temp1->next = nullptr;
    if (position == 1) {
        return Node::insertAtFront(head, data);
    }
    Node *temp2 = head;
    for (i = 0; i < position - 2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    return head;
}

Node *Node::insertAtEnd(Node *head1, int x) {
    Node *temp1 = head1;
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = x;
    temp->next = nullptr;
    while (temp1->next != nullptr) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return (head1);
}

void Node::delList(Node *head) {
    if (head == nullptr) return;
    delList(head->next);
    free(head);
    cout << "List deleted.";
}

Node *Node::deleteNth(Node *head, int n) {
    if (n < 1) {
        return head;
    }
    int i;
    Node *temp1 = head;
    if (n == 1) {
        head = head->next;
        return head;
    }
    for (i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return head;
}

void Node::deleteByValue(Node *head, int value) {
    print(head);
    Node *temp = head;
    while (temp->next->data != value) {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    print(head);
}

Node *Node::deleteFront(Node *head) {
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *Node::deleteLast(Node *head) {
    Node *temp1 = head;
    while (temp1->next->next != nullptr) {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return head;
}

bool Node::isAscending(Node *head) {
    while (head != nullptr && head->next != nullptr) {
        if (head->data > head->next->data) { return false; } //NOt Ascend
        head = head->next;
    }
    return true;
}


bool Node::isDescending(Node *head) {
    while (head != nullptr && head->next != nullptr) {
        if (head->data < head->next->data) { return false; } //NOt DEScend
        head = head->next;
    }
    return true;
}

bool Node::isSorted(Node *head) {
    bool ans = false;
    if (!isAscending(head)) {
        if (!isDescending(head)) {
            cout << "Array unordered.\n";
        } else {
            cout << "Array in Descending order.";
            ans = true;
        }
    } else {
        cout << "Array in Ascending order.";
        ans = true;
    }
    return ans;
}
Node *Node::removeDup(Node *head) {
    if (head == nullptr) {
        cout << "List Empty.";
        return head;
    }
    Node *temp = head;
    Node *temp1;
    while (temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            temp1 = temp->next->next;
            free(temp->next);
            temp->next = temp1;
        } else {

            temp = temp->next;
        }
    }
    print(head);
    return head;
}

Node *Node::delAlternative(Node *head) {
    if(head == nullptr){
        return  head;
    }
    Node *prev = head;
    Node *node = head->next;
    while (prev != nullptr && node != nullptr) {
        prev->next = node->next;
        free(node);
        prev = prev->next;
        if (prev != nullptr) {
            node = prev->next;
        }
    }
    return head;
}

Node *Node::moveLtoF(Node *head) {
    Node *lastsPrev = head;
    Node *lastNode = head->next;
    Node *oldHead = head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
        lastsPrev = lastsPrev->next;
    }
    head = lastNode;
    lastNode->next = oldHead;
    lastsPrev->next = nullptr;
    print(head);
    return head;
}

Node *Node::moveFtoL(Node *head) {
    Node *lastNode = head;
    Node *newHead = head->next;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;

    }
    lastNode->next = head;
    head = newHead;
    lastNode->next->next = nullptr;
    return head;
}

void Node::rotate(Node *head) {
    int n, i;
    cout << "Enter key value:\n";
    cin >> n;

    for (i = 0; i < n; i++) {
        head = moveFtoL(head);
    }
    print(head);

}

Node *Node::recursive(Node *head) {
    if (head->next == nullptr) {
        return head;
    }
    Node *newHead = recursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

bool Node::notEqual(Node *head1, Node *head2) {
    return !equality(head1, head2);
}

