//
// Created by kenwi on 11.12.18.
//

#ifndef MASS_SIMULATOR_SIMULATOR_H
#define MASS_SIMULATOR_SIMULATOR_H

#include "Setup.h"

#include "xtensor/xtensor.hpp"

class Simulator
{
	Setup model;
	int time_steps;

	xt::xtensor<float, 3> position;
	xt::xtensor<float, 3> velocity;
	xt::xtensor<float, 1> mass;

public:
	Simulator(Setup &model, int time_steps)
		: model(model)
		, time_steps(time_steps)
	{

	}

	void update_velocities(xt::xtensor<float, 3> &velocity,
		const xt::xtensor<float, 3> &position,
		const xt::xtensor<float, 1> &mass,
		float G,
		float epsilon);

	void run_nbody();

	int find_existing();
};

#endif //MASS_SIMULATOR_SIMULATOR_H
