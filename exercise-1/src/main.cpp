#include "Equation.h"
#include "Headers.h"
#include "CalcMass.h"
#include "Repository.h"

/*
 * r = sqrt (x2 - x1)² + (y2 - y1)² + (z2 - z1)²
 *
 * */

double Equation::objDistance() {
 	auto& obj1 = repository.getObject(0).pos;
	auto& obj2 = repository.getObject(1).pos;

	double calc = pow((obj2.x - obj1.x), 2) + pow((obj2.y - obj1.y), 2) + pow((obj2.z - obj1.z), 2);

	double r = sqrt(calc);

	return r;
}

/*
 * F = G m1 m2
 *      -------
 *        r²
 * */
double Equation::gravityForce(double distance) {

	double calc = distance * this->astronomic_unity;

	this->r = calc;
	this->r2 = calc * calc;

	this->F = this->constant_gravity * (this->repository.getObject(0).mass * this->repository.getObject(1).mass) / this->r2;
	
	return this->F;
};

/*
 * a = F
 *    ---
 *     m
 * */

double Equation::accelerateCalc() {
	this->a = this->F / this->repository.getObject(1).mass;
	
	return this->a;
};

/*
 *  GM
 * ----
 *  r²
 *
 * */
double Equation::accelerateGravity(){
	double pullGravity = (this->constant_gravity * this->repository.getObject(0).mass) / this->r2;

	return pullGravity;
};


/*
 * v = sqrt GM
 *         ----
 *          r
 * */
double Equation::orbitalcalc() {
	double v = sqrt((this->constant_gravity * repository.getObject(0).mass) / this->r);

	return v;
};

int main() {
	
	

	return 0;
}
