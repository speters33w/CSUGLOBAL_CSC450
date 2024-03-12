## Module 5: Critical Thinking

### User Input Program

Demonstrate an understanding of C++ programming concepts by completing the following:

1. Program: Create a C++ program that will obtain input from a user and store it into the provided [CSC450_CT5_mod5.txt](./CSC450_CT5_mod5.txt) file
2. Download [CSC450_CT5_mod5.txt](./CSC450_CT5_mod5.txt) file. Your program should append it to the provided text file, without deleting the existing data: 
   1. Store the provided data in the CSC450_CT5_mod5.txt file.
   2. Create a reversal method that will reverse all of the characters in the CSC450_CT5_mod5.txt file and store the result in a CSC450-mod5-reverse.txt file.

Compile and submit your pseudocode, source code, and screenshots of the application executing the application, the results and your GIT repository in a single document.

Reginald Haseltine     

Feb 2, 2024 Local: Feb 2 at 3:22pm<br>Course: Feb 2 at 1:22pm

Module 5 Introduction

In this module we're taking a look at concurrency, specifically where there are multiple threads of execution within a single program.

With multiple threads, it is important to synchronize them to achieve the correct results, for example when the threads are accessing a common variable.

One of the common problems that can occur with concurrent programs is a race condition where multiple threads are trying to access a shared resource simultaneously and possible change its value.

We'll be investigating how race conditions can be avoided by using a mutex and locks, as well as other thread management techniques.

In this week's CT assignment you'll be appending text to the end of an existing file, reversing the text, and then storing the reversed text into another file.

Please do not include a pathname for your local computer to your files since this means it will need to be removed to check your code. Just include the appropriate file names. 

**To receive full credit for the packaging requirements for your Critical Thinking and Portfolio assignments you must:**

**1) Put your C++ source code in .cpp text files. Note that I execute all your programs to check them out.**

**2) In a Word or PDF "documentation" file, labeled as such,** **put a copy of your C++ source code and execution output screen snapshots.**

**3) Include a screenshot showing that you've stored your C++ source code in a GitHub repository.**

**4) Put all your files into a single** **.zip file, and submit ONLY that .zip file for grading.**