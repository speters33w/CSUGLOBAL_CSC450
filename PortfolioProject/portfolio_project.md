## Portfolio Project: Part II

### Concurrency Concepts

For your Portfolio Project, you will demonstrate an understanding of the various concepts discussed in each module. For the second part of your Portfolio Project, you will create a Java application that will exhibit concurrency concepts. Your [application](./TwentyTwenty.java) should create two threads that will act as counters. One thread should count up to 20. Once thread one reaches 20, then a second thread should be used to count down to 0. For your created code, please provide a [detailed analysis](./doc/detailed_analysis.pdf) of appropriate concepts that could impact your application. Specifically, please address:

- Performance issues with concurrency
- Vulnerabilities exhibited with use of strings
- Security of the data types exhibited.

Submit the following components to your GIT repository in a single document:

- [Word document](./doc/documentation.pdf) with appropriate screenshots of your program executing, program analysis responses, and source code in the Word file.
- Submit your [.java source code file(s)](./src/). If more than 1 file, submit a zip file.
- Provide a [detailed comparison](./doc/detailed_comparison.pdf) between the performance implementations between the Java and C++ versions of your applications. Which implementation may be considered less vulnerable to security threats and why? Your detailed comparison should be 3-4 pages in length. 

Reginald Haseltine   

Feb 2, 2024 Local: Feb 2 at 3:24pm
Course: Feb 2 at 1:24pm

Module 8 Introduction

Congratulations! You've made it to the final module of the class.

In this final module we are discussing Java exceptions and exception handling, and potential vulnerabilities related to them.

We will cover the ways that exceptions can be handled, what types of exceptions should be handled, which are optional, and which shouldn't be bother with.

We're also discussing when it might be appropriate to use user-defined exceptions vs. built-in exceptions.

For this week's programming assignment you have a final program to create for the Portfolio Project Part II where you'll be creating a multi-threaded Java program and then comparing it to the C++ multi-threaded program from Module 7.

**To receive full credit for the packaging requirements for your Module 8 Portfolio Project assignment you must:**

**1) Put your [Java source code](./src/) in .java text files. Note that I execute all your programs to check them out.**

**2) In a Word or [PDF "documentation" file](./doc/documentation.pdf), labeled as such, put a copy of your Java source code and execution output screen snapshots.**

**3) Include a [screenshot](./img/GitHubRepository8.png) showing that you've stored your Java source code in a GitHub repository.**

**4) Include a [detailed analysis](./doc/detailed_analysis.pdf) paper in APA Edition 7 format of the important concepts of concurrency with Java to cover in detail performance issues, string vulnerabilities, and security of data types.**

**5) Include a separate [3-4 page APA Edition 7 paper](./doc/detailed_comparison.pdf) comparing the performance and security differences between C++ and Java multi-threaded programs.** 

**6) Put all your files into a single** **.zip file, and submit ONLY that .zip file for grading.**

 

**Note that Java thread synchronization isn't covered in detail in the Interactive Lectures but you can achieve this using one of the following approaches:**

**1) Thread class's join() method used properly**

**2) Thread class's start() and lock() methods used properly**

**3) synchronized instance variable, method, or block**

**4) ReentrantLock class**

**5) Semaphore class** 