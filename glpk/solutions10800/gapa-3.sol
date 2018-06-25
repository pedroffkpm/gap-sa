GLPSOL: GLPK LP/MIP Solver, v4.65
Parameter(s) specified in the command line:
 -m gap.mod -d instances/gapa-3.dat --tmlim 10800
Reading model section from gap.mod...
34 lines were read
Reading data section from instances/gapa-3.dat...
2017 lines were read
Generating obj...
Generating exec...
Generating res...
Model has been successfully generated
GLPK Integer Optimizer, v4.65
111 rows, 1000 columns, 3000 non-zeros
1000 integer variables, all of which are binary
Preprocessing...
110 rows, 1000 columns, 2000 non-zeros
1000 integer variables, all of which are binary
Scaling...
 A: min|aij| =  1.000e+00  max|aij| =  2.500e+01  ratio =  2.500e+01
GM: min|aij| =  6.687e-01  max|aij| =  1.495e+00  ratio =  2.236e+00
EQ: min|aij| =  4.472e-01  max|aij| =  1.000e+00  ratio =  2.236e+00
2N: min|aij| =  2.500e-01  max|aij| =  1.375e+00  ratio =  5.500e+00
Constructing initial basis...
Size of triangular part is 110
Solving LP relaxation...
GLPK Simplex Optimizer, v4.65
110 rows, 1000 columns, 2000 non-zeros
      0: obj =   2.900000000e+03 inf =   7.625e+01 (1)
    143: obj =   2.948775120e+03 inf =   0.000e+00 (0)
*   417: obj =   1.358556923e+03 inf =   7.176e-16 (0) 1
OPTIMAL LP SOLUTION FOUND
Integer optimization begins...
Long-step dual simplex will be used
+   417: mip =     not found yet >=              -inf        (1; 0)
+   448: >>>>>   1.376000000e+03 >=   1.359000000e+03   1.2% (21; 0)
Solution found by heuristic: 1365
Solution found by heuristic: 1363
+   496: >>>>>   1.361000000e+03 >=   1.360000000e+03 < 0.1% (22; 29)
+   530: >>>>>   1.360000000e+03 >=   1.360000000e+03   0.0% (12; 63)
+   530: mip =   1.360000000e+03 >=     tree is empty   0.0% (0; 91)
INTEGER OPTIMAL SOLUTION FOUND
Time used:   0.1 secs
Memory used: 1.9 Mb (1999636 bytes)
