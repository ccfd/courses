import sys, numpy
from time import *

n = 128

A = numpy.random.rand(n, n)
B = numpy.random.rand(n, n)
C = numpy.zeros([n, n])

start = time()
for i in range(n):
    for j in range(n):
        for k in range(n):
            C[i][j] += A[i][k] * B[k][j]
end = time()

print(end - start, 'seconds')
