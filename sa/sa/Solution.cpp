//
//  Solution.cpp
//  sa
//
//  Created by Pedro Kampmann on 26/06/18.
//  Copyright © 2018 Pedro Kampmann. All rights reserved.
//

#include "Solution.hpp"

Solution::Solution(Instance instance)
: tasks(instance.getNumberOfTasks()),
  limits(instance.getAvRes())
{
    
    unsigned numberOfTasks = instance.getNumberOfTasks();
    unsigned numberOfAgents = instance.getNumberOfAgents();
    
    //generate feasible initial solution
    //feasible solution is attribute task to the agent with minimal resource consumption
    //and it being less than his resource limit
    
    std::vector<unsigned> resources = instance.getReqRes();
    std::vector<unsigned> aux(numberOfAgents);
    int minIndex;
    
    do {
        this->tasks.resize(this->tasks.size(), -1); //tasks sao iniciadas com o valor UNFEASIBLE de -1
        
        for(unsigned i = 0; i < numberOfTasks; i++) {
            for(unsigned j = 0; j < numberOfAgents; j++) {
                aux[j] = resources[(numberOfTasks * j) + i]; //seleciona "coluna" da tarefa i
            }
            std::cout << &aux;
            minIndex = getMinIndex(aux); //indice do agente que tem o menor recurso
            std::cout << minIndex;
            
            //verifica se ele passa do limite; se passa o minIndex tem que ser outro que n passe
            
            for(unsigned i = 0; i < numberOfAgents; i++) {
                if(this->limits[minIndex] >= aux[minIndex]) { //se o limite é ok
                    this->limits[minIndex] -= aux[minIndex];
                    this->tasks[i] = minIndex; //esse agente vira o dessa task
                    break;
                }
                else {
                    aux.erase(aux.begin() + minIndex); //tira o elemento min do array
                    minIndex = getMinIndex(aux); //indice do novo valor mínimo
                    continue;
                }
            }
        }
    } while (!isFeasible(instance));
}

bool Solution::isFeasible(Instance instance) {
    
    if (std::find(this->tasks.begin(), this->tasks.end(), -1) != this->tasks.end()) {
        return false;
    }
    
    unsigned aux = 0;
    std::vector<unsigned> resources = instance.getReqRes();
    
    for (unsigned i = 0; i < instance.getNumberOfAgents(); i++) {
        for (unsigned j = 0; j < instance.getNumberOfTasks(); j++) {
            aux += resources[(instance.getNumberOfTasks() * i) + j];
        }
        if (aux > instance.getAvRes()[i]) {
            return false;
        }
    }

    return true;
}

std::vector<unsigned> Solution::getTasks() {
    return this->tasks;
}

std::vector<unsigned> Solution::getLimits() {
    return this->limits;
}

int Solution::getMinIndex(std::vector<unsigned> &vector) { //retorna o indice do menor valor de um vetor
    
    std::vector<unsigned>::iterator minIterator = std::min_element(vector.begin(), vector.end());
    
    return std::distance(vector.begin(), minIterator);
}

