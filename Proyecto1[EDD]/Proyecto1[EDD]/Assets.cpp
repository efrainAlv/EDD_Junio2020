#include "Assets.h"

void Assets::setName(std::string name) {
	this->name = name;
}
std::string Assets::getName() {
	return this->name;
}


void Assets::setDescription(std::string description) {
	this->description = description;
}
std::string Assets::getDescription() {
	return this->description;
}


std::string Assets::getID() {
	return this->ID;
}

void Assets::printAAsset() {

	std::cout << "ID: " << this->ID << " " << getName() << " " << getDescription();

}