#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "CalcMass.h"
#include <stdexcept>

class Position {
	private:
		float x, y, z;
		float vx, vy, vz;

	public:
		void objPosition(float x, float y, float z) {
			this-> x = x;
			this-> y = y;
			this-> z = z;
		}

		void velocPosition(float vx, float vy, float vz) {
			this-> vx = vx;
			this-> vy = vy;
			this-> vz = vz;
		}
	
};

struct AstroObject {
	ObjType type;
	Position pos;
	double mass;
};

class Repository {

	private:
		std::vector<AstroObject> astro_objects = {};

	public:
		void save(ObjType type, double mass);

		const AstroObject& getObject(int index);
		
		AstroObject& getObjPos(float x, float y, float z) const;
		
		size_t size() const;
};

void Repository::save(ObjType type, double mass) {
	this->astro_objects.push_back({ type, mass });
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
