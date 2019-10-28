#include <iostream>
#include "FloorPlan.h"
#include <string>
#include <iostream>

using namespace std;

int getInt() {
	cout << "What action would you like to perform?" << endl;
	cout << "1: Add a room\n2: Delete a room\n3: Print current diagram\n4: Output Design Information\n0: Exit program\n";
	int input;
	bool valid;
	do {
		cin >> input;
		valid = input >= 0 && input <= 4;
		if (!valid) {
			cout << "Invalid input: " << input << endl;
		}
	} while (!valid);
	return input;
}
void addRoom(FloorPlan& fp) {
	Room* r = new Room();
	cin >> r;
	if (!fp.addRoom(r)) {
		cout << "Not Enough space to add room" << endl;
	}
}

void deleteRoom(FloorPlan& fp) {
	string name;
	cout << "Enter name of room to be deleted: ";
	cin.ignore();
	getline(cin, name);
	if (fp.deleteRoom(name)) {
		cout << name << " was deleted." << endl;
	}
	else {
		cout << name << " could not be found." << endl;
	}
}

int main() {
	int totalArea;
	cout << "Enter total square footage for the property: ";
	cin >> totalArea;
	FloorPlan fp(totalArea);
	int input;
	do {
		input = getInt();
		switch (input) {
		case 1:
			addRoom(fp);
			break;
		case 2:
			deleteRoom(fp);
			break;
		case 3:
			fp.printDiagram(cout);
			break;
		case 4:
			fp.printDesignInfo(cout);
			break;
		}
	} while (input != 0);
	return 0;
}