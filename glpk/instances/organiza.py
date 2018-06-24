import sys

    
with open(sys.argv[1], 'r') as f:
    f2 = open(sys.argv[2],"w+")
    data = f.readline().split( )
    m = data[0]
    n = data[1]
    c = ''
    f2.write('data;\n')
    f2.write('param m := ' + str(m) + '\n')
    f2.write('param n := ' + str(n) + '\n')
    f2.write('param c := ' + '\n')
    for line in f:
        c = c + line.rstrip('\n')
    c1 = c.split( )
    for j in range (0, int(m)):
        for i in range(0, int(n)):   
            f2.write('    ' + str(j+1) + ' ' + str(i+1) + ' ' + c1[i+j*int(n)] + '\n')

    aux = int(m)*int(n)
    f2.write('param a := ' + '\n')
    for j in range (0, int(m)):
        for i in range(0, int(n)):
            f2.write('    ' + str(j+1) + ' ' + str(i+1) + ' ' + c1[i+j*int(n)+aux] + '\n')

    f2.write('param b := ' + '\n')
    for j in range (0, int(m)):
            f2.write('    ' + str(j+1) + ' ' + c1[j+aux*2] + '\n')
    f2.write('end;')
    f2.close()

    