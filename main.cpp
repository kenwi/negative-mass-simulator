#include <iostream>

#include "Simulator.h"
#include "Setup.h"
#include "Export.h"

int main()
{
    Setup darkMatterHalo;
    
	Simulator simulator(darkMatterHalo, 10);
    simulator.run_nbody();

//    Export exporter;

    return 0;
}