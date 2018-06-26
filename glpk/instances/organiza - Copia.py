import sys

    
with open(sys.argv[1], 'r') as f:
    f2 = open(sys.argv[2],"w+")
    data = f.readline().split( )
    m = data[0]
    n = data[1]
    c = ''
    
    f2.write(str(m) + '\n')
    f2.write(str(n) + '\n')
    for line in f:
        c = c + line.rstrip('\n')
    c1 = c.split( )
    for j in range (0, int(m)):
        for i in range(0, int(n)):   
            f2.write(c1[i+j*int(n)] + '\n')

    aux = int(m)*int(n)
    
    for j in range (0, int(m)):
        for i in range(0, int(n)):
            f2.write(c1[i+j*int(n)+aux] + '\n')

    
    for j in range (0, int(m)):
            f2.write( c1[j+aux*2] + '\n')
    f2.close()

    