#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void add(vector<string>&);
void view(vector<string>&);
void update(vector<string>&);
void search(vector<string>&);
void sort(vector<string>&);
void save(vector<string>&);
void load(vector<string>&);
void del(vector<string>&);


void add(vector<string>& list)
{
	string item;
	cout << "Enter item to add: ";
	cin >> item;
	list.push_back(item);
}

void view(vector<string>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << i + 1 << ". " << list[i] << endl;
	}
}

void update(vector<string>& list)
{
	int index;
	string item;
	cout << "Enter index to update: ";
	cin >> index;
	cout << "Enter new item: ";
	cin >> item;
	list[index - 1] = item;
}

void search(vector<string>& list)
{
	string item;
	cout << "Enter item to search: ";
	cin >> item;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == item)
		{
			cout << "Item found at index " << i + 1 << endl;
			return;
		}
	}
	cout << "Item not found" << endl;
}

void sort(vector<string>& list)
{
	sort(list.begin(), list.end());
}

void save(vector<string>& list)
{
	ofstream file;
	file.open("todo.txt");
	for (int i = 0; i < list.size(); i++)
	{
		file << list[i] << endl;
	}
	file.close();
}

void load(vector<string>& list)
{
	ifstream file;
	string item;
	file.open("todo.txt");
	while (getline(file, item))
	{
		list.push_back(item);
	}
	file.close();
}

void del(vector<string>& list)
{
	int index;
	cout << "Enter index to delete: ";
	cin >> index;
	list.erase(list.begin() + index - 1);
}

int main()
{
	vector<string> list;
	load(list);
	while (true)
	{
		int choice;
		cout << "1. Add" << endl;
		cout << "2. View" << endl;
		cout << "3. Update" << endl;
		cout << "4. Search" << endl;
		cout << "5. Sort" << endl;
		cout << "6. Save" << endl;
		cout << "7. Load" << endl;
		cout << "8. Delete" << endl;
		cout << "9. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			add(list);
			break;
		case 2:
			view(list);
			break;
		case 3:
			update(list);
			break;
		case 4:
			search(list);
			break;
		case 5:
			sort(list);
			break;
		case 6:
			save(list);
			break;
		case 7:
			load(list);
			break;
		case 8:
			del(list);
			break;
		case 9:
			return 0;
		default:
			cout << "Invalid choice" << endl;
		}
	}
}