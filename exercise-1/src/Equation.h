#ifndef EQUATION_H
#define EQUATION_H

#include "Repository.h"

class Equation {
	private:
		Repository& repository;
		double distance;
		
		double F, r, r2, a, v2;

		const double constant_gravity = 6.674e-11;
		const double astronomic_unity = 1.496e11;	

	public:
		Equation(Repository& repo): repository(repo) {}
		double objDistance();	
		double gravityForce(double distance);
		double accelerateCalc();
		double accelerateGravity();
		double orbitalcalc();
};


#endif
