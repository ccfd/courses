---
number: 9
course: Computer Science 1
material: Instruction 9
---

## 1.
Create a file containing a vector `w` and its length in the first line.
The file should look in the following way:
```
N
w1
w2
w3
...
wN
```
## 2.
Write a program which contains a static array `w` of length `MAX_N` and three two-dimensional static arrays `A`, `B` and `C` of sizes $[MAX_N x MAX_M]$, $[MAX_M x MAX_L]$ and $[MAX_N x MAX_L]$ correspondingly.

## 3.
Read the length $N$ of the vector `w` and and check if `MAX_N`$\ge$`N`.
If the condition is fulfilled, read the vector into the array.

## 4.
Check if `MAX_M`$\ge$`N` and if the condition is satisfied, create the array `B` which elements are defined by the formula:
$$
b_{ij} =
\left\{
\begin{array}{ll}
1-w_i w_j,& \; i=j \\
-2w_i w_j,& \; i \ne j
\end{array}
\right.
$$
## 5.
Write a function which prints an array passed as its argument to the file "mac.txt".
Run the function with the array `B` as the argument.


## 6.
Write two functions:

a. the first one should compute a product of two matrices `A` and `B`:
$C = A \cdot B$, or in another way $C_{ij} = \sum_{k=1}^M A_{ik} B_{kj}$
b. the second one should compute a transposition of a given matrix.

## 7.
Use both functions from the point 6 and calculate the matrix:
$C = B \cdot B^T$.