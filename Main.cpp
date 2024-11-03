#include <iostream> // for std::cout
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

// Function to calculate Pi using the Monte Carlo method
double calculatePi(int numPoints) {
    int insideCircle = 0; // Counter for points inside the quarter circle

    // Generate points and count how many fall inside the quarter circle
    for (int i = 0; i < numPoints; ++i) {
        double x = static_cast<double>(rand()) / RAND_MAX; // Random x coordinate
        double y = static_cast<double>(rand()) / RAND_MAX; // Random y coordinate
        if (x * x + y * y <= 1.0) { // Check if the point is inside the quarter circle
            ++insideCircle;
        }
    }

    // Estimate Pi based on the ratio of points inside the quarter circle
    return 4.0 * insideCircle / numPoints;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    int numPoints = 1000000; // Number of points to generate
    double pi = calculatePi(numPoints); // Calculate Pi
    std::cout << "Estimated Pi (Serial): " << pi << std::endl; // Print the result
    return 0;
}
