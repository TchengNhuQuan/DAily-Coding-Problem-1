#include <iostream>
using namespace std;

class Node {
    public: 
    int value;
    Node * xpn;

    Node(int new_value){
        value = new_value;
    }
    static Node *XOR (Node *prev, Node *next) {
        reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(prev) ^ reinterpret_cast<uintptr_t>(next));
    }
};


class XOR_LL {
    public: 
    Node *head = NULL;
    Node *tail = NULL;
    int length = 0;
    XOR_LL(Node* head_node) {
        head = head_node;
        tail = head_node;
        length += 1;
    }

    void add(int value) {
        Node *new_node = new Node(value);
        new_node->xpn =Node::XOR(tail->xpn, NULL);
        if (tail != NULL) {
            // Node* next = Node::XOR(tail->xpn, NULL); // chua hieu lam
            tail->xpn = Node::XOR(tail->xpn, new_node); 
            // tail->xpn = Node::XOR(new_node, tail->xpn); // chua hieu lam
        }
        length += 1;
        tail = new_node;
    }

    Node *get(int index) {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        for (int i = 0; i < index; i++) {
            next = Node::XOR(prev, curr->xpn);
            prev = curr;
            curr = next;
        }
        return curr;
    }

    void print_list() {
        Node *curr = head;
        Node* prev = NULL;
        Node *next = NULL;
        cout << "The XOR linked list contains: ";

        while (curr != NULL) {
            cout << curr->value << " ";
            next = Node::XOR(prev, curr->xpn);
            prev = curr;
            curr = next;
        }
        cout << "\n";
    }
};

int main () {
    Node *head = new Node(1);
    XOR_LL xor_ll(head);
    xor_ll.add(2);
    xor_ll.add(3);
    xor_ll.add(4);
    xor_ll.add(5);
    xor_ll.add(6);

    xor_ll.print_list();
    int index = 3;
    Node *index_node = xor_ll.get(index);
    cout << "the value of xor_ll at index " << index << " is " << index_node->value << "\n";
    return 0;
}

