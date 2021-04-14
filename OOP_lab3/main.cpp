#include "Stack.h"
#include "Employee.h"
#include "FileIO.h"

int ent_int(std::istream& in, double min, double max) {
	double i;
	int flags;
	do {
		try {
			flags = 0;
			std::cout << "Enter the number... ";
			in >> i;
			if (!std::cin || std::cin.peek() != '\n') {
				throw 1;
			}
			if (i < min || i > max) {
				throw 'a';
			}
		}
		catch (int) {
			flags = 1;
			std::cout << "It's not a (type) number!!!\n\n";
			std::cin.clear(0);
			rewind(stdin);
		}
		catch (char) {
			flags = 1;
			std::cout << "Out of range.\n\n";
			std::cin.clear(0);
			rewind(stdin);
		}
	} while (flags);
	return i;
}


Stack<Employee>* bt;

void Add() { //добавление
	if (bt != nullptr) {
		//cout << "enter: \n";
		Employee tmp = Employee();
		cin >> tmp;
		bt->push(tmp);
	}
	else {
		std::cout << "\nstack created\n";
	}
}
void Clear() {// очистка
	delete bt;
}

/*
 case 4:
	 cout << "sort stack\n";

	 stackEmp->sortStack();
	 break;
 case 5:
	 cout << "sort stack\n";
	 stackEmp->sortStackB();
	 break;
*/

int main()
{
	setlocale(LC_ALL, "Russian");
	int c = 0;
	FileIO file = FileIO();

	bt = file.readFileToTree("stack.txt");
	int ch = 0;
	do {
		cout << "1 - push \n2 - pop \n3 - search \n4 - sort inserts ascending \n5 - sort descending inserts \n6 - print \n7 - exit and save \n";
		cout << "Enter choice: ";
		ch = ent_int(std::cin, 1, 7);
		int e;	
		switch (ch) {
		case 1:
			cout << "enter elem\n";
			Add();
			break;
		case 2:
			bt->pop();
			cout << "del elem\n";
			/*if (b == NULL) {
				  cout << "not del elem\n";
			  }
			  else {
				  cout << "del elem\n";
			  }*/
			break;
		case 3:
			cout << "enter search elem\n";
			cin >> e;
			bt->search(e);
			break;
		case 4:
			cout << "sort stack\n";

			bt->sortStack();
			break;
		case 5:
			cout << "sort stack\n";
			bt->sortStackB();
			break;
		case 6:
			bt->printStack();
			break;
		case 7:
			file.writeTreeToFile((*bt), "stack.txt");
			break;
		}
	} while (ch != 7);
	/*do {
		c = 0;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Команды: \n";
		cout << "1: Dobavi: \n";
		cout << "2: Vivod: \n";
		cout << "3: New three:  \n";
		cout << "4: Sortirovat: \n";
		cout << "5: Clear. \n";
		cout << "6: Exit. \n";
		cin >> c;
		if (c == 1) { Add(); }
		else if (c == 2) { if (bt != nullptr)bt->printStack(); }
		else if (c == 3) {
			std::cout << "The first item on the stack" << std::endl;
			Employee emp = Employee();
			cin >> emp;
			bt = new Stack<Employee>(emp);
		}
		/*else if (c == 4) { 
			int minAge = 0, maxAge = 0;
			if (bt != nullptr) {
				do {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please, input minimal age boundary: ";
					cin >> minAge;
				} while (minAge <= 0 || minAge >= 100);

				cout << endl;

				do {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please, input maximal age boundary: ";
					cin >> maxAge;
				} while (maxAge <= minAge || maxAge >= 100);

				cout << endl;
				bt->sort(minAge, maxAge);
			}
		}
		else if (c == 4)
		{
			cout << "sort stack\n";
			bt->sortStack();
		}
		else if (c == 5) { Clear(); }
		else if (c == 6) {
			file.writeTreeToFile((*bt), "tree.txt");
			break;
		}
		else {
			continue;
		}
	} while (true);*/
	return 1;
}
