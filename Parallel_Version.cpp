#include <iostream> // for std::cout
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <omp.h>    // for OpenMP functions

// Function to calculate Pi using the Monte Carlo method with OpenMP
double calculatePi(int numPoints) {
    int insideCircle = 0; // Counter for points inside the quarter circle

    #pragma omp parallel // Start parallel region
    {
        unsigned int seed = static_cast<unsigned int>(time(NULL)) ^ omp_get_thread_num(); // Unique seed for each thread
        #pragma omp for reduction(+:insideCircle) // Parallel for loop with reduction
        for (int i = 0; i < numPoints; ++i) {
            double x = static_cast<double>(rand()) / RAND_MAX; // Random x coordinate
            double y = static_cast<double>(rand()) / RAND_MAX; // Random y coordinate
            if (x * x + y * y <= 1.0) { // Check if the point is inside the quarter circle
                ++insideCircle;
            }
        }
    }

    // Estimate Pi based on the ratio of points inside the quarter circle
    return 4.0 * insideCircle / numPoints;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    int numPoints = 1000000; // Number of points to generate
    double pi = calculatePi(numPoints); // Calculate Pi
    std::cout << "Estimated Pi (Parallel): " << pi << std::endl; // Print the result
    return 0;
}
