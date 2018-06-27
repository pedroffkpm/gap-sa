//
//  Instance.hpp
//  sa
//
//  Created by Pedro Kampmann on 25/06/18.
//  Copyright © 2018 Pedro Kampmann. All rights reserved.
//

#ifndef Instance_hpp
#define Instance_hpp
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#endif /* Instance_hpp */

class Instance {
  
    //number of agents
    unsigned numberOfAgents;
    //number of tasks
    unsigned numberOfTasks;
    
    //costs matrix as 1d vector, to be manually indexed
    std::vector<unsigned> costs;
    
    //task resources matrix as 1d vector, to be manually indexed
    std::vector<unsigned> taskResource;
    
    //resource limit of each agent
    std::vector<unsigned> agentLimit;
    
public:
    Instance( unsigned agents, unsigned tasks, std::vector<unsigned> cost, std::vector<unsigned> taskResource, std::vector<unsigned> agentLimit );
    unsigned getNumberOfAgents();
    unsigned getNumberOfTasks();
    std::vector<unsigned> getCosts();
    std::vector<unsigned> getTaskResource();
    std::vector<unsigned> getAgentLimit();
    
};
