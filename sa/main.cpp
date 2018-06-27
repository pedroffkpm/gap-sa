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
    
    std::istringstream ss(line);
    ss >> numberOfAgents;

   
    
    /* available resources of each agent */
    std::vector<unsigned> agentLimit(numberOfAgents);

    /* number of tasks */
    unsigned numberOfTasks;
    
    /* parse number of tasks */
    std::getline(instanceFile, line);
    std::istringstream ss2(line);
    ss2 >> numberOfTasks;
    

    unsigned size = numberOfTasks*numberOfAgents;    

    /*resources matrix as 1d vector, to be manually indexed */
    std::vector<unsigned> taskResources(size);
    
    /*costs matrix as 1d vector, to be manually indexed */
    std::vector<unsigned> cost(size);
    
    
    
    /*parse costs*/
    unsigned aux;
   
    unsigned i = 0;
    for (i = 0; i < size; i++) {
     //   std::cout << "\nkrl2\n";
        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> aux;
        cost[i] = aux;
		
    }
	
    /*parse required resources*/
     for (i = 0; i < size; i++) {

        std::getline(instanceFile, line);
        std::istringstream ss1(line);
        ss1 >> aux;

        taskResources[i] = aux;
    }
	
    /* parse available resources per agent*/
   for (i = 0; i < numberOfAgents; i++) {

        std::getline(instanceFile, line);
        std::istringstream ss2(line);
        ss2 >> aux;

	

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
    
    double temperature = 70;
    
    for (int k =0; k < steps; k++) {
        Solution newSolution(instance, current);
        double u = double(std::rand()) / double(RAND_MAX); //random between 0 and 1

        double deltaCost = newSolution.getTotalCost() - current.getTotalCost() + newSolution.calculateUnfitness(instance);

        double e = double(-deltaCost)/double(temperature);
        
        if (deltaCost < 0.0 || u < std::exp(e)) {
            current = newSolution;
        }
        
        if (current.getTotalCost() <= best.getTotalCost()) {
            best = current;
        }
        
        temperature = temperature * alpha;
    }
    
    return best;
}




void logOut(Solution solution) {
    std::cout << solution.getTotalCost() << "\n";
    std::cout << "#Job\t#Agent\n";

    unsigned task = 0;
    for (unsigned agent : solution.getTasks()) {
        std::cout << task << "\t" << agent << "\n";
        task++;
}
}
  


int main(int argc, const char * argv[]) {
    
    std::istringstream ss;

    /* instance file path */
    const std::string instancePath(argv[1]);
    
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
 
    
    Instance instance = parseInstance(instancePath);
	
    std::cout << "first, seconds, best"  << std::endl;
    
    auto initialTime = std::chrono::system_clock::now();

    Solution solution = simulatedAnnealing(instance, alpha, acceptanceProb, steps);

    auto endTime = std::chrono::system_clock::now();
    
    auto time = endTime - initialTime;
    auto seconds = std::chrono::duration_cast<std::chrono::duration<double>>(time);
    
    std::cout << seconds.count() << ", "; 
    logOut(solution);
    
        return 0;
}
