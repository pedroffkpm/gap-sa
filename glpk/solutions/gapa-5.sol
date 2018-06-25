GLPSOL: GLPK LP/MIP Solver, v4.65
Parameter(s) specified in the command line:
 -m gap.mod -d instances/gapa-5.dat --tmlim 3600
Reading model section from gap.mod...
34 lines were read
Reading data section from instances/gapa-5.dat...
instances/gapa-5.dat:4027: warning: final NL missing before end of file
4027 lines were read
Generating obj...
Generating exec...
Generating res...
Model has been successfully generated
GLPK Integer Optimizer, v4.65
121 rows, 2000 columns, 6000 non-zeros
2000 integer variables, all of which are binary
Preprocessing...
120 rows, 2000 columns, 4000 non-zeros
2000 integer variables, all of which are binary
Scaling...
 A: min|aij| =  1.000e+00  max|aij| =  2.500e+01  ratio =  2.500e+01
GM: min|aij| =  6.687e-01  max|aij| =  1.495e+00  ratio =  2.236e+00
EQ: min|aij| =  4.472e-01  max|aij| =  1.000e+00  ratio =  2.236e+00
2N: min|aij| =  2.500e-01  max|aij| =  1.375e+00  ratio =  5.500e+00
Constructing initial basis...
Size of triangular part is 120
Solving LP relaxation...
GLPK Simplex Optimizer, v4.65
120 rows, 2000 columns, 4000 non-zeros
      0: obj =   3.049000000e+03 inf =   8.781e+01 (1)
    171: obj =   3.189392397e+03 inf =   0.000e+00 (0)
*   496: obj =   1.157080000e+03 inf =   2.099e-15 (0) 1
OPTIMAL LP SOLUTION FOUND
Integer optimization begins...
Long-step dual simplex will be used
+   496: mip =     not found yet >=              -inf        (1; 0)
+   521: >>>>>   1.161000000e+03 >=   1.158000000e+03   0.3% (19; 0)
Solution found by heuristic: 1158
+   522: mip =   1.158000000e+03 >=     tree is empty   0.0% (0; 37)
INTEGER OPTIMAL SOLUTION FOUND
Time used:   0.0 secs
Memory used: 3.3 Mb (3474812 bytes)
