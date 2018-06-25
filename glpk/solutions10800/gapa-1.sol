GLPSOL: GLPK LP/MIP Solver, v4.65
Parameter(s) specified in the command line:
 -m gap.mod -d instances/gapa-1.dat --tmlim 10800
Reading model section from gap.mod...
34 lines were read
Reading data section from instances/gapa-1.dat...
1012 lines were read
Generating obj...
Generating exec...
Generating res...
Model has been successfully generated
GLPK Integer Optimizer, v4.65
106 rows, 500 columns, 1500 non-zeros
500 integer variables, all of which are binary
Preprocessing...
105 rows, 500 columns, 1000 non-zeros
500 integer variables, all of which are binary
Scaling...
 A: min|aij| =  1.000e+00  max|aij| =  2.500e+01  ratio =  2.500e+01
GM: min|aij| =  6.687e-01  max|aij| =  1.495e+00  ratio =  2.236e+00
EQ: min|aij| =  4.472e-01  max|aij| =  1.000e+00  ratio =  2.236e+00
2N: min|aij| =  2.500e-01  max|aij| =  1.375e+00  ratio =  5.500e+00
Constructing initial basis...
Size of triangular part is 105
Solving LP relaxation...
GLPK Simplex Optimizer, v4.65
105 rows, 500 columns, 1000 non-zeros
      0: obj =   3.023000000e+03 inf =   7.256e+01 (1)
    120: obj =   3.387250000e+03 inf =   0.000e+00 (0)
*   319: obj =   1.697727273e+03 inf =   2.258e-14 (0)
OPTIMAL LP SOLUTION FOUND
Integer optimization begins...
Long-step dual simplex will be used
+   319: mip =     not found yet >=              -inf        (1; 0)
Solution found by heuristic: 1698
+   319: mip =   1.698000000e+03 >=     tree is empty   0.0% (0; 1)
INTEGER OPTIMAL SOLUTION FOUND
Time used:   0.0 secs
Memory used: 1.0 Mb (1042970 bytes)
