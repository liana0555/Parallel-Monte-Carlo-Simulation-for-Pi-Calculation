# Parallel-Monte-Carlo-Simulation-for-Pi-Calculation

Our team: 
Yáred Iessé Bustillo Medina - 57963128
Liana Mikhailova - 43583189
Josué David Pavón - 93116997


Objective: Implement a Monte Carlo simulation to estimate the value of Pi using OpenMP.

Description: Monte Carlo simulations use random sampling to estimate mathematical results. The goal is to estimate Pi by randomly generating points in a unit square and counting how many falls within a quarter circle.

Steps:
1.	Implement the Monte Carlo simulation for Pi calculation in serial.
2.	Use OpenMP to parallelize the generation and counting of random points.
3.	Ensure thread safety when updating shared variables.
4.	Run the simulation with different numbers of points and threads to analyse the performance.
5.	Compare the accuracy and performance of the parallel implementation with the serial one.

Key Learning Outcomes:

•	Random number generation and statistical estimation.

•	Managing shared variables and thread safety.

•	Performance tuning for parallel simulations.


                                                    Project Explanation 

Objective:

This project aims to implement the Monte Carlo method for Pi value estimation in both serialised and parallelised forms. The project seeks to increase efficiency by spreading the computation across several threads using OpenMP for parallelisation, enabling quicker and more efficient calculation completion.

A Review of the Monte Carlo Method 

- Concept: A statistical method called the Monte Carlo method makes use of random sampling to address deterministic problems. In this project, points are generated at random within a unit square, and the number of points that fall inside the quarter circle engraved in the square is used to estimate the value of Pi.

- Method:
1. Random sampling: Create arbitrary locations inside the unit square.
2. Point Verification: Verify that every point is contained within the quarter circle, that is, if x^2 + y^2 ≤ 1.
3. Calculating Ratios: Determine the ratio between the total number of points and the points inside the quarter circle.
4. Pi estimation: Since the quarter circle is one-fourth of the whole circle, multiply the ratio by four to get an estimate of Pi.

Project Elements:

1. Version in Serial Form:
- Goal: To use a single thread to carry out the Monte Carlo approach.

- Method:
1. Provide a unit square with a predetermined number of randomly generated points.
2. Ascertain the number of points that are contained within a quarter circle.
3. Utilising the ratio of points inside the circle to total points, get the value of Pi.

2. Parallelised Form:
- Goal: To improve the Monte Carlo technique by parallelising the computation with OpenMP.

- Procedure:
1. To create random points inside a unit square, use multiple threads.
2. The number of points on each thread that fall inside a quarter circle is determined independently.
3. To estimate Pi, add together all of the threads' results.
4. By seeding the random number generator differently for every thread, you can guarantee a diversity of random values.
5. To control parallel execution and lessen synchronisation problems, use OpenMP directives.


                                                Detailed Implementation


                                                 Main class Explanation

- The Monte Carlo approach is used in the provided C++ implementation to determine the value of Pi.

1. 'Main' Role: 
- The goal is to configure the simulation's parameters, start the Pi computation, and show the outcome.

- Actions:
1. Define Number of Points: The number of random points to be generated for the simulation is specified by the numPoints variable.
2. Seed the Random Number Generator: To guarantee that the simulation yields distinct outcomes on each run, the current time is used
  to seed the random number generator.
3. Call up the function calculatePi: To find the value of Pi, call the calculatePi function and pass in numPoints as an argument.
4. Print the Outcome: Gives the console the estimated value of Pi.

2. The 'calculatePi' function
- The goal is to use the Monte Carlo method to estimate the value of Pi.

- Actions:
1. Create Random Points: Within a unit square, which has a side length of one, random points are created.
2. Determine the Circle's Inside Points: Every point is examined to determine whether it is inside a quarter circle with a radius of 1.
3. Calculate Pi: The ratio of the total number of points to the number of points inside the quarter circle is used to calculate Pi. To
estimate Pi, we double this ratio by 4 because we are utilising a quarter circle.


                                              Parallel Version Class Explanation 

This C++ application uses the Monte Carlo method to calculate the value of Pi. It uses OpenMP for parallel processing, which allows for the efficient use of multiple CPU cores. 
 
1. 'Main' Function: This C++ application sets up the simulation parameters, initiates the parallel Pi calculation, and displays the result. 

- Steps:
1. Define Number of Points: The variable numPoints specifies the number of random points to generate for the simulation.
2. Seed the Random Number Generator: The random number generator is seeded differently for each thread to ensure diverse random values.
3. Invoke the calculatePi Function: Calls the calculatePi function with numPoints as an argument to estimate the value of Pi using
parallel threads.
4. Print the Result: Outputs the estimated value.

2. 'calculatePi' function
- The goal is to use parallel processing and the Monte Carlo method to estimate the value of Pi.

- Actions:
1. Parallel Execution: The function parallelises the generation of random points and their check to see if they fall inside the quarter
circle by using OpenMP.
2. Create Random Points: Every thread creates a random point inside a unit square.
3. Find the Points Inside the Circle: Every thread looks to see whether any of its points fall inside a quarter circle.
4. Compile Findings: All threads contribute to the total number of points inside the circle by means of the '#pragma omp for
reduction(+:insideCircle)' directive.
5. Calculate Pi: Pi is calculated by multiplying the total number of points by the ratio of points inside the quarter circle, and then
multiplying the result by 4.


               Parallel_Version_Performance_Measurement to Parallel_Version

- The purpose of the code is a Monte Carlo method to estimate the value of the number 𝜋.
* Using parallel computing, to speed up the process of generating + checking the number of random points.
  • The code utilises the parallel computing capabilities of OpenMP.
By splitting the task into multiple threads, we want to reduce the execution time of the programme.
• The Monte Carlo method applied here is our tool for numerical modelling.


                        Parallel_Version_Threads_Configuration

- The purpose of this code is to demonstrate the use of the Monte Carlo method to estimate the value of the number 𝜋.
• Parallel region: Inside #pragma omp parallel, a parallel region is created where each thread executes a different copy of the code.
 Within this territory/region, random numbers are generated for each thread.
• Parallel loop: The #pragma omp for reduction(+:insideCircle)
directive distributes loop data between threads and sums the values of the insideCircle variable from all threads.

• The value of π is estimated based on the ratio of points that fell inside the quarter circle to the total number of points generated.
 The result is multiplied by 4 because we are working with a quarter circle.
- So this code demonstrates the use of OpenMP to perform calculations in parallel while reducing the program execution time too.
  We also specify the number of threads using omp_set_num_threads, which allows us to control parallel execution.
