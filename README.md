# Gaussian-Elimination-with-Partial-Pivoting-for-Square-Matrices

In this project, the main goal is to solve the linear equation system

Ax=b using Gaussian Elimination with partial pivoting algorithms. These algorithms 

can be found in the web easily.

-----------------------------

By realizing that purpose checking whether the matrix A is singular or not carries out

an importance. For this, I used the approach that checking the matrix after the elimination and 

partial pivoting took place and changed the original matrix by row operations. Because of the fact 

that I swapped the highest pivot in a column to the upwards, checking only the last entry of the last
 
column was enough but I checked all the diagonal entries. Besides, checking for only being a zero or 

non-zero does not suffice, because the machine's precision; in other words, Epsilon; is important 

here. Because so small pivots act like a zero and causes matrix to be singular.

-------------------------

Additionally, checking the 1-condition number and infinity-condition number tasks are implemented for 

2x2 matrices. The exact values can be seen after giving input in the terminal.


--------------------------

How to run?

&&&&&&&&&&&&&&&&&&&&&


This program is worked on cmd (command terminal) or the compiler's own terminal. 

As input, this program accepts 4 arguments including the executable file of the code.

You should firstly go to the file where the ".cpp" file is inside and after that write in the form 

like that:


./YourCpp'sNameWithoutExtension AMatrix.txt bMatrix.txt x.txt


Here, x.txt is the file we write the output, x.


-----------------------------------------

Also, with this program, you can see and observe the effects of large condition number to the X.

For example, you can see that small difference in the input causes a big difference in X:


Matrix A is: 
1 1 
1 1.001 

Matrix b is: 
2 2 

1-Condition number is: 4004
Infinity-Condition number is: 4004


SOLUTION VECTOR X:
[2 0 ]^T%        

----------------------------------


Matrix A is: 
1 1 
1 1.001 

Matrix b is: 
2 2.001 

1-Condition number is: 4004
Infinity-Condition number is: 4004

SOLUTION VECTOR X:

[1 1 ]^T
-------------------------------------


Some examples can be seen here:


-------------------------------------
sfasdasdsadadasdasdasdad proj123 % ./dosyalari_okuma A10.txt b10.txt x.txt 
Matrix A is: 
0.288469 0.681283 7.01425 2.25133 4.77281 5.38058 1.04583 -7.0697 -7.52135 3.10452 
7.68562 -8.20099 1.21119 9.799 1.71974 1.62893 2.59767 -6.21856 -0.192854 -0.348586 
1.76052 -7.76589 8.59218 0.553601 -5.06531 8.56626 -9.36018 -9.14695 7.05996 -5.52838 
-6.90495 -7.27415 3.93334 -0.409532 3.32832 1.60181 2.29427 2.70396 7.47855 0.771592 
-6.00274 3.57305 1.65582 6.02695 -8.33034 -9.66034 -2.75177 -4.36266 -4.59411 -4.55877 
-1.8609 -0.0964596 6.30794 -5.44314 2.5192 -7.58281 -9.00935 0.771934 -5.83077 0.591291 
4.97411 -6.20579 7.58028 -0.0381142 3.21889 7.25421 -0.2086 3.90326 1.29959 0.669316 
6.51168 -0.0998835 9.77823 8.01705 4.59504 -0.31407 -6.14979 -0.0176797 2.80624 2.12207 
5.79926 -7.04784 -9.98955 1.49322 7.81504 6.89711 -7.53833 0.716021 -1.65942 2.52563 
-3.62952 -8.90052 7.30877 6.90356 9.64606 -5.8119 -5.89012 -1.09634 -5.88049 3.41852 

Matrix b is: 
[8.95866 -8.35858 -7.88581 -7.15918 -6.67079 2.41917 1.4742 -8.95844 8.62403 4.57323 ]^T

Matrix is singular%                                                                            
sdfadfgsdgadfadfafasdfasfaf proj123 % ./dosyalari_okuma A7.txt b7.txt x.txt 
Matrix A is: 
-4.21871 3.50664 -3.55056 -6.16509 3.66726 -5.27539 6.83858 8.79659 -5.62647 8.65707 
3.43616 -9.86569 5.69479 4.76854 0.931862 -7.61208 6.65834 2.91104 -7.88403 9.45482 
3.90281 2.04341 -0.572857 -5.14301 -1.48542 2.14608 -4.87118 -0.410736 -7.80605 -6.15943 
-8.64014 -2.26458 -9.28475 8.34849 2.88886 -0.997246 2.26921 2.78634 -8.72817 -7.22252 
-4.9042 8.31982 -6.48251 -4.61877 2.95235 -0.82549 1.64498 0.894322 -1.9084 3.92533 
-5.5192 -9.97698 4.43516 5.31 3.58034 3.2389 0.814787 2.94623 -1.03254 -8.1236 
3.35665 -0.751017 -0.53028 -6.22676 2.71573 5.40571 7.39882 0.877719 -2.68368 0.508088 
6.88784 -1.51302 -6.94558 -4.25004 8.90348 -2.99564 -4.70442 4.42093 5.27009 0.606884 
-3.11075 -0.781673 -3.17751 -8.17773 -5.8213 3.24019 -3.63852 0.449906 2.55793 7.2228 
5.61039 5.40319 2.14778 1.52419 4.18563 -1.67683 -7.61571 9.87409 5.43961 -0.302933 

Matrix b is: 
[-2.13087 3.42862 4.82516 0.401049 -3.04575 -7.00005 1.72184 -4.75709 -9.11092 5.09867 ]^T

SOLUTION VECTOR X:

[0.953687 0.64322 -0.00893717 0.603682 -0.572178 0.00591031 0.431477 0.295362 -0.354223 -0.240896 ]^T



										All rights reserved.
