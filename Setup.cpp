//
// Created by kenwi on 11.12.18.
//

#include <random>
#include <iostream>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xarray.hpp>

#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

#include "Setup.h"

void Setup::initialize_halo_parameters()
{
    std::cout << "Initializing halo parameters..." << std::endl;
    G = 1.0f;
    epsilon = 0.07f;
    limit = 80000;
    radius = 4;
    num_pos_particles = 5000;
    num_pos_particles = 45000;
    chunks_value = (num_pos_particles + num_neg_particles) / 5.0f;
    time_steps = 1000;
}

void Setup::init_dm_halo()
{
    std::cout << "Initializing Dark matter halo formation simulation..." << std::endl;
   
    if(!fs::exists("DATA"))
    {
        std::cout << "Data directory not detected!" << std::endl;
        
        if(fs::create_directory("DATA"))
        {
            std::cout << "Directory created..." << std::endl;
        }
    }
    
    print_state();
    initialize_halo_parameters();
    num_tot_particles = num_pos_particles + num_neg_particles;
    initialize_halo_sim();
    print_state();
}

void Setup::print_state()
{
    std::cout << std::endl
              << "Simulation state:" << std::endl
              << "float \tG:" << G << std::endl
              << "float \tepsilon: " << epsilon << std::endl
              << "float \tlimit: " << limit << std::endl
              << "float \tradius: " << radius << std::endl
              << "int \tnum_pos_particles: " << num_pos_particles << std::endl
              << "int \tnum_neg_particles: " << num_neg_particles << std::endl
              << "int \tnum_tot_particles: " << num_tot_particles << std::endl
              << "float \tchunks_value: " << chunks_value << std::endl
              << "int \ttime_steps: " << time_steps << std::endl
              << "float \tm_pos: " << m_neg << std::endl
              << "float \tm_neg: " << m_pos << std::endl
              << "float \ta_scale: " << a_scale << std::endl
              << "float \tgauss_vel_comp: " << gauss_vel_comp << std::endl
              << "float \tcube_neg_width: " << cube_neg_width << std::endl
              << std::endl;
}


void Setup::initialize_halo_sim()
{
    std::cout << "Initializing halo simulation..." << std::endl;
    m_pos = 1.0f;
    m_neg = -3.0f;
    a_scale = 1.0f;
    gauss_vel_comp = 0.3f;
    cube_neg_width = 200;
}

void Setup::particle_halo_init(float G, float num_pos_particles, float num_neg_particles, float num_tot_particles,
                               float limit, float m_pos, float m_neg, float a_scale, float gauss_vel_comp,
                               float cube_neg_width)
{
    /*xt::xarray<float> mass_pos;
    if(num_pos_particles > 0)
        mass_pos= xt::random::rand<float>(m_pos/num_pos_particles, m_pos/num_neg_particles, num_tot_particles);
    else
        mass_pos = xt::random::rand<float>(0, 0, 0);
*/
    /*xt::xarray<float> mass_neg;
    if(num_neg_particles > 0)
        mass_neg = xt::random::rand<float>(m_neg/num_neg_particles, m_neg/num_pos_particles, num_tot_particles);
    else
        mass_neg = xt::random::rand<float>(0, 0, 0);

    auto mass = xt::concatenate(xtuple(mass_pos, mass_neg), 0);*/
}
