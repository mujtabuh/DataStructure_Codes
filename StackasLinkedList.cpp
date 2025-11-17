#include<iostream>
using namespace std;
class node {
protected:
	int element;
	node* next_node;
public:
	node(int e = 0, node* n = nullptr) : element(e), next_node(n)
	{
	}
	int retrieve()const {
		return element;
	}
	node* next() const {
		return next_node;
	}
	friend class list;
	friend class list;
};
class list {
private:
	node* list_head;
public:
	list() :list_head(nullptr)
	{
	}
	int count(int n) {
		int count = 0;
		for (node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
			if (ptr->retrieve() == n) {
				count = count + 1;
			}
		}
		return count;
	}
	int size() {
		int count = 0;
		for (node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {

			count = count + 1;
		}
		return count;
	}
	void display() {
		for (node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
			cout << ptr->retrieve() << " ";
		}

	}
	void push_end(int n) {
		node* new_node = new node(n, nullptr);
		if (empty()) {
			list_head = new_node;
			return;
		}
		node* ptr = list_head;
		while (ptr->next() != nullptr) {
			ptr = ptr->next_node;
		}
		ptr->next_node = new_node;
	}
	void pop_end() {
		if (empty()) {
			throw underflow_error("list is empty");
		}

		if (list_head->next_node == nullptr) {
			delete list_head;
			list_head = nullptr;
			return;
		}
		node* last = head();
		node* curr = head()->next_node;
		while (curr->next_node != nullptr) {
			last = curr;
			curr = curr->next_node;
		}
		last->next_node = nullptr;
		delete curr;

	}
	void push_front(int a) {
		list_head = new node(a, list_head);
	}
	int pop_front() {
		if (empty()) {
			cout << "List is empty! Cannot pop." << endl;
			return -1;
		}

		node* old_head = list_head;
		list_head = old_head->next();
		delete old_head;
	}
	int erase(int n) {
		//if list is epmty //
			if (empty()) {
				throw underflow_error("list is empty");
				return 0;
			}
		// if the element you want to remove is the first node /
			node * old_head = list_head;
		if (list_head->element == n) {
			list_head = old_head->next_node;
			delete old_head;
			return 1;
		}
		// if list have only one elemt /
			if (list_head->next_node == nullptr) {
				delete list_head;
				list_head = nullptr;
			}
		// if the element you want to erase is the tail of the list /
			node * last = list_head;
		node* curr = list_head->next_node;
		while (curr->next_node != nullptr) {
			last = curr;
			curr = curr->next_node;
		}
		last->next_node == nullptr;
		delete curr;
		// if you want to erase in between /
			node * previous = list_head;
		int node_count = 0;
		for (node* ptr = head(); ptr != nullptr; ptr = ptr->next_node) {
			if (ptr->retrieve() == n) {
				previous->next_node = ptr->next_node;
				delete ptr;
				++node_count;

			}
			previous = ptr;
		}
		return node_count;
	}
	int front() const {
		if (list_head == nullptr) {
			cout << "List is empty!" << endl;
			return -1;
		}
		return list_head->retrieve();
	}
	int end()const;
	node* head()const
	{
		return list_head;
	}
	bool empty() {
		if (list_head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
};
class stack {
protected:
	list* l;
public:
	stack(list* existing_list) {
		l = existing_list;
	}
	void push(int x) {
		l->push_front(x);
	}
	void pop() {
		l->pop_front();
	}
	void displaystack() {
		l->display();
	}
};
int main() {
	list l;
	l.push_front(10);
	l.push_front(13);
	l.push_front(40);
	l.push_front(15);
	l.display();
	stack s(&l);
	s.push(20);
	s.push(30);
	s.pop();
	s.displaystack();
	cout << endl;
}