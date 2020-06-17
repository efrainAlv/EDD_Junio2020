#pragma once


#include <iostream>

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <boost/lexical_cast.hpp>		  // cast uuid object to string
 

class Assets
{
private:
	std::string name;
	std::string ID;
	std::string description;

public:

	Assets(std::string _name, std::string _description) :name(_name), description(_description) {

		boost::uuids::uuid uuid = boost::uuids::random_generator()();
		this->ID = boost::lexical_cast<std::string>(uuid);

	}


	void setName(std::string _fullName);
	std::string getName();

	void setDescription(std::string _userName);
	std::string getDescription();

	std::string getID();

	void printAAsset();

};

