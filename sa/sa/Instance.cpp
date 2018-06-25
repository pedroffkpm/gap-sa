//
//  Instance.cpp
//  sa
//
//  Created by Pedro Kampmann on 25/06/18.
//  Copyright © 2018 Pedro Kampmann. All rights reserved.
//

#include "Instance.hpp"

Instance::Instance( unsigned agents, unsigned tasks, std::vector<unsigned> cost, std::vector<unsigned> requestedResources, std::vector<unsigned> availableResources):
            agents(agents),
            tasks(tasks),
            cost(cost),
            requestedResources(requestedResources),
            availableResources(availableResources)
            {}

unsigned Instance::getAgents() {
    return this->agents;
}

unsigned Instance::getTasks() {
    return this->tasks;
}

std::vector<unsigned> Instance::getCosts() {
    return this->cost;
}

std::vector<unsigned> Instance::getReqRes() {
    return this->requestedResources;
}

std::vector<unsigned> Instance::getAvRes() {
    return this->availableResources;
}
