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

    std::string line;
    std::ifstream instanceFile(instancePath);

    /* parse number of agents */
    std::getline(instanceFile, line);
    std::cout << line << "\n";
    std::istringstream ss(line);
    ss >> numberOfAgents;
    std::cout << "numberofagents" << numberOfAgents << "\n";
    
    /* available resources of each agent */
    std::vector<unsigned> agentLimit(numberOfAgents);

    /* number of tasks */
    unsigned numberOfTasks;
    
    /* parse number of tasks */
    std::getline(instanceFile, line);
    std::istringstream ss2(line);
    ss2 >> numberOfTasks;
    std::cout << numberOfTasks << "\n";
    
    /*resources matrix as 1d vector, to be manually indexed */
    std::vector<unsigned> taskResources(numberOfTasks);
    
    /*costs matrix as 1d vector, to be manually indexed */
    std::vector<unsigned> cost(numberOfAgents*numberOfTasks);
    
    
    
    /*parse costs*/
    unsigned aux;
    std::cout << "\nkrl1\n";
    
    for (int i = 0; i < numberOfTasks*numberOfAgents; i++) {
        std::cout << "\nkrl2\n";
        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> aux;
        
        std::cout << "aux =";
        std::cout << aux << "\n";

        cost[i] = aux;
    }
    /*parse required resources*/
     for (int i = 0; i < numberOfTasks*numberOfAgents; i++) {

        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> aux;

        taskResources[i] = aux;
    }
    /* parse available resources per agent*/
   for (int i = 0; i < numberOfAgents; i++) {

        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> aux;

        agentLimit[i] = aux;
    }

    return Instance(numberOfAgents, numberOfTasks, cost, taskResources, agentLimit);
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
    
    //instance file + seed + alpha + acceptanceProbability + numberOfIterations
    
    
    unsigned seed;
    ss.str(argv[2]);
    ss >> seed;
    std::cout << seed << "\n";
    ss.clear();
    std::srand(seed);
    
    double alpha;
    ss.str(argv[3]);
    ss >> alpha;
    std::cout << alpha << "\n";
    ss.clear();
    
    double acceptanceProb;
    ss.str(argv[4]);
    ss >> acceptanceProb;
    std::cout << acceptanceProb << "\n";
    ss.clear();

    unsigned steps;
    ss.str(argv[5]);
    ss >> steps;
    ss.clear();
    
    Instance instance = parseInstance(instancePath);
    
    auto initialTime = std::chrono::system_clock::now();
    
    Solution solution = simulatedAnnealing(instance, alpha, acceptanceProb, steps);
    
    auto endTime = std::chrono::system_clock::now();
    
    auto time = endTime - initialTime;
    auto seconds = std::chrono::duration_cast<std::chrono::duration<double>>(time);
    
    std::cout << seconds.count() << ", ";
    
        return 0;
}
