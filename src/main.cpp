/*
  Shruti Pasumarti
  Aswin Chander Aravind Kumar
  Spring 2024
  CS 5330 Computer Vision

  Date: 11th February,2024

  Purpose:Given a target image path based on the task number the main function invokes the functions.h to perfrom
  different tasks thereby reading image files from a directory, performing the specified task,
  and then saving the results in a results directly along with the task number

  Time travel days used : 1 day
*/

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

using namespace cv;
using namespace std;

// Define target image paths for each task
#define TARGET_IMAGE_PATH_TASK_1 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.1016.jpg"
#define TARGET_IMAGE_PATH_TASK_2 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0164.jpg" 
#define TARGET_IMAGE_PATH_TASK_21 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0164.jpg" 
#define TARGET_IMAGE_PATH_TASK_3 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0164.jpg" 
#define TARGET_IMAGE_PATH_TASK_31 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.1016.jpg" 
#define TARGET_IMAGE_PATH_TASK_32 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.1016.jpg" 
#define TARGET_IMAGE_PATH_TASK_4 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0535.jpg"
#define TARGET_IMAGE_PATH_TASK_41 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0628.jpg"
#define TARGET_IMAGE_PATH_TASK_42 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0746.jpg"
#define TARGET_IMAGE_PATH_TASK_5 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0893.jpg"
#define TARGET_IMAGE_PATH_TASK_51 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0164.jpg"
#define TARGET_IMAGE_PATH_TASK_6 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.1072.jpg"
#define TARGET_IMAGE_PATH_TASK_7 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0746.jpg"
#define TARGET_IMAGE_PATH_TASK_8 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0164.jpg"
#define TARGET_IMAGE_PATH_TASK_9 "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/src/olympus/pic.0280.jpg"
#define RESULTS_DIRECTORY "C:/Users/shrut/OneDrive/Desktop/PRCV PROJECT 2/results"

// Tasks Description:

// Task 1: Basic Image Comparison using Sum of Squared Differences (SSD) for image pic.1016.jpg.
//This task evaluates the similarity between the target image and a set of images based on pixel differences.

// Task 2: Basic Histogram Comparison for image pic.0164.jpg using histogram intersection.
//This task compares images based on color distribution to find the best match.

// Task 21: Advanced Histogram Analysis using a 3D RGB histogram for image pic.0164.jpg.
// This task extends Task 2 by employing a more detailed color histogram for comparison.

// Task 3: Combined Whole Image and Centered Region Histogram Matching for image pic.0164.jpg.
// This task uses both global and local histograms to enhance the matching accuracy.

// Task 31: Centered Region and Hue-Saturation Histogram Matching for image pic.1016.jpg.
// This task combines color and spatial information to improve image comparison results.

// Task 32: Dual Histogram Analysis applying one histogram on the top and another at the bottom for image pic.1016.jpg.
// This task segments the image into two regions for a more nuanced comparison.

// Task 4: Texture and Color Analysis using whole image histogram and texture histogram for image pic.0535.jpg.
// This task integrates color and texture features to identify similar images.

// Task 41: Fourier Transform Features Extraction for image pic.0628.jpg by resizing the power spectrum to a 16x16 image.
// This task employs frequency domain analysis to extract distinctive image features.

// Task 42: Co-occurrence Matrix Features Extraction for image pic.0746.jpg, analyzing texture through energy, entropy, contrast, homogeneity, and max probability.
// This task utilizes texture analysis for detailed image comparison.

// Task 5: Deep Network Embeddings Comparison using cosine distance for image pic.0893.jpg.
// This task leverages deep learning embeddings to find similar images based on high-level features.

// Task 51: Similar to Task 5 but for image pic.0164.jpg, focusing on deep network embeddings and their comparison.

// Task 6: Classical Features vs Deep Learning Embeddings

// Task 7: Gabor Filter Used for detecting similar trash cans

// Task 8: Feature Matching using Histogram of Oriented Gradients (HOG) for image pic.0164.jpg.
// This task extracts and compares HOG features to identify images with similar content and structure.

// Task 9 : Feature Matching considering Spatial Variance



int main(int argc, char* argv[]) {
    if (argc < 5 ) {
        cout << "Usage: " << argv[0] << " <directory path> <top N matches> <task number> <embeddings file path>" << endl;
        return -1;
    }


    
    string directoryPath = argv[1];
    int topN = stoi(argv[2]); // Convert the command-line argument to an integer
    int taskNumber = stoi(argv[3]);
    string embeddingsFilePath = argv[4];
    vector<string> imageFiles;
    readFiles(directoryPath, imageFiles);

    // Select the target image based on the task number
    string targetImagePath;
    if (taskNumber == 1) {
        targetImagePath = TARGET_IMAGE_PATH_TASK_1;
    } else if (taskNumber == 2) {
        targetImagePath = TARGET_IMAGE_PATH_TASK_2;
    } else if (taskNumber == 21) {
        targetImagePath = TARGET_IMAGE_PATH_TASK_21;
    }else if (taskNumber == 3){
        targetImagePath = TARGET_IMAGE_PATH_TASK_3;
    } else if (taskNumber == 31){
        targetImagePath = TARGET_IMAGE_PATH_TASK_31;
    }else if (taskNumber == 32){
        targetImagePath = TARGET_IMAGE_PATH_TASK_32;
    }else if (taskNumber == 4){
        targetImagePath = TARGET_IMAGE_PATH_TASK_4;
    }else if (taskNumber == 41){
        targetImagePath = TARGET_IMAGE_PATH_TASK_41;
    }else if (taskNumber == 42){
        targetImagePath = TARGET_IMAGE_PATH_TASK_42;
    }else if (taskNumber == 5){
        targetImagePath = TARGET_IMAGE_PATH_TASK_5;
    }else if (taskNumber == 51){
        targetImagePath = TARGET_IMAGE_PATH_TASK_51;
    }else if (taskNumber == 6){
        targetImagePath = TARGET_IMAGE_PATH_TASK_6;
    }else if (taskNumber == 7){
        targetImagePath = TARGET_IMAGE_PATH_TASK_7;
    }else if (taskNumber == 8){
        targetImagePath = TARGET_IMAGE_PATH_TASK_8;
    }else if (taskNumber == 9){
        targetImagePath = TARGET_IMAGE_PATH_TASK_9;
    }else {
        cerr << "Invalid task number." << endl;
        return -1;
    }

    vector<pair<string, float>> ssdScores;

    //Pipeline function - Takes in different arguments to executes different tasks based on the requirement
    pipeline(targetImagePath, imageFiles, ssdScores, topN, taskNumber,embeddingsFilePath);

    // Display the top N matches
    cout << "Top " << topN << " matches for task " << taskNumber << ":" << endl;
    for (int i = 0; i < topN && i < ssdScores.size(); ++i) {
        cout << ssdScores[i].first << " - Score: " << ssdScores[i].second << endl;
    }

    // Saving the top N matches
    saveMatchedImages(cv::imread(targetImagePath, cv::IMREAD_COLOR), ssdScores, RESULTS_DIRECTORY, topN, taskNumber);

    return 0;
}