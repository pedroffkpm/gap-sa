GLPSOL: GLPK LP/MIP Solver, v4.65
Parameter(s) specified in the command line:
 -m gap.mod -d instances/gapd-2.dat --tmlim 10800
Reading model section from gap.mod...
34 lines were read
Reading data section from instances/gapd-2.dat...
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
 A: min|aij| =  1.000e+00  max|aij| =  1.000e+02  ratio =  1.000e+02
GM: min|aij| =  3.178e-01  max|aij| =  3.146e+00  ratio =  9.898e+00
EQ: min|aij| =  1.021e-01  max|aij| =  1.000e+00  ratio =  9.798e+00
2N: min|aij| =  6.250e-02  max|aij| =  1.281e+00  ratio =  2.050e+01
Constructing initial basis...
Size of triangular part is 205
Solving LP relaxation...
GLPK Simplex Optimizer, v4.65
205 rows, 1000 columns, 2000 non-zeros
      0: obj =   1.164500000e+04 inf =   2.781e+02 (1)
    249: obj =   1.665345730e+04 inf =   0.000e+00 (0)
*   659: obj =   1.273619608e+04 inf =   7.660e-13 (0) 1
OPTIMAL LP SOLUTION FOUND
Integer optimization begins...
Long-step dual simplex will be used
+   659: mip =     not found yet >=              -inf        (1; 0)
Solution found by heuristic: 12974
Solution found by heuristic: 12954
Solution found by heuristic: 12812
Solution found by heuristic: 12783
Solution found by heuristic: 12774
+ 25104: mip =   1.277400000e+04 >=   1.273700000e+04   0.3% (4134; 1862)
+ 50190: mip =   1.277400000e+04 >=   1.273800000e+04   0.3% (8999; 1921)
+ 74506: mip =   1.277400000e+04 >=   1.273800000e+04   0.3% (13818; 1983)
+ 98051: mip =   1.277400000e+04 >=   1.273800000e+04   0.3% (18511; 2047)
+121143: mip =   1.277400000e+04 >=   1.273800000e+04   0.3% (23036; 2103)
+143660: mip =   1.277400000e+04 >=   1.273800000e+04   0.3% (27480; 2159)
+166220: mip =   1.277400000e+04 >=   1.273800000e+04   0.3% (31881; 2215)
+187875: mip =   1.277400000e+04 >=   1.273800000e+04   0.3% (36334; 2273)
Solution found by heuristic: 12771
+210380: mip =   1.277100000e+04 >=   1.273800000e+04   0.3% (38448; 6192)
+232702: mip =   1.277100000e+04 >=   1.273800000e+04   0.3% (42735; 6254)
+240475: mip =   1.277100000e+04 >=   1.273800000e+04   0.3% (44265; 6276)
Time used: 7252.5 secs.  Memory used: 40.9 Mb.
+259974: mip =   1.277100000e+04 >=   1.273800000e+04   0.3% (48098; 6330)
+283353: mip =   1.277100000e+04 >=   1.273800000e+04   0.3% (52513; 6398)
+305969: mip =   1.277100000e+04 >=   1.273800000e+04   0.3% (56797; 6465)
+328123: mip =   1.277100000e+04 >=   1.273800000e+04   0.3% (61062; 6528)
Solution found by heuristic: 12758
+348922: mip =   1.275800000e+04 >=   1.273800000e+04   0.2% (44718; 47635)
+368089: mip =   1.275800000e+04 >=   1.273800000e+04   0.2% (48689; 47723)
+386952: mip =   1.275800000e+04 >=   1.273800000e+04   0.2% (52611; 47800)
+406459: mip =   1.275800000e+04 >=   1.273800000e+04   0.2% (56577; 47879)
+426329: mip =   1.275800000e+04 >=   1.273800000e+04   0.2% (60503; 47955)
+445378: mip =   1.275800000e+04 >=   1.273800000e+04   0.2% (64312; 48036)
#449493: obj =   1.273828275e+04 inf =   0.000e+00 (1) 100%
+449493: mip =   1.275800000e+04 >=   1.273800000e+04   0.2% (65111; 48058)
TIME LIMIT EXCEEDED; SEARCH TERMINATED
Time used:   14504.6 secs
Memory used: 58.1 Mb (60879526 bytes)
