//
//  main.cpp
//  sa
//
//  Created by Pedro Kampmann on 25/06/18.
//  Copyright © 2018 Pedro Kampmann. All rights reserved.
//
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//#include "solution.h"
#include "instance.hpp"

Instance parseInstance(std::string instancePath) {
    /* number of agents */
    unsigned agents;

    /* number of tasks */
    unsigned tasks;

    unsigned tasks_size = agents * tasks;

    /*costs matrix as 1d vector, to be manually indexed */
    std::vector<unsigned> cost;

    /*resources matrix as 1d vector, to be manually indexed */
    std::vector<unsigned> requestedResources;

    /* available resources of each agent */
    std::vector<unsigned> availableResources;


    std::string line;
    std::ifstream instanceFile(instancePath);

    /* parse number of agents */
    std::getline(instanceFile, line);
    std::istringstream ss(line);
    ss >> agents;

    /* parse number of tasks */
    std::getline(instanceFile, line);
    std::istringstream iss(line);
    ss >> tasks;

    /*parse costs*/
    for (int i = 0; i < tasks_size; i++) {
        unsigned aux;

        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> aux;

        cost[i] = aux;
    }
    /*parse required resources*/
     for (int i = 0; i < tasks_size; i++) {
        unsigned aux;

        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> aux;

        requestedResources[i] = aux;
    }
    /* parse available resources per agent*/
   for (int i = 0; i < agents; i++) {
        unsigned aux1;

        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> aux;

        availableResources[i] = aux;
    }

    return Instance(agents, tasks, cost, requestedResource, availableResource );
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    /* instance file path */
    const std::string instancePath(argv[1]);

    Instance instance = parseInstance(instancePath);
    return 0;
}
