# Password-Cracker

=> g++ pass_cracker.cpp

=> ./a.out

**Project Overview**

In this Project,I I implement a distributed "**password cracker**". This project is  implemented for 
a clustered computing environment with multiple nodes running **MPICH implementation of the MPI 
specification**. 

In order to decipher a password, I used **brute force** (testing for all possible combinations) and as 
the number of combinations increases exponentially with the size of password, we needed a distributed 
system to assist us in this task. The project would come into its own for problems of significant complexity.

One way to encrypt a password is using a cryptographic hash function. As the name suggests, it 
is a hash function that takes an input and returns a fixed-size alphanumeric string. 

Ideally, it should be extremely computationally difficult to regenerate the password given 
only the hashed text. One example of the usage of such cryptographic hash function is password
management in Operating Systems. 

Instead of storing the password in plain text, the OS encrypts (computes hash) and saves it. 

As a result, even if someone steals the password information (for instance /etc/shadow file 
containing the hashes of the password), he/she doesn’t immediately learn the passwords. 
For our project I used the **Ubuntu Linux distribution** and it uses **SHA-512 algorithm** to store 
the encrypted passwords. 
