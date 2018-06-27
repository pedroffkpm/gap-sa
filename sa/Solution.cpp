//
//  Solution.cpp
//  sa
//
//  Created by Pedro Kampmann on 26/06/18.
//  Copyright © 2018 Pedro Kampmann. All rights reserved.
//

#include "Solution.hpp"

Solution::Solution(Instance instance)
: tasks(instance.getNumberOfTasks()), //array of size |tasks|
  costs(instance.getCosts())
{
    
    unsigned numberOfTasks = instance.getNumberOfTasks();
    unsigned numberOfAgents = instance.getNumberOfAgents();
    //try to generate feasible initial solution
    //feasible solution is attribute task to the agent with minimal resource consumption
    //and it being less than his resource limit
    
    std::vector<unsigned> resources = instance.getTaskResource();
    std::vector<unsigned> limits = instance.getAgentLimit();
    std::vector<unsigned> aux(numberOfAgents); //vai guardar os recursos necessarios indexados por agente
    int minIndex;
	
	  

    for(unsigned i = 0; i < numberOfTasks; i++) {
        for(unsigned j = 0; j < numberOfAgents; j++) {
            aux[j] = resources[(numberOfTasks * j) + i]; //seleciona "coluna" da tarefa i
        }
        
        minIndex = getMinIndex(aux); //indice do agente que tem o menor recurso
        
        
        //verifica se ele passa do limite; se passa o minIndex tem que ser outro que n passe
        
       
                this->tasks[i] = minIndex; //esse agente vira o dessa task
                
       
                }
            }


Solution::Solution(Instance instance, Solution solution) {
    //Randomly change assignees of three randomly chosen jobs
    tasks = solution.getTasks();
    costs = solution.getCosts();
   
    
    for (unsigned i = 0; i < 3; i++) {
        //choose random job & agent
        unsigned job = std::rand() % instance.getNumberOfTasks();
        unsigned agent = std::rand() % instance.getNumberOfAgents();
        
        tasks[job] = agent;
    }
    
}

bool Solution::isFeasible(Instance instance) {
    unsigned aux = 0;
    
    std::vector<unsigned> resources = instance.getTaskResource();
    
    for (unsigned i = 0; i < instance.getNumberOfAgents(); i++) {
        for (unsigned j = 0; j < instance.getNumberOfTasks(); j++) {
            aux += resources[(instance.getNumberOfTasks() * i) + j]; //soma todos os recursos do agente i
        }
        if (aux > instance.getAgentLimit()[i]) { //se a soma dos resources pra o agente i passa do disponível pra ele
            return false;
        }
    }
    
    return true;
}

std::vector<unsigned> Solution::getTasks() {
    return this->tasks;
}

std::vector<unsigned> Solution::getCosts() {
    return this->costs;
}

int Solution::getTotalCost() {
    
    int aux = 0;
    int numberOfTasks = this->tasks.size();
	
    //iterar pelas tarefas; pegar o agente => acessar custo => somar
    for (int i = 0; i < numberOfTasks; i++) {
        
        int agent = tasks[i];
        aux += costs[(numberOfTasks * agent) + i];
    }
    return aux;
}

double Solution::calculateUnfitness(Instance instance) {
    
    double unfitness = 0;
    
    std::vector<unsigned> aux(instance.getNumberOfAgents(), 0);
    std::vector<unsigned> resources = instance.getTaskResource();
    std::vector<unsigned> limits = instance.getAgentLimit();

    for (int i = 0; i < instance.getNumberOfTasks(); i++) {
        int agent = tasks[i];
        aux[agent] += resources[(instance.getNumberOfTasks() * agent) + i];
    }
    
    for (int i = 0; i < instance.getNumberOfAgents(); i++) {
        
        double diff = double(aux[i]) - double(limits[i]);
        unfitness += std::max(double(0), diff);
    }
    
    return unfitness;
}

int Solution::getMinIndex(std::vector<unsigned> &vector) { //retorna o indice do menor valor de um vetor
    
    std::vector<unsigned>::iterator minIterator = std::min_element(vector.begin(), vector.end());
    
    return std::distance(vector.begin(), minIterator);
}

