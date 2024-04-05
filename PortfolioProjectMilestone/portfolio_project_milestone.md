## Portfolio Project: Part 1

For your Portfolio Project, you will demonstrate an understanding of the various concepts discussed in each module. For the first part of your Portfolio Project, you will create a C++ application that will exhibit concurrency concepts. Your [application](./Count.cpp) should create two threads that will act as counters. One thread should count up to 20. Once thread one reaches 20, then a second thread should be used to count down to 0. For your created code, provide a detailed analysis of appropriate concepts that could impact your application. Specifically, address:

- Performance issues with concurrency
- Vulnerabilities exhibited with use of strings
- Security of the data types exhibited.

Compile and submit your pseudocode, [source code](./Count.cpp), and screenshots of the application [executing the application](./img/Count.png), the results and your [GIT repository](./img/GitHubRepository7.png) in a [single document](./doc/PortfolioProjectMilestone_Concurrency_in_CPP.pdf).

Reginald Haseltine     

Feb 2, 2024 Local: Feb 2 at 3:23pm
Course: Feb 2 at 1:23pm

Module 7 Introduction

This week you have a Portfolio Milestone assignment where you are to develop a C++ multi-threaded program that with 2 threads counting up and down to 20, and then document the performance, vulnerability, and data security issues of your program.

One approach you could use to have 2 threads execute without interfering with each other to modify a global counter variable is to use a mutex with appropriate lock() and unlock() function calls. A second approach could have the first thread execute the Thread class's join() function before starting the second thread. The first approach is a more realistic demonstration of a multithreaded application though.

**To receive full credit for the packaging requirements for your Critical Thinking and Portfolio assignments you must:**

**1) Put your [C++ source code](./Count.cpp) in .cpp text files. Note that I execute all your programs to check them out.**

**2) In a Word or PDF ["documentation" file](./doc/PortfolioProjectMilestone_Concurrency_in_CPP.pdf), labeled as such, put a copy of your C++ source code and execution output screen snapshots.**

**3) Include a [screenshot](./img/GitHubRepository7.png) showing that you've stored your C++ source code in a GitHub repository.**

**4) Include a [detailed analysis paper](./doc/PortfolioProjectMilestone_Concurrency_in_CPP.pdf) in APA Edition 7 format of the important concepts of concurrency with C++ to cover in detail performance issues, string vulnerabilities, and security of data types.**

**5) Put all your files into a [single .zip file](./zip/PortfolioProjectMilestone.zip), and submit ONLY that .zip file for grading.**