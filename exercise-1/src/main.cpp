#include "Equation.h"
#include "Headers.h"
#include "CalcMass.h"
#include "Repository.h"

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
