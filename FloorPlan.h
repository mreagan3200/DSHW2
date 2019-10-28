#pragma once
#include "Room.h"
#include <iostream>

using namespace std;
/*
Floorplan class that contains information about the square footage and room information (Linked List).
Functionality includes adding rooms, and deleting rooms.
*/
class FloorPlan {
private:
	int totalArea;
	int currentArea = 0;
	Room* head = nullptr;
public:
	FloorPlan(int area = 0) {
		this->totalArea = area;
	}
	~FloorPlan() {
		deleteRooms(head);
	}
	//adds room to the list
	//returns true if added, returns false if cannot be added
	//if room cannot be added, deletes the pointer
	bool addRoom(Room* r) {
		if (r->area + currentArea > totalArea) {
			delete r;
			return false;
		}
		else {
			if (head == nullptr) {
				head = r;
			}
			else {
				Room* temp = head;
				while (temp->next != nullptr) {
					temp = temp->next;
				}
				temp->next = r;
			}
			currentArea += r->area;
			return true;
		}
	}
	//delete all rooms in list beginning at start
	void deleteRooms(Room* start) {
		if (start != nullptr) {
			Room* next = start->next;
			delete start;
			deleteRooms(next);
		}
	}

	//delete a room based off of the name
	//return true if the room was deleted, false otherwise.
	bool deleteRoom(string name) {
		if (head == nullptr)
			return false;
		Room* temp = head;
		if (head->name == name) {
			head = head->next;
			delete temp;
			return true;
		}
		else {
			while (temp->next != nullptr) {
				if (temp->next->name == name) {
					Room* r = temp->next->next;
					delete temp->next;
					temp->next = r;
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
	}
	//prints out design information
	void printDesignInfo(ostream& stream) {
		int publicarea = 0, privatearea = 0;
		Room* temp = head;
		while (temp != nullptr) {
			if (temp->privateSpace) {
				privatearea += temp->area;
			}
			else publicarea += temp->area;
			temp = temp->next;
		}
		stream << "Property Area: " << totalArea << "sq ft" << endl;
		stream << "Public Area:   " << publicarea << "sq ft" << endl;
		stream << "Private Area:  " << privatearea << "sq ft" << endl;
	}

	//print out a representation of the list
	void printDiagram(ostream& stream) {
		Room* temp = head;
		while (temp != nullptr) {
			stream << temp->name << ": Area = " << temp->area << " sq ft, ";
			if (temp->privateSpace)
				stream << "private";
			else stream << "public";
			temp = temp->next;
			stream << endl;
		}
	}
};