#pragma once
#include <string>

using namespace std;

class Room {
public:
	string name;
	int area;
	bool privateSpace;
	Room* next;
};
istream& operator >> (istream& in, Room*& r) {
	cout << "Enter name of the room: ";
	string s;
	cin.ignore();
	getline(in, s);
	r->name = s;
	cout << "Enter area in sq ft: ";
	getline(in, s);
	r->area = stoi(s);
	cout << "Is this a private space? (1 for yes, 0 for no) ";
	getline(in, s);
	r->privateSpace = stoi(s);
	return in;
}