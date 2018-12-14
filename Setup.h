//
// Created by kenwi on 11.12.18.
//

#ifndef MASS_SIMULATOR_SETUP_H
#define MASS_SIMULATOR_SETUP_H

#include <xtensor/xrandom.hpp>

class Setup
{
	void init_dm_halo();
	void initialize_halo_parameters();
	void initialize_halo_sim();
	void particle_halo_init(float G,
		float num_pos_particles,
		float num_neg_particles,
		float num_tot_paricles,
		float limit,
		float m_pos,
		float m_neg,
		float a_scale,
		float gauss_vel_comp,
		float cube_neg_width);
	
public:
	float G;
	float epsilon;
	float limit;
	float radius;
	int num_pos_particles;
	int num_neg_particles;
	int num_tot_particles;

	float chunks_value;

	float m_pos;
	float m_neg;
	float a_scale;
	float gauss_vel_comp;
	float cube_neg_width;

	Setup()
	{
		init_dm_halo();
	}

	void print_state();
};

#endif //MASS_SIMULATOR_SETUP_H
