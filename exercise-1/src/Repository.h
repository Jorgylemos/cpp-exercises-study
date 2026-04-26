#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "CalcMass.h"
#include <stdexcept>

struct Position {
	
	float x, y, z;
	
	void objPosition(float x, float y, float z) {
		this-> x = x;
		this-> y = y;
		this-> z = z;
	}
	
};

struct AstroObject {
	std::string obj_name;
	ObjType type;
	double mass;
	Position pos;
};

class Repository {

	private:
		std::vector<AstroObject> astro_objects = {};

	public:
		void save(std::string obj_name, ObjType type, double mass, Position pos);

		const AstroObject& getObject(int index);
		
		AstroObject& getObjPos(float x, float y, float z) const;
		
		size_t size() const;
};

void Repository::save(std::string obj_name, ObjType type, double mass, Position pos) {
	this->astro_objects.push_back({ obj_name, type, mass, pos });
};


const AstroObject& Repository::getObject(int index) {
	return astro_objects[index];
};

AstroObject& Repository::getObjPos(float x, float y, float z) const {
	for(const auto& obj : astro_objects) {

		if(obj.pos.x == x && obj.pos.y == y && obj.pos.z == z) {
			return obj;
		}
	}

	throw std::runtime_error("Object not found");
}

size_t Repository::size() const {
	return astro_objects.size();
}

#endif
