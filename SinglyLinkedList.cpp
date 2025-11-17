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

	friend class List;
};

class List {
private:
	Node* List_head;
public:

	List() {
		List_head = nullptr;
	}
	Node* head() {
		return List_head;
	}
	bool empty() const {

		return (List_head == nullptr);
	}

	void DisplayList() {
		for (Node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
			cout << ptr->retrive() << " ";
		}
	}

	int count(int n) {
		int Count = 0;
		for (Node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
			if (ptr->retrive() == n) {
				Count += 1;
			}
		}
		return Count;
	}
	int size() {
		int Size = 0;
		for (Node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
			Size += 1;
		}
		return Size;
	}

	 int front() const {
		 if (empty()) {
			 throw underflow_error("The list is empty");
		 }
	    return List_head->retrive();
	};

	 void push_front(int n) {

		 Node* new_node = new Node(n, List_head);

		 List_head = new_node;
	 };
	int pop_front() {

		if (empty()) {
			throw underflow_error ("The list is empty!");
		}
		else {
			int e = front();
			Node* ptr = List_head;
			List_head = List_head->next();
			delete ptr;
			ptr = nullptr;

			return e;
		}
	};
	void push_end(int n) {
		Node* new_node = new Node(n, nullptr);
		if (empty()) {
			List_head = new_node;
		}
		else 
		{
			Node* ptr = List_head;
			while (ptr->next() != nullptr) {
				ptr = ptr->next_node;
			}
			ptr->next_node = new_node;

		}
	}
	int pop_end() {

		if (empty()) {
			throw underflow_error("The list is empty!");
		}
		if (List_head->next() == nullptr) {
			int Value = List_head->retrive();
			Node* ptr = List_head;
			delete ptr;
			ptr = nullptr;
			List_head = nullptr;
			return Value;
		}
		Node* last_node = nullptr;
		Node* prev_node = nullptr;
		for (Node* ptr = head(); ptr != nullptr; ptr = ptr->next()) {

			if (ptr->next() == nullptr) {
				last_node = ptr;
				break;
			}
			prev_node = ptr;
		}
		int Value = last_node->retrive();
		delete last_node;
		prev_node->next_node = nullptr;

		return Value;
	}
	void erase(int val) {

		//case 1
		if (empty()) {
			throw underflow_error("The list is already empty!");
		}

		else {
			// case 2
			while (List_head != nullptr && List_head->retrive() == val) {
				Node* temp = head();
				List_head = List_head->next_node;
				delete temp;

			}
			// case 3
			Node* Current = head();
			for (Node* ptr = List_head; ptr != nullptr; ptr = ptr->next()) {

				if (ptr->retrive() == val) {
					Current->next_node = ptr->next();
					delete ptr;
					ptr = nullptr;
					ptr = Current;

				}
				Current = ptr;

			}
		}

	}
};

int main() {
	List li;
	li.push_front(55);
	li.push_end(88);
	li.pop_end();
	li.DisplayList();
	return 0;
}

