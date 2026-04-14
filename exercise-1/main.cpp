#include "Headers.h"


/*
 * @Developed By Jorge Lemos (No AI)
 * */


enum ObjType {
	STAR,
	PLANET
};

struct AstroObject {
	ObjType type;
	double mass;

}

struct Repository {
	std::vector<AstroObject> astro_objects = {};


	void save(ObjType type, double mass);
	void list();
};


void Repository::save(ObjType type, double mass) {
	astro_objects.push_back({ type, mass });
};

void Repository::list(){
	for(const auto& [first, second] : astro_objects) {
		std::cout << first << second << endl;
	}
};

struct UnivGravity {
	// Obs: Here is save star and planet mass value;
	// std::vector<std::pair<ObjType, double>> astro_objects = {};
	double M, m; 

	double distance;
	double F, r, r2, a;

	const double constant_gravity = 6.674e-11; // 6.6743 * 10⁻¹¹ m³ kg⁻¹ s⁻² ;
	const double astronomic_unit = 1.496e11; // 1.496 * 10¹¹(1.496e11) = 1 AU
	
	// UnivGravity(double M, double m, double distance): M(M), m(m), distance(distance) {}

	UnivGravity(double distance);
	double massCalc(ObjType type, double mass);
	double accelCalc();
	double orbitalCalc();

};

/*
 * F = G m₁ m₂
 *       -----
 *         r²
 *
 *(Obs: Star first, planet is second)
 * */
UnivGravity::UnivGravity(double distance): distance(distance) {

	Repository _repository;

	double calc = distance * astronomic_unit;
	r = calc;
	r2 = calc * calc; // Change from pow(calc, 2) for calc² (more precision);
	
	

	F = const_gravity * (astro_objects[0].mass * astro_objects[1].mass) / r2;

	// Removed for get performance from other form
	// F = ((const_gravity * pow(10.0, -11.0))) * ((astros_save.at(0) * astros_save.at(1))) / r; 

	//F = constant_gravity * (astro_objects.at(0) * astro_objects.at(1)) / r;
};

/*
 * a = F
 *    ---
 *     m
 * */
double UnivGravity::accelCalc() {
	a = F / astro_objects[1].mass;

	return a;
}

/*
 * v =  sqrt  GM
 *           ----
 *            r
 *
 * */
double UnivGravity::orbitalCalc() {

	// Can't, root from only constant_gravity and astro_objectts[0] without r;
	// double v = sqrt(constant_gravity * astro_objects[0].mass) / r;
	
	// Correct form
	double v = sqrt((constant_gravity * astro_objects[0].mass) / r); //sqrt(const_gravity * (astros_save.at(0), astros_save.at(1)) / r);
	

	return 0.0;
};



// MassCalc(0.447, ObjType::PLANET) # 0.447UA, PLANET | STAR;
std::optional<double> UnivGravity::massCalc(ObjType type, double mass) {

	Repository _repository;

	const double star_mass_base = 1.989e30; // Changed from (1.9 * pow(10.0, 30.0) to 1.989e30;
	const double planet_mass_base = 5.97e24; // Changed from (1.9 * pow(5.97, 24.0) to 5.97e24;
	
	// double obj_calc = 0.0;

	if(type == ObjType::STAR) {
		this->M = mass * star_mass_base;

		// obj_calc = (obj_astro_unit * star_mass_base);
		repository.save(ObjType::STAR, this->M);

		return this->M;

	} else if (type == ObjType::PLANET) {
		this->m = mass * planet_mass_base;
		// obj_calc = (obj_astro_unit * planet_mass_base);
		
		repository.save(ObjType::PLANET, this->m);

		return this->m;

	}

	return std::nullopt;
};


int main() {

	UnivGravity eq;

	// Setup with [0] = STAR and [1] = PLANET
	
	double star = 0.419;
	double planet = 5.18;

	eq.massCalc(ObjType::STAR, star);
	eq.massCalc(ObjType::PLANET, planet);
	

	return 0;
}
