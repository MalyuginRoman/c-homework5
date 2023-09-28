#pragma once

#include <iostream>
#include <vector>
#include "primitive.h"

class Document{

public:
	Document(std::string name_) : name(name_){};
	Document(const Document& d): name(d.sendName()){}
	~Document() {}

    void addPrimitive (primitive * somePrimitive) {
		std::cout << "add :" << somePrimitive->sendName() << std::endl;
		primitives.push_back(somePrimitive);
	};

	void deletePrimitive () {
		if(!primitives.empty()){
			std::cout << "Delete last primitive" << std::endl;
			primitives.pop_back();
		}
	};

	std::string sendName() const{
		return this->name;
	}

private:
	std::vector<primitive * > primitives;
	std::string name;
};
