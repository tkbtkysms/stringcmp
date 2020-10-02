# stringcmp
A fast computation of Milnor invariants

## Compile
```Shell
$ cd src
$ make
```

## How to make input files
In the following, we use our paper's notation.
In this software, we change the segment and inverse names ($a_{i,j}$ and $a_{i,j}^{-1}$) to positive integers based on the following rules.
1. $a_{1,1}$ to 1.
2. $a_{i,1} (i > 1)$ to the odd number adding 2 to the odd number representation of the last segment of $l_{i-1}$.
3. $a_{i,j} (i > 1, j > 1)$ to the odd number adding 2 to the odd number representation of $a_{i,j-1}$.
4. $a_{i,j}^{-1}$ to the even number adding 1 to the odd number representation of $a_{i,j}$.

The input file is a space-separated value file that we write the above integer representations from $l_1$ to $l_k$, where $k$ is the number of strings in the input knot. The below figure is the example of the input file.



## Execution
```Shell
# we can execunte in stringcmp/src.
$ ./milnor od nel input_file1 input_file2 first_longitude1 first_longitude2 num_magnus_expansion max_degree 
```
The 1st argument (od) is the computation mode ('o' or 'd').
- o: compute the Milnor invariant of input_file1. 
- d: compute the difference of two Milnor invariants (input_file1 and input_file2)

The 2nd argument (nel) is the type of Milnor invariant ('n', 'e' or 'l').
- n: compute the standard Milnor invariant.
- e: change the monomial transformations ($a_{i,j}\to 1 + X_i$ and $a_{i,j}^{-1}\to 1 - X_i + X_i^{2} \cdots X_i^k$, where $k$ is max_degree)
  to Maclaurin expansions of $e^x$ and $e^{-x}$ ($a_{i,j} \to 1 + X_i + \frac{1}{2!}X_i^2 + \cdots \frac{1}{k!}X_i^k$ and $a_{i,j}^{-1} \to 1 + X_i - \frac{1}{2!}X_i^2 + \cdots \frac{1}{k!}X_i^k$).
- l: compute the Milnor invariant link homotopy

The 3rd argument (input_file1) is the 1st input file name.

The 4th argument (input_file2) is the 2nd input file name.
**In the case we set 'o' to the 1st argument, we cannot set this argument.**

The 5th argument (first_longitude1) is the positive integer representing input_file1's longitude starting its magnus expansion.

The 6th argument (first_longitude2) is the positive integer representing input_file2's longitude starting its magnus expansion.
**In the case we set 'o' to the 1st argument, we cannot set this argument.**

The 7th argument (num_magnus_expansion) is the positive integer representing the number of magnus expation.

The 8th argument (max_degree) is the positive integer representing maxmum degree of polynomials.

## Execution examples
### Compute the standard Milnor invariant for stringcmp/sample/Y.txt. The first longitude, the number of magnus expansions and the maximum degree of polynomials are 1, 3, 4, respectively.
```Shell
$ ./milnor o n ../sample/Y.txt 1 3 4 
# the below is the output of this execution.
input file # display ../sample/Y.txt
12 1 13 
4 5 

transformed input file # I forget why this transformation is required.
2 14 3 15 
6 7 

answer1 1 + XYY - 2YXY + YYX - XXYY + XYXY - XYYY + YXXY - YXYX + YXYY + YYXY - YYYX # Milnor invariant
Calculating time:0.000786
```

### Change the monomial transformations of the standard Milnor invariant to Maclaurin expansions of $e^x$ and $e^{-x}$
```Shell
# change the 2nd argument 'n' to 'e'
$ ./milnor o e ../sample/Y.txt 1 3 4

input file
12 1 13 
4 5 

transformed input file
2 14 3 15 
6 7 

answer1: 1 + XYY - 2YXY + YYX - 1/2XXYY + XYXY - YXYX + 1/2YYXX # Milnor invariant with Maclaurin expansions of $e^x$ and $e^{-1}$


Calculating time:0.001295

```

### Compute the Milnor invariant link homotopy
```Shell
#  change the 2nd argument 'l'
$ ./milnor o l ../sample/Y.txt 1 3 4
#input file
12 1 13 
4 5 

transformed input file
2 14 3 15 
6 7 

answer1: 1 # Milnor invariant link homotopy


Calculating time:0.000829
```


### Change the input file stringcmp/sample/Y.txt to stringcmp/sample/ex1.txt
```Shell
# change the 3rd argument '../sample/Y.txt' to '../sample/ex1.txt'
$ ./milnor o n ../sample/ex1.txt 1 3 4 # compute the standard Milnor invariant
input file
8 17 21 
8 5 18 23 3 
5 15 

transformed input file
1 12 21 25 
11 12 7 22 27 5 
7 19 

answer1 1 + X + Z - XY + XZ + YX + YZ - ZY - XYZ + YXY + YXZ - YYX - 2YYZ + YZX + 3YZY + YZZ - ZYX - ZYY - 2ZYZ + ZZY + XXYY - XYXY - XYYX - XYYZ + XZYY - YXXY + 3YXYX + 3YXYZ - 2YXZY - YYXX - YYXY - YYXZ + YYYX + 3YYYZ - 3YYZX - 5YYZY - 3YYZZ + YZXY + YZXZ + 4YZYX + 2YZYY + 7YZYZ - 2YZZY - ZYXY - ZYXZ - ZYYX - ZYYZ - ZYZX - 3ZYZY - ZYZZ + ZZYX + 2ZZYY + 2ZZYZ - ZZZY
Calculating time:0.003693
```

### Change the first longitude '1' to '2'.
```Shell
# change the 4th argument '1' to '2'
$ ./milnor o n ../sample/ex1.txt 2 3 4
input file
8 17 21 
8 5 18 23 3 
5 15 

transformed input file
1 12 21 25 
11 12 7 22 27 5 
7 19 

answer1 1 + 2X - Y + Z + XX - XY - YX + YY - 2YZ + 2ZX + ZY - 2XXY + 3XYX + XYY + XYZ - XZY - 2YXX + YYX - YYY + 3YYZ - 5YZX - 2YZY - YZZ + ZXX - ZXY + 4ZYX + 2ZYZ - ZZY + XXXY - 3XXYX + XXYY - XXYZ + XXZY + 3XYXX - XYYX - XYYY - 2XYYZ + 3XYZX + 3XYZY - 3XZYX - XZYY - XZYZ + XZZY - YXXX + 2YXXY - 4YXYX - YXYZ + YXZY + 3YYXX - YYYX + YYYY - 4YYYZ + 9YYZX + 3YYZY + 3YYZZ - 4YZXX + 2YZXY - 10YZYX - 5YZYZ - 2YZZX + YZZY - 2ZXXY + 3ZXYX + ZXYY + ZXYZ - ZXZY + 2ZYXX - 2ZYXY + 2ZYYX - ZYYZ + 4ZYZX + 3ZYZY + ZYZZ - 2ZZYX - ZZYY - 2ZZYZ + ZZZY
Calculating time:0.003639


Calculating time:0.00136
```

### Change the number of magnus expansion '3' to '5'
```Shell
# change the 5th argument '3' to '5'
$ ./milnor o n ../sample/ex1.txt 2 2 4
input file
8 17 21 
8 5 18 23 3 
5 15 

transformed input file
1 12 21 25 
11 12 7 22 27 5 
7 19 

answer1 1 + 2X - Y + Z + XX - XY - YX + YY - 2YZ + 2ZX + ZY - 2XXY + 3XYX + XYY + XYZ - XZY - 2YXX + YYX - YYY + 3YYZ - 5YZX - 2YZY - YZZ + ZXX - ZXY + 4ZYX + 2ZYZ - ZZY + XXXY - 3XXYX + 3XXYY - 2XXYZ + 3XYXX - 4XYXY + 3XYXZ - XYYX - 2XYYY - XYYZ + 2XYZX + XYZZ + XZXY - 2XZYX + 2XZYY - 2XZYZ + XZZY - YXXX + 2YXXY - YXXZ + 3YXYY - YXZX - 2YXZY + YYXX - 3YYXY + YYXZ + YYYY - 3YYYZ + 6YYZX + 3YYZZ - 3YZXX + 5YZXY - YZXZ - 7YZYX + 3YZYY - 5YZYZ - 2YZZX + YZZY - ZXXY + 3ZYXX - 3ZYXY + ZYXZ + ZYYX - ZYYY - ZYYZ + 5ZYZX + 3ZYZY + ZYZZ - 3ZZYX - ZZYY - 2ZZYZ + ZZZY
Calculating time:0.002564

```

### Change the maximum degree of polynomials '4' to '3'
```Shell
# change the 6th argument '4' to '3'
$ ./milnor o n ../sample/ex1.txt 2 2 3
input file
8 17 21 
8 5 18 23 3 
5 15 

transformed input file
1 12 21 25 
11 12 7 22 27 5 
7 19 

answer1 1 + 2X - Y + Z + XX - XY - YX + YY - 2YZ + 2ZX + ZY - 2XXY + 3XYX + XYY + XYZ - XZY - 2YXX + YYX - YYY + 3YYZ - 5YZX - 2YZY - YZZ + ZXX - ZXY + 4ZYX + 2ZYZ - ZZY
Calculating time:0.001511
```
### Compute the diffrence of stringcmp/sample/ex1.txt and stringcmp/sample/ex2.txt. The type of Milnor invariant and the first longitude of the 2nd input file are standard and 1, respectively.  
```Shell
# change the 1st argument 'o' to 'd' and set '../sample/ex2.txt' (resp. '1') to the 4th argument (resp. the 6th argument)   
$ ./milnor d n ../sample/ex1.txt ../sample/ex2.txt 2 1 2 3
input file # display the 1st input file  
8 17 21 
8 5 18 23 3 
5 15 

transformed input file # transform the 1st input file
1 12 21 25 
11 12 7 22 27 5 
7 19 

input file # display the 2nd input file
26 31 7 25 8 
17 5 36 24 
22 17 19 6 23 14 29 

transformed input file # trasnform the 2nd input file
32 37 7 31 8 
14 19 5 42 30 
26 26 28 19 21 6 29 16 35 

answer1 1 + 2X - Y + Z + XX - XY - YX + YY - 2YZ + 2ZX + ZY - 2XXY + 3XYX + XYY + XYZ - XZY - 2YXX + YYX - YYY + 3YYZ - 5YZX - 2YZY - YZZ + ZXX - ZXY + 4ZYX + 2ZYZ - ZZY # the Milnor invarinant of the 1st input file

answer2 1 + Z + 2XZ - 2YZ - 2ZX + 2ZY - 2XZX + 2XZY + XZZ - 2YXZ + 3YYZ + 2YZX - 4YZY - YZZ + 2ZXX - 2ZXY - 2ZXZ + ZYY + 2ZYZ + ZZX - ZZY  # the  Milnor invariant of the 2nd input file


diff 2X - Y + XX - XY - 2XZ - YX + YY + 4ZX - ZY - 2XXY + 3XYX + XYY + XYZ + 2XZX - 3XZY - XZZ - 2YXX + 2YXZ + YYX - YYY - 7YZX + 2YZY - ZXX + ZXY + 2ZXZ + 4ZYX - ZYY - ZZX  # answer1 -  answer2

Calculating time:0.00495


# simiraly to the case that the 1st argument is 'o', we can change the 2nd - 8th argument.
```
