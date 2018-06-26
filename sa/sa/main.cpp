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
#include <cmath>
#include "Solution.hpp"

Instance parseInstance(std::string instancePath) {
    /* number of agents */
    unsigned numberOfAgents;

    /* number of tasks */
    unsigned numberOfTasks;

    unsigned tasks_size = numberOfAgents * numberOfTasks;

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
    ss >> numberOfAgents;

    /* parse number of tasks */
    std::getline(instanceFile, line);
    std::istringstream iss(line);
    ss >> numberOfTasks;

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
   for (int i = 0; i < numberOfAgents; i++) {
        unsigned aux;

        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> aux;

        availableResources[i] = aux;
    }

    return Instance(numberOfAgents, numberOfTasks, cost, requestedResources, availableResources );
}

double setInitialTemp(Solution solution, Instance instance, double acceptanceProb) {
    int deltaSum = 0;
    
    for (unsigned i = 0; i < 1000; i++) {
        Solution newSolution(instance, solution);
        deltaSum += std::abs(newSolution.getTotalCost() - solution.getTotalCost());
    }
    return (deltaSum/1000) / std::log(1/acceptanceProb);
}

Solution simulatedAnnealing(Instance instance, double alpha, double acceptanceProb, unsigned steps) {
    Solution current(instance);
    std::cout << current.getTotalCost() << ", ";
    Solution best = current;
    
    double temperature = setInitialTemp(current, instance, acceptanceProb);
    
    for (int k =0; k < steps; k++) {
        
        Solution newSolution(instance, current);
        double u = std::rand() / RAND_MAX; //random between 0 and 1
        int deltaCost = newSolution.getTotalCost() - current.getTotalCost() + newSolution.calculateUnfitness(instance);
        
        if (deltaCost < 0 || u < std::exp(-deltaCost/temperature)) {
            current = newSolution;
        }
        
        if (current.isFeasible(instance) && current.getTotalCost() < best.getTotalCost()) {
            best = current;
        }
        
        temperature *= alpha;
    }
    
    return best;
}


int main(int argc, const char * argv[]) {
    
    std::istringstream ss;

    /* instance file path */
    const std::string instancePath(argv[1]);
    
    Instance instance = parseInstance(instancePath);

    //instance file + seed + alpha + acceptanceProbability + numberOfIterations
    
    unsigned seed;
    ss.str(argv[2]);
    ss >> seed;
    ss.clear();
    std::srand(seed);
    
    double alpha;
    ss.str(argv[3]);
    ss >> alpha;
    ss.clear();
    
    double acceptanceProb;
    ss.str(argv[4]);
    ss >> acceptanceProb;
    ss.clear();

    unsigned steps;
    ss.str(argv[5]);
    ss >> steps;
    ss.clear();
    
    auto initialTime = std::chrono::system_clock::now();
    
    Solution solution = simulatedAnnealing(instance, alpha, acceptanceProb, steps);
    
    auto endTime = std::chrono::system_clock::now();
    
    auto time = endTime - initialTime;
    auto seconds = std::chrono::duration_cast<std::chrono::duration<double>>(time);
    
    std::cout << seconds.count() << ", ";
    
        return 0;
}
