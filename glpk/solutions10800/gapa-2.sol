GLPSOL: GLPK LP/MIP Solver, v4.65
Parameter(s) specified in the command line:
 -m gap.mod -d instances/gapa-2.dat --tmlim 10800
Reading model section from gap.mod...
34 lines were read
Reading data section from instances/gapa-2.dat...
2012 lines were read
Generating obj...
Generating exec...
Generating res...
Model has been successfully generated
GLPK Integer Optimizer, v4.65
206 rows, 1000 columns, 3000 non-zeros
1000 integer variables, all of which are binary
Preprocessing...
205 rows, 1000 columns, 2000 non-zeros
1000 integer variables, all of which are binary
Scaling...
 A: min|aij| =  1.000e+00  max|aij| =  2.500e+01  ratio =  2.500e+01
GM: min|aij| =  6.687e-01  max|aij| =  1.495e+00  ratio =  2.236e+00
EQ: min|aij| =  4.472e-01  max|aij| =  1.000e+00  ratio =  2.236e+00
2N: min|aij| =  2.500e-01  max|aij| =  1.375e+00  ratio =  5.500e+00
Constructing initial basis...
Size of triangular part is 205
Solving LP relaxation...
GLPK Simplex Optimizer, v4.65
205 rows, 1000 columns, 2000 non-zeros
      0: obj =   5.884000000e+03 inf =   1.459e+02 (1)
    248: obj =   5.828841498e+03 inf =   0.000e+00 (0)
*   592: obj =   3.234739130e+03 inf =   3.473e-14 (0) 1
OPTIMAL LP SOLUTION FOUND
Integer optimization begins...
Long-step dual simplex will be used
+   592: mip =     not found yet >=              -inf        (1; 0)
Solution found by heuristic: 3235
+   602: mip =   3.235000000e+03 >=     tree is empty   0.0% (0; 9)
INTEGER OPTIMAL SOLUTION FOUND
Time used:   0.0 secs
Memory used: 1.9 Mb (2043632 bytes)
