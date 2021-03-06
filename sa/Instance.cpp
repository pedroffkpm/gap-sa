//
//  Instance.cpp
//  sa
//
//  Created by Pedro Kampmann on 25/06/18.
//  Copyright © 2018 Pedro Kampmann. All rights reserved.
//

#include "Instance.hpp"

Instance::Instance(unsigned numberOfAgents,
                   unsigned numberOfTasks,
                   std::vector<unsigned> costs,
                   std::vector<unsigned> taskResource,
                   std::vector<unsigned> agentLimit):
                numberOfAgents(numberOfAgents),
                numberOfTasks(numberOfTasks),
                costs(costs),
                taskResource(taskResource),
                agentLimit(agentLimit) {}

unsigned Instance::getNumberOfAgents() {
    return this->numberOfAgents;
}

unsigned Instance::getNumberOfTasks() {
    return this->numberOfTasks;
}

std::vector<unsigned> Instance::getCosts() {
    return this->costs;
}

std::vector<unsigned> Instance::getTaskResource() {
    return this->taskResource;
}

std::vector<unsigned> Instance::getAgentLimit() {
    return this->agentLimit;
}
