//
// Created by kenwi on 11.12.18.
//

#include "Simulator.h"
#include <string>
#include <iostream>
#include <chrono>

void Simulator::run_nbody()
{
	std::cout << "Searching for existing dataset..." << std::endl;
	int index = find_existing();
	std::cout << "Index of last dataset: " << index << std::endl;

	time_steps -= index;
	std::cout << "About to perform calculation on " << time_steps << " time steps..." << std::endl;
	auto begin = std::chrono::high_resolution_clock::now();

	std::cout << "Beginning N-body simulation..." << std::endl;
	while (time_steps > 0)
	{
		begin = std::chrono::high_resolution_clock::now();
		update_velocities(position, velocity, mass, model.G, model.epsilon);

		const auto end = std::chrono::high_resolution_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << "Iteration " << index << " completed in " << duration << " ns..." << std::endl;

		index++;
		time_steps--;
	}
}

int Simulator::find_existing()
{
	return 1;
}

void Simulator::update_velocities(xt::xtensor<float, 3> &velocity,
	const xt::xtensor<float, 3> &position,
	const xt::xtensor<float, 1> &mass,
	float G,
	float epsilon)
{

}

/*void Simulator::load_as_dask_array(xt::xtensor<float, 3> &position,
								   xt::xtensor<float, 3> &velocity,
								   const int index,
								   const float chunks_value)
{
	std::string position_file("./DATA/position" + std::to_string(index) + ".hdf5");
	std::string velocity_file("./DATA/velocity" + std::to_string(index) + ".hdf5");
	std::string mass_file("./DATA/mass" + std::to_string(index) + ".hdf5");

	HighFive::File position_data(position_file, HighFive::File::ReadOnly);
	HighFive::File velocity_data(velocity_file, HighFive::File::ReadOnly);
	HighFive::File mass_data(mass_file, HighFive::File::ReadOnly);
}*/


