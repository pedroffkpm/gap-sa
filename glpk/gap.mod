param n >= 0;
/* number of agents */

set I := 1..n;
/* set of agents */

param m >= 0;
/* number of tasks */

set J := 1..m;
/* set of tasks */

param c{i in I, j in J}, integer, >= 0;
/* cost of assigning agent i to task j */

param a{i in I, j in J}, integer, >= 0;
/* resource for agent i to complete task j */

param b{i in I}, integer, >= 0;
/* resources available to agent i */

 var x{i in I, j in J}, binary;
 /* 1 if agent i is assigned to task j, 0 otherwise */

 minimize obj: sum{i in I, j in J} c[i,j] * x[i,j];
 /* minimize costs */

 s.t. exec{j in J}: sum{i in I} x[i,j] = 1;
 /* each task is executed  exactly once */

 s.t. res{i in I}: sum{j in J} x[i,j] * a[i,j] <= b[i];
 /* each agent can request at most b[i] resources */

 end;
