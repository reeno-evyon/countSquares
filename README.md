# How many squares?

## Task Description: 
On an infinite lattice you are given an n x n square, for an arbitrary value of n. How many squares can you see? 
For instance: for n = 1 we can see one square, for n= 2 we can see 5 squares, and so on.

## Solution:
We can gain insight into this classic problem by analyzing small, illustrative examples.

For n=1, Total number of squares = 1 => ( 1<sup>2</sup>)

For n=2, Total number of squares = 5 => ( 1<sup>2</sup>+2<sup>2</sup> )

For n=3, Total number of squares = 14 => ( 1<sup>2</sup>+2<sup>2</sup>+3<sup>2</sup> )

For n=4, Total number of squares = 30 => ( 1<sup>2</sup>+2<sup>2</sup>+3<sup>2</sup>+4<sup>2</sup> )

Based on this, we can generalize that... **Total number of squares = ( 1<sup>2</sup>+2<sup>2</sup>+3<sup>2</sup>+...+n<sup>2</sup> )**

## Mathematical approach:
Imagine summing the squares of all numbers from **1** to **n** – not easy, right? 

But thanks to amazing mathematicians, we have a formula for that!

The sum of squares of first ***n*** natural numbers = ***[n(n+1)(2n+1)] / 6***

## Interesting facts:
The above formula becomes fascinating when we try to code it. Using standard data types leads to overflow errors for large values of **n**. :confused:

While simply restricting the program's output or throwing exceptions is straightforward, it lacks excitement. Imagine seeing incredibly large numbers as results, even if we can't read them. :nerd_face:

## Avoiding overflow problem:
The [GMP library](https://gmplib.org/) can assists with avoiding overflow issues when evaluating the sum of squares formula. Its precision is practically unlimited, except for limitations imposed by the available memory on the machine it runs on. 

Browse through the source code to know more about how GMP library is used here to avoid the overflow problem.


## Building and running:
This solution is self contained and can be build directly using the make command. 

Steps to follow:
```
gh repo clone reeno-evyon/countSquares
cd countSquares
make all
bin/squares_counter
```

## Dockerized application:
Using github actions, the latest docker image built from `main` will be published to docker hub. You can directly pull the image from reenodocker/rjtest and run it.
```
docker pull reenodocker/rjtest:latest
docker run -it reenodocker/rjtest:latest
```
