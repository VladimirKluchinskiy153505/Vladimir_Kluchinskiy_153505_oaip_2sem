#include <iostream>
#include "C:\Users\avdot\Desktop\LabWorks\LabRab25\Linked_List\Linked_List.cpp"
int main() {
	my_queue<int> que;
	for (int i = 0; i < 10; ++i) {
		que[i] = 100 + i;
	}
	for (int i = 0; i < que.size() - 1; ++i) {
		std::cout << que[i]<<' ';
	}
	cout << '\n';
	que.clear();
	que.push_back(999);
	for (int i = 0; i < que.size() - 1; ++i) {
		std::cout << que[i]<<" ";
	}
	return 0;
}

