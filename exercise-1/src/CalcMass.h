#ifndef CALCMASS_H
#define CALCMASS_H

#include "Equation.h"
#include "Repository.h"

enum ObjType {
	STAR,
	PLANET
};


inline std::optional<double> MassCalc(std::string obj_name, double objMass, ObjType type, Repository& repository, Position pos) {

	constexpr double star_base_mass = 1.989e30;
	constexpr double planet_base_mass = 5.97e24;

	double M, m;

	if(type == ObjType::STAR) {
		M = objMass * star_base_mass;
	
		repository.save(
			obj_name,
			ObjType::STAR, 
			M, 
			pos.objPosition(pos.x, pos.y, pos.z)
		);

		return M;
	
	} else if(type == ObjType::PLANET) {
		m = objMass * planet_base_mass;

		repository.save(
			ObjType::PLANET, 
			m,
			pos.objPosition(pos.x, pos.y, pos.z)
		);
		
		return m;
	}

	return std::nullopt; 
};

#endif
