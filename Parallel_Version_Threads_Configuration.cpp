#include <iostream> // for std::cout
#include <random>   // for std::mt19937 and std::uniform_real_distribution
#include <ctime>    // for time()
#include <omp.h>    // for OpenMP functions

// Function to calculate Pi using the Monte Carlo method with OpenMP
double calculatePi(int numPoints) {
    int insideCircle = 0; // Counter for points inside the quarter circle

    #pragma omp parallel // Start parallel region
    {
        // Create a thread-local random number generator
        std::mt19937 generator(static_cast<unsigned int>(time(NULL)) ^ omp_get_thread_num());
        std::uniform_real_distribution<double> distribution(0.0, 1.0);

        #pragma omp for reduction(+:insideCircle) // Parallel for loop with reduction
        for (int i = 0; i < numPoints; ++i) {
            double x = distribution(generator); // Random x coordinate
            double y = distribution(generator); // Random y coordinate
            if (x * x + y * y <= 1.0) { // Check if the point is inside the quarter circle
                ++insideCircle;
            }
        }
    }

    // Estimate Pi based on the ratio of points inside the quarter circle
    return 4.0 * insideCircle / numPoints;
}

int main() {
    int numPoints = 1000000; // Number of points to generate
    omp_set_num_threads(4); // Set the number of threads

    double start = omp_get_wtime(); // Start timing
    double pi = calculatePi(numPoints); // Calculate Pi
    double end = omp_get_wtime(); // End timing

    std::cout << "Estimated Pi (Parallel with 4 threads): " << pi << std::endl; // Print the result
    std::cout << "Time taken: " << end - start << " seconds" << std::endl; // Print the elapsed time

    return 0;
}
