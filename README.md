# CSCE_1040_Lab_1_Assignment

You are to write a program that reads in lines of input using scanf or cin, and file redirection, process the data, and then output
the results using printf or cout. This means you can use C or C++ style I/O as is your personal preference.
Name your file lab1assignment.cpp. Failure to name the file correctly may lead to a grade of zero.
The data file used in the example is available at: ~dmk0080/public/1040/labs/one.
or in the Cavans assignment. Use the file named "transactiondata"
3. Use command line redirection to execute as in ./a.out < transactiondata
4. to compile use g++ labassignment1.cpp to create the executable file a.out
1.
2.
The data:
1.
2.
3.
4.
5.
6.
Each line of th named "transactione data file begins with an 'e', 'c', or 't'.
Lines beginning with 'e' will have an integer employee ID and an employee name.
Lines beginning with 'c' will have an integer customer ID, customer name, and a floating point account balance.
Lines beginning with a 't' will have a customer ID, employee ID, a 'w' or 'd' representing withdrawal or deposit,
and a floating point transaction amount.
Lines beginning with an 'e' and 'c' may be intermingled, but all 'e' and 'c' lines will come before lines beginning
with 't'.
There will be at most 50 employees and 50 customers, and an unknown number of transactions. Names will be at
most 15 characters long.
An example data file is shown below:
e
c
e
e
c
c
e
c
c
e
e
e
c
e
c
c
e
e
c
c
t
t
t
t
t
t
t
t
t
t
t
t
t
t
t
t
t
5 Elden
3 Felipe
55342.51415
3 Leonardo
1 Yong
9 Alessandra 8114.541862
6 Marnie
15287.78233
8 Kourtney
2 Lou
95053.44742
5 Numbers
51245.66138
4 Jarvis
9 Marlen
10 Florance
1 Devon
56442.27875
2 Elliott
8 Justina
73723.84849
10 Reyna
82946.53205
6 Antonetta
7 Florene
4 Merrill
98281.82784
7 Marlana
33252.21805
1 8 w 4924.86
9 6 d 3220.42
6 1 w 127.62
9 8 w 5566.7
9 8 d 5414.55
5 7 w 9422.35
9 10 d 1382.07
4 7 d 6131.07
8 2 w 2362.22
8 10 d 5834.48
5 4 w 5150.73
6 2 d 3795.96
1 9 w 3919.45
5 2 w 5037.31
3 9 w 8129.21
8 6 d 1235.67
2 4 d 6901.28
Page ! 1 of 2t 8 10 d 5599.44
t 6 9 d 1936.16
t 7 9 d 7363.98
Your program should read in the employee and customer information and update the customer account balance depending
on the transaction. For example, t 1 8 w 4924.86 means to update the balance for customer 1 by withdrawing
4924.86 from Devon's account balance of 56442.27875 . For each transaction, output customer name, the employee
name, a plus sign for deposit or a minus sign for withdrawal, the transaction amount, and the new balance after the
transaction with two decimal places (truncate values; do not worry about rounding). For example, the output for the
example transaction above would appear as (include the line of digits):
123456789012345678901234567890123456789012345678901234567890
Devon
Kourtney -$4924.86 $ 51517.42
For the above the data file, your output would be:
123456789012345678901234567890123456789012345678901234567890
Devon
Kourtney -$4924.86 $ 51517.42
Alessandra
Antonetta +$3220.42 $ 11334.96
Marnie
Yong -$ 127.62 $ 15160.16
Alessandra
Kourtney -$5566.70 $ 5768.26
Alessandra
Kourtney +$5414.55 $ 11182.81
Numbers
Florene -$9422.35 $ 41823.31
Alessandra
Florance +$1382.07 $ 12564.88
Merrill
Florene +$6131.07 $104412.90
Justina
Elliott -$2362.22 $ 71361.63
Justina
Florance +$5834.48 $ 77196.11
Numbers
Jarvis -$5150.73 $ 36672.58
Marnie
Elliott +$3795.96 $ 18956.12
Devon
Marlen -$3919.45 $ 47597.97
Numbers
Elliott -$5037.31 $ 31635.27
Felipe
Marlen -$8129.21 $ 47213.30
Justina
Antonetta +$1235.67 $ 78431.78
Lou
Jarvis +$6901.28 $101954.73
Justina
Florance +$5599.44 $ 84031.22
Marnie
Marlen +$1936.16 $ 20892.28
Marlana
Marlen +$7363.98 $ 40616.20
You should create structures to hold the data for each employee and for the customers,
including their current balance. Then create arrays of these structures. You will need
counters to keep track of the next available space in each array, as well as to use for
loop control when searching for information. The arrays may be fixed size base on the
limits provided above. When you receive a 't" command you can get the employee name
and customer name and balance from the arrays. Be sure to update the customer balance
to complete the transaction processing. You will output the iformation as described above.
When oyu have completed and tested your program on the CSE Linux Servers, you will need
to download it to your local machine, and then upload it to the assignment box in Canvas
for Lab1. Be sure to include all the files needed to compile, link and run your program
if you created more than a single program file.
