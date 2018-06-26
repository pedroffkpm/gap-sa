//
//  Solution.hpp
//  sa
//
//  Created by Pedro Kampmann on 26/06/18.
//  Copyright © 2018 Pedro Kampmann. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <iostream>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Instance.hpp"

#endif /* Solution_hpp */

class Solution {
    
    std::vector<unsigned> tasks; //vector of size |tasks|, in which will be represented the agents assigned to each task
    std::vector<unsigned> costs; //vector of size |tasks|*|agents|, represents costs
    
public:
    //create feasible initial solution
    Solution(Instance instance);
    
    //create new Solution from neighbour
    Solution(Instance instance, Solution solution);
    
    bool isFeasible(Instance instance);
    
    int getMinIndex(std::vector<unsigned> &vector);
    
    std::vector<unsigned> getTasks();
    std::vector<unsigned> getCosts();
    
    int getTotalCost();
    double calculateUnfitness(Instance instance);
    
};
