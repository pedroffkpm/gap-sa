GLPSOL: GLPK LP/MIP Solver, v4.65
Parameter(s) specified in the command line:
 -m gap.mod -d instances/gapa-4.dat --tmlim 3600
Reading model section from gap.mod...
34 lines were read
Reading data section from instances/gapa-4.dat...
instances/gapa-4.dat:4017: warning: final NL missing before end of file
4017 lines were read
Generating obj...
Generating exec...
Generating res...
Model has been successfully generated
GLPK Integer Optimizer, v4.65
211 rows, 2000 columns, 6000 non-zeros
2000 integer variables, all of which are binary
Preprocessing...
210 rows, 2000 columns, 4000 non-zeros
2000 integer variables, all of which are binary
Scaling...
 A: min|aij| =  1.000e+00  max|aij| =  2.500e+01  ratio =  2.500e+01
GM: min|aij| =  6.687e-01  max|aij| =  1.495e+00  ratio =  2.236e+00
EQ: min|aij| =  4.472e-01  max|aij| =  1.000e+00  ratio =  2.236e+00
2N: min|aij| =  2.500e-01  max|aij| =  1.375e+00  ratio =  5.500e+00
Constructing initial basis...
Size of triangular part is 210
Solving LP relaxation...
GLPK Simplex Optimizer, v4.65
210 rows, 2000 columns, 4000 non-zeros
      0: obj =   5.812000000e+03 inf =   1.674e+02 (1)
    293: obj =   5.611037188e+03 inf =   0.000e+00 (0)
*   765: obj =   2.623000000e+03 inf =   3.164e-14 (0) 1
OPTIMAL LP SOLUTION FOUND
Integer optimization begins...
Long-step dual simplex will be used
+   765: mip =     not found yet >=              -inf        (1; 0)
+   769: >>>>>   2.623000000e+03 >=   2.623000000e+03 < 0.1% (4; 0)
+   769: mip =   2.623000000e+03 >=     tree is empty   0.0% (0; 7)
INTEGER OPTIMAL SOLUTION FOUND
Time used:   0.0 secs
Memory used: 3.4 Mb (3573390 bytes)
