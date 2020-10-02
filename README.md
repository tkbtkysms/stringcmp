# stringcmp
A fast computation of Milnor invariants

## Compile
```Shell
$ cd src
$ make
```

## How to make input files
under construction

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
$ ./milnor o n ../sample/Y.txt 1 3 4 # execute in stringcmp/src
```

### Change the monomial transformations of standard Milnor invariant to Maclaurin expansions of $e^x$ and $e^{-x}$
```Shell
# change the 2nd argument 'n' to 'l'
$ ./milnor o e ../sample/Y.txt 1 3 4
```

### Compute the Milnor invariant link homotopy
```Shell
# change the 2nd argument 'e' to 'l'
$ ./milnor o l ../sample/Y.txt 1 3 4
```

### Change the input file stringcmp/sample/Y.txt to stringcmp/sample/ex1.txt
```Shell
# change the 3rd argument '../sample/Y.txt' to '../sample/ex1.txt'
$ ./milnor o l ../sample/ex1.txt 2 3 4
```

### Change the first longitude '1' to '2'.
```Shell
# change the 4th argument '1' to '2'
$ ./milnor o l ../sample/Y.txt 2 3 4
```

### Change the number of magnus expansion '3' to '5'
```Shell
# change the 5th argument '3' to '5'
$ ./milnor o l ../sample/ex1.txt 2 5 4
```

### Change the maximum degree of polynomials '4' to '3'
```Shell
# change the 6th argument '4' to '3'
$ ./milnor o l ../sample/ex1.txt 2 5 3
```
### Compute the diffrence of stringcmp/sample/ex1.txt and stringcmp/sample/ex2.txt. The type of Milnor invariant and the first longitude of the 2nd input file are standard and 1, respectively.  
```Shell
# change the 1st argument 'o' (resp. the 2nd argument 'l') to 'd' (resp. 'n') and set '../sample/ex2.txt' (resp. '1') to the 4th argument (resp. the 6th argument)   
$ ./milnor d n ../sample/ex1.txt ../sample/ex2.txt 2 1 5 3
# simiraly to the case that the 1st argument is 'o', we can change the 2nd - 8th argument.
```
