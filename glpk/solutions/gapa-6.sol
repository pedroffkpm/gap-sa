GLPSOL: GLPK LP/MIP Solver, v4.65
Parameter(s) specified in the command line:
 -m gap.mod -d instances/gapa-6.dat --tmlim 3600
Reading model section from gap.mod...
34 lines were read
Reading data section from instances/gapa-6.dat...
instances/gapa-6.dat:8027: warning: final NL missing before end of file
8027 lines were read
Generating obj...
Generating exec...
Generating res...
Model has been successfully generated
GLPK Integer Optimizer, v4.65
221 rows, 4000 columns, 12000 non-zeros
4000 integer variables, all of which are binary
Preprocessing...
220 rows, 4000 columns, 8000 non-zeros
4000 integer variables, all of which are binary
Scaling...
 A: min|aij| =  1.000e+00  max|aij| =  2.500e+01  ratio =  2.500e+01
GM: min|aij| =  6.687e-01  max|aij| =  1.495e+00  ratio =  2.236e+00
EQ: min|aij| =  4.472e-01  max|aij| =  1.000e+00  ratio =  2.236e+00
2N: min|aij| =  2.500e-01  max|aij| =  1.375e+00  ratio =  5.500e+00
Constructing initial basis...
Size of triangular part is 220
Solving LP relaxation...
GLPK Simplex Optimizer, v4.65
220 rows, 4000 columns, 8000 non-zeros
      0: obj =   5.744000000e+03 inf =   1.721e+02 (1)
    339: obj =   5.798880680e+03 inf =   0.000e+00 (0)
*   924: obj =   2.337327333e+03 inf =   2.513e-14 (0) 1
OPTIMAL LP SOLUTION FOUND
Integer optimization begins...
Long-step dual simplex will be used
+   924: mip =     not found yet >=              -inf        (1; 0)
+   979: >>>>>   2.341000000e+03 >=   2.338000000e+03   0.1% (33; 0)
+  1061: >>>>>   2.340000000e+03 >=   2.339000000e+03 < 0.1% (69; 19)
+  1066: >>>>>   2.339000000e+03 >=   2.339000000e+03   0.0% (39; 85)
+  1066: mip =   2.339000000e+03 >=     tree is empty   0.0% (0; 173)
INTEGER OPTIMAL SOLUTION FOUND
Time used:   0.2 secs
Memory used: 6.8 Mb (7100390 bytes)
