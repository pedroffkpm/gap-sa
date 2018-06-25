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
#include <vector>

#endif /* Instance_hpp */

class Instance {
  
    //number of agents
    unsigned agents;
    //number of tasks
    unsigned tasks;
    
    //costs matrix as 1d vector, to be manually indexed
    std::vector<unsigned> cost;
    
    //resources matrix as 1d vector, to be manually indexed
    std::vector<unsigned> requestedResources;
    
    //available resources of each agent
    std::vector<unsigned> availableResources;
    
public:
    Instance( unsigned agents, unsigned tasks, std::vector<unsigned> cost, std::vector<unsigned> requestedResource, std::vector<unsigned> availableResource );
    unsigned getAgents();
    unsigned getTasks();
    std::vector<unsigned> getCosts();
    std::vector<unsigned> getReqRes();
    std::vector<unsigned> getAvRes();
    
};
