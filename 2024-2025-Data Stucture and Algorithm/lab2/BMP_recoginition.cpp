#include <iostream>
#include <vector>
#include <cmath> // For round
#include <numeric> // Potentially useful, but not strictly needed here

// Define an enum for neighborhood type for clarity
enum NeighborhoodType {
    FOUR_NEIGHBORHOOD,
    EIGHT_NEIGHBORHOOD
};

// Function to apply neighborhood averaging filter
// inputImage: The original image represented as a 2D vector
// neighborhoodType: Specifies whether to use 4- or 8-neighborhood
// Returns a new image with the averaging filter applied
std::vector<std::vector<int>> applyNeighborhoodAverage(
    const std::vector<std::vector<int>>& inputImage,
    NeighborhoodType neighborhoodType)
{
    if (inputImage.empty() || inputImage[0].empty()) {
        return {}; // Return empty image if input is empty
    }

    int height = inputImage.size();
    int width = inputImage[0].size();

    // Create a new image to store the result
    std::vector<std::vector<int>> outputImage(height, std::vector<int>(width));

    // Define offsets for neighbors based on type
    std::vector<std::pair<int, int>> offsets;

    if (neighborhoodType == FOUR_NEIGHBORHOOD) {
        offsets = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1} // Up, Down, Left, Right
        };
    } else if (neighborhoodType == EIGHT_NEIGHBORHOOD) {
        offsets = {
            {-1, -1}, {-1, 0}, {-1, 1},  // Top-Left, Top, Top-Right
            {0, -1},           {0, 1},   // Left, Right
            {1, -1},  {1, 0},  {1, 1}    // Bottom-Left, Bottom, Bottom-Right
        };
    } else {
        // Handle invalid type (e.g., copy original image or throw error)
        std::cerr << "Invalid neighborhood type!" << std::endl;
        return inputImage; // Or handle as an error
    }

    // Iterate through each pixel in the input image
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            double sum = 0.0;
            int count = 0;

            // Iterate through the defined neighbors' offsets
            for (const auto& offset : offsets) {
                int neighbor_i = i + offset.first;
                int neighbor_j = j + offset.second;

                // Check if the neighbor is within the image boundaries
                if (neighbor_i >= 0 && neighbor_i < height && neighbor_j >= 0 && neighbor_j < width) {
                    sum += inputImage[neighbor_i][neighbor_j];
                    count++;
                }
            }

            // Calculate the average
            // If no valid neighbors (e.g., for a 1x1 image or invalid type logic),
            // the count would be 0. We'll assign 0 or original value in that case.
            double average = (count > 0) ? (sum / count) : 0.0;
            // A common alternative for count=0 edge case is to assign the original pixel value:
            // double average = (count > 0) ? (sum / count) : inputImage[i][j];


            // Assign the rounded average to the corresponding pixel in the output image
            outputImage[i][j] = static_cast<int>(round(average));

            // Ensure pixel values stay within a typical range if needed (e.g., 0-255)
            // outputImage[i][j] = std::max(0, std::min(255, outputImage[i][j]));
        }
    }

    return outputImage;
}

// Helper function to print an image (for demonstration)
void printImage(const std::vector<std::vector<int>>& image) {
    if (image.empty()) {
        std::cout << "Empty image." << std::endl;
        return;
    }
    for (const auto& row : image) {
        for (int pixel : row) {
            std::cout << pixel << "\t"; // Use tab for spacing
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample grayscale image (or just a 2D matrix of numbers)
    std::vector<std::vector<int>> originalImage = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120},
        {130, 140, 150, 160}
    };

    std::cout << "Original Image:" << std::endl;
    printImage(originalImage);

    // Apply 4-Neighborhood Average
    std::vector<std::vector<int>> image4Avg = applyNeighborhoodAverage(originalImage, FOUR_NEIGHBORHOOD);
    std::cout << "Image after 4-Neighborhood Averaging:" << std::endl;
    printImage(image4Avg);

    // Apply 8-Neighborhood Average
    std::vector<std::vector<int>> image8Avg = applyNeighborhoodAverage(originalImage, EIGHT_NEIGHBORHOOD);
    std::cout << "Image after 8-Neighborhood Averaging:" << std::endl;
    printImage(image8Avg);

    return 0;
}