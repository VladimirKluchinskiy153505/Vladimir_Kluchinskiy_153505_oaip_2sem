#include <C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\New_String\New_String.cpp>
#include <C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\My_Vec\My_Vec.cpp>
#include<C:\Users\avdot\Desktop\LabRab3\3LabRabKluchinskiy\New_Stack\New_Stack.cpp>
#include<C:\Users\avdot\Desktop\LabWorks\24LabRabKluchinskiy\MyPair\MyPair.cpp>
using namespace std;

void checkin(my_vec<int>& vec) {
	MyString str, str1;
 	Getline(cin, str);
	cout << str << '\n';
	int first = -1, second;

	while (str.find(" ", first + 1) != -1) {
		second = str.find(" ", first + 1);
		str1 = str.substr(first + 1, second - first - 1);
		vec.push_back(atoi(str1.c_str()));
		first = second;
	}
	str1 = str.substr(first + 1, str.size() - first - 1);
	vec.push_back(atoi(str1.c_str()));
}
int main() {
	my_vec<int> tempr;
	checkin(tempr);
	size_t size = tempr.size();
	my_vec <int> answer(size,0);
	my_stack <my_pair<int,int>> Steck;
	for (int i = size - 1; i >= 0; --i) {
		while (!Steck.empty() && (Steck.top().first <= tempr[i]))//пока стек не пустой и верхушка стека меньше= текущей температуры удаляем из него элементы
		{
			Steck.pop();
		}
		if (!Steck.empty()) {
			answer[i] = Steck.top().second - i;
			//cout<<
		}
		Steck.push(my_pair<int,int>(tempr[i], i));
	}
	for (auto now : answer)
	{
		cout << now << " ";
	}
	return 0;
}