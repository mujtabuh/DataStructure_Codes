#include<iostream>
#include<stdexcept> 

using namespace std;

class Node {
private:
    int element;
    Node* next_node;

public:
    Node(int e = 0, Node* n = nullptr) : element(e), next_node(n) {
    };

    int retrive() const {
        return element;
    };
    Node* next() const {
        return next_node;
    };

    void setElement(int e) {
        element = e;
    }

    void setNext(Node* n) {
        next_node = n;
    }
    friend class CircularList;
};

class CircularList {
private:
    Node* list_head;

public:
    CircularList() {
        list_head = nullptr;
    }
    ~CircularList() {
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

    void DisplayList() {
        if (empty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* ptr = head();
        do {
            cout << ptr->retrive() << " ";
            ptr = ptr->next();
        } while (ptr != head());
        cout << endl;
    }

    int count(int n) const {
        if (empty()) {
            return 0;
        }

        int node_count = 0;
        Node* ptr = head();
        do {
            if (ptr->retrive() == n) {
                node_count++;
            }
            ptr = ptr->next();
        } while (ptr != head());
        return node_count;
    }

    int size() const {
        if (empty()) {
            return 0;
        }

        int node_count = 0;
        Node* ptr = head();
        do {
            node_count++;
            ptr = ptr->next();
        } while (ptr != head());
        return node_count;
    }

    int front() const {
        if (empty()) {
            throw underflow_error("Underflow: The list is empty");
        }
        return head()->retrive();
    }

    int end() const {
        if (empty()) {
            throw underflow_error("Underflow: The list is empty");
        }

        Node* ptr = head();
        while (ptr->next() != head()) {
            ptr = ptr->next();
        }
        return ptr->retrive();
    }

    void push_front(int n) {
        Node* p = new Node(n);
        if (empty()) {
            p->setNext(p); 
            list_head = p;
        }
        else {
      
            Node* ptr = head();
            while (ptr->next() != head()) {
                ptr = ptr->next();
            }
            p->setNext(head()); 
            ptr->setNext(p); 
            list_head = p;
        }
    }
    int pop_front() {
        if (empty()) {
            throw underflow_error("Underflow: The list is empty!");
        }

        int e = front();
        Node* ptr = head(); 

        if (list_head->next() == head()) {
            list_head = nullptr;
        }
        else {
            Node* p = head();
            while (p->next() != head()) {
                p = p->next();
            }
            list_head = list_head->next();
            p->setNext(list_head); 
        }

        delete ptr;
        ptr = nullptr;
        return e;
    }

    void push_end(int n) {
        if (empty()) {
           
            push_front(n);
        }
        else {
          
            Node* ptr = head();
            while (ptr->next() != head()) {
                ptr = ptr->next();
            }

            Node* newnode = new Node(n, nullptr);
            ptr->setNext(newnode); 
            newnode->setNext(head()); 
        }
    }

    int pop_end() {
        if (empty()) {
            throw underflow_error("The list is empty!");
        }

        if (list_head->next() == head()) {
           
            return pop_front();
        }

        Node* ptr = head();
        Node* prev = head();
        while (ptr->next() != head()) {
            prev = ptr;
            ptr = ptr->next();
        }

        int e = ptr->retrive(); 
        delete ptr; 
        prev->setNext(head()); 

        return e;
    }

    void erase(int val) {
        if (empty()) {
            throw underflow_error("The list is already empty!");
        }

        while (!empty() && head()->retrive() == val) {
            pop_front();
        }
        if (empty()) {
            return;
        }
        Node* current = head()->next();
        Node* prev = head();

        do {
            if (current->retrive() == val) {
                prev->setNext(current->next()); 
                Node* temp = current;
                current = current->next(); 
                delete temp; 
            }
            else {
                
                prev = current;
                current = current->next();
            }
        } while (current != head()); 
    }
};

int main() {
    CircularList li;

    cout << "Pushing 55 to front:" << endl;
    li.push_front(55); // List: 55
    li.DisplayList();

    cout << "Pushing 88 to end:" << endl;
    li.push_end(88);   
    li.DisplayList();

    cout << "Pushing 99 to end:" << endl;
    li.push_end(99);   
    li.DisplayList();

    cout << "Front element: " << li.front() << endl; 
    cout << "End element: " << li.end() << endl;  
    cout << "List size: " << li.size() << endl;  

    cout << "Popping end: " << li.pop_end() << endl;
    li.DisplayList(); 

    cout << "Popping front: " << li.pop_front() << endl;
    li.DisplayList();

    cout << "List size: " << li.size() << endl; 

    cout << "Popping last element: " << li.pop_end() << endl; 
    li.DisplayList(); 
    cout << "List size: " << li.size() << endl; 
    li.push_front(5);
    li.push_front(5);
    li.push_end(10);
    li.push_end(20);
    li.push_end(5);
    li.push_end(20);
    li.push_end(5);
    cout << "Original list: ";
    li.DisplayList(); 

    cout << "Erasing all 5s..." << endl;
    li.erase(5);
    li.DisplayList(); 

    cout << "Erasing all 20s..." << endl;
    li.erase(20);
    li.DisplayList(); 

    cout << "Erasing 10..." << endl;
    li.erase(10);
    li.DisplayList(); 

    return 0;
}