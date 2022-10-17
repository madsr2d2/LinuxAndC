---
title:  Mandatory Assignment 3
subtitle: 'Linux and C Programming (62558)'
author: Mads Richardt (s224948)
date: \today
documentclass: scrartcl
---

# Introduction
The aim of this assignment is to introduce the student to Make[^1]. Make is a build automation tool that enables automatic compilation of executable programs from source code. This is done by reading so called MakeFiles, which specify how the target program should should be compiled. In this assignment, the student must write a Makefile which automates the build process of an executable program from source code. I addition,  the Makefile and the source code must be uploaded to the student server using SCP.

# Makefiles
A MakeFile is just a standard text file read by the Make program. The main component of MakeFiles are *build rules*. These rules specify the dependencies of a particular file, the *target*, and how the compiler should build this file from these dependencies.
Build rules have the following syntax.

```
target: [dependencies ...]
Tab [command 1]
	   .
	   .
	   .
Tab [command n]
```

```
CC=gcc
CFLAGS


all: main

main: main.c
	gcc -o main main.c

```

[^1]: https://www.gnu.org/software/make/