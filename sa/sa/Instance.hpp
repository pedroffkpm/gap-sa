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
    unsigned numberOfAgents;
    //number of tasks
    unsigned numberOfTasks;
    
    //costs matrix as 1d vector, to be manually indexed
    std::vector<unsigned> costs;
    
    //resources matrix as 1d vector, to be manually indexed
    std::vector<unsigned> requestedResources;
    
    //available resources of each agent
    std::vector<unsigned> availableResources;
    
public:
    Instance( unsigned agents, unsigned tasks, std::vector<unsigned> cost, std::vector<unsigned> requestedResource, std::vector<unsigned> availableResource );
    unsigned getNumberOfAgents();
    unsigned getNumberOfTasks();
    std::vector<unsigned> getCosts();
    std::vector<unsigned> getReqRes();
    std::vector<unsigned> getAvRes();
    
};
