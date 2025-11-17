#include <iostream>
#include <stdexcept> 

using namespace std;

class Node {
private:
    int element;
    Node* next_node;
    Node* prev_node;

public:
   
    Node(int e = 0, Node* n = nullptr, Node* p = nullptr)
        : element(e), next_node(n), prev_node(p) {
    };

    int retrieve() const {
        return element;
    }

    Node* next() const {
        return next_node;
    }

    Node* previous() const { 
        return prev_node;
    }
    void setnext(Node* n) {
        next_node = n;
    }

    void setelement(int e) {
        element = e;
    }

    void setprevious(Node* n) {
        prev_node = n;
    }
};
.
class DoublyList {
private:
    Node* list_head;

public:
    DoublyList() : list_head(nullptr) {
        
    }

    ~DoublyList() {
        while (!empty()) {
            pop_front();
        }
    }

    Node* head() const {
        return list_head;
    }

    bool empty() const {
      return (list_head == nullptr);
    }

    int front() const {
        if (empty()) {
            throw underflow_error("Underflow: List is empty");
        }
        else {
            return head()->retrieve();
        }
    }
    int end() const {
        if (empty()) {
            throw underflow_error("Underflow: List is empty");
        }

        Node* ptr;
       
        for (ptr = head(); ptr->next() != nullptr; ptr = ptr->next()) {
         
        }
        return ptr->retrieve();
    }
    int size() const {
        int count = 0;
        for (Node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
            count++;
        }
        return node_count;
    }

    int count(int n) const {
        int node_count = 0;
        for (Node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
            if (ptr->retrieve() == n) {
                node_count++;
            }
        }
        return node_count;
    }
    void DisplayList() {
        for (Node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
            cout << ptr->retrieve() << " ";
        }
    }

    //Mutators
    void push_front(int n) {
        Node* new_node = new Node(n, head(), nullptr);

        if (!empty()) {

            head()->setprevious(new_node);
        }
        list_head = new_node;
    }

    int pop_front() {
        if (empty()) {
            throw underflow_error("Underflow: List is empty");
        }

        int e = front(); 
        Node* ptr = head(); 

        list_head = list_head->next();

        if (list_head != nullptr) {
            list_head->setprevious(nullptr);
        }

        delete ptr; 
        ptr = nullptr;
        return e;
    }

    void push_end(int n) {
        if (empty()) {
            push_front(n); 
            return;
        }
        Node* last = head();
        for (Node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
            last = ptr;
        }

        Node* new_node = new Node(n, nullptr, last); 
        last->setnext(new_node); 
    }
    int pop_end() {
        if (empty()) {
            throw underflow_error("Underflow: List is empty");
        }

        Node* ptr = head();
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }


        int e = ptr->retrieve();
        // one node only
        if (ptr == head()) {
            delete ptr;
            list_head = nullptr;
        }
        else {
            ptr->previous()->setnext(nullptr);
            delete ptr;
        }

        return e;
    }

    int erase(int val) {
        if (empty()) {
            throw underflow_error("The list is empty!"); // Nothing to erase
        }

        int instances_erased = 0;

        // --- Case 1: Deleting from the head ---
        while (list_head != nullptr && list_head->retrieve() == val) {
            pop_front(); 
            instances_erased++;
        }

        if (list_head == nullptr) {
            return instances_erased;
        }

        Node* ptr = head();
        while (ptr != nullptr) {
            if (ptr->retrieve() == val) {
                Node* node_to_delete = ptr;

                node_to_delete->previous()->setnext(node_to_delete->next());

                if (node_to_delete->next() != nullptr) {
                    // Middle
                    node_to_delete->next()->setprevious(node_to_delete->previous());
                }
                ptr = ptr->next();
                delete node_to_delete;
                instances_erased++;
            }
            else {
                ptr = ptr->next();
            }
        }
        return instances_erased;
    }
};

int main() {
    DoublyList list;

    list.push_front(500);
    list.push_front(5000);
    list.push_end(100);
    list.push_front(100);
    list.push_end(11);
    list.push_end(55);
    list.push_end(100);
    cout << "Initial List: ";
    list.DisplayList();
    cout << endl;

    cout << "Front element: " << list.front() << endl;
    cout << "End element: " << list.end() << endl;


    cout << "Popping: " << list.pop_end() << endl; 
    cout << "Popping: " << list.pop_end() << endl; 
    cout << "Popping: " << list.pop_end() << endl; 

    cout << "Final List: ";
    list.DisplayList();
    cout << endl;

    DoublyList list2;
    list2.push_end(10);
    list2.push_end(20);
    list2.push_end(30);
    list2.push_end(20);
    list2.push_end(10);
    cout << "\nList for erase test: ";
    list2.DisplayList(); 
    cout << endl;

    cout << "Erasing all 10s..." << endl;
    list2.erase(10); 
    cout << "After erasing 10: ";
    list2.DisplayList(); 
    cout << endl;

    cout << "Erasing all 20s" << endl;
    list2.erase(20); 
    cout << "After erasing 20: ";
    list2.DisplayList(); 
    cout << endl;

    cout << "Erasing 30" << endl;
    list2.erase(30); 
    cout << "After erasing 30: ";
    list2.DisplayList(); 
    cout << "\nIs list empty? " << (list2.empty() ? "Yes" : "No") << endl;

    return 0;
}