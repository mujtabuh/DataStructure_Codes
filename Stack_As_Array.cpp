#include<iostream>
using namespace std;

class stack {
protected:
	int size;
	int top;
	int* arr;
public:
	stack(int s = 10, int t = -1) {
		size = s;
		top = t;
		arr = new int[size];
	}
	bool is_empty() {

		return(size == 0);

	}
	bool is_full() {
		if (top == size - 1) {
			return true;
		}
		else {
			return false;
		}
	}
	void push_item(int value) {
		if (is_full()) {
			cout << "previous array has size " << size << " .So the size is full ,we are creating double the size of the previous array:" << endl;
			int* new_array = new int[size * 2];
			for (int i = 0; i < size; i++) {
				new_array[i] = arr[i];

			}
			delete[] arr;
			arr = new_array;
			size = size * 2;
		}
		arr[++top] = value;
	}
	void pop_item() {
		if (is_empty()) {
			throw underflow_error("list is empty");
			return;
		}
		int delete_item = arr[top--];
		cout << "the value you poped is: " << delete_item << endl;
	}
	void display() {
		if (is_empty()) {
			throw underflow_error("stack is empty");
			return;
		}
		cout << "the elements of stack are: ";
		for (int i = 0; i <= top; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int stack_size() {
		return (top + 1);
	}
	~stack() {
		delete[] arr;
	}

};
int main() {
	try {
		stack s(3);
		s.push_item(10);
		s.push_item(30);
		s.push_item(15);
		s.push_item(31);
		cout << (s.is_empty() ? " empty" : "not empty") << endl;
		s.display();
		cout << "the number of elemnts in the stack are: " << s.stack_size() << endl;
		s.pop_item();
		s.pop_item();
		s.pop_item();
		s.pop_item();

		s.display();
	}
	catch (const underflow_error& e) {
		cout << "Error: " << e.what() << endl;
	}
	return 0;

}
