#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <opencv2/opencv.hpp>

// Calculates the sum-of-squared-difference between two images.
float SSD(const cv::Mat &src, const cv::Mat &dst);

// Reads image files from a directory and stores their paths in a vector.
int readFiles(const std::string& dirname, std::vector<std::string>& files);

// Saves the target image and top N matched images based on SSD scores to a specified results directory.
void saveMatchedImages(const cv::Mat &targetImage, const std::vector<std::pair<std::string, float>> &ssdScores, const std::string &resultsDirectory, int topN, int taskNumber);

// Processes images in a pipeline, applying various analysis and comparison tasks.
int pipeline(const std::string &src_dir, const std::vector<std::string> &files, std::vector<std::pair<std::string, float>> &scores, int topN, int taskNumber, const std::string& embeddingsFilePath);

// Generates a color histogram for an image.
cv::Mat generateHistogram(const cv::Mat& src, int histsize = 16);

// Calculates the histogram intersection between two histograms.
float histogramIntersection(const cv::Mat& histA, const cv::Mat& histB);

// Generates a 3D RGB histogram for an image.
cv::Mat generateRGBHistogram(const cv::Mat& src, int bins = 8);

// Calculates the histogram intersection for 3D histograms.
float histogramIntersection3D(const cv::Mat& histA, const cv::Mat& histB);

// Generates a histogram for a centered region of the image.
cv::Mat generateCenteredRegionHistogram(const cv::Mat& src, int bins, float regionFraction);

// Generates a histogram for the top percentage of an image.
cv::Mat generateHistogramTop(const cv::Mat& src, int bins, double top_percentage);

// Generates a histogram for the bottom percentage of an image.
cv::Mat generateHistogramBot(const cv::Mat& src, int bins, double bot_percentage);

// Applies a Sobel filter in the x-direction to detect horizontal edges.
int sobelX3x3(cv::Mat &src, cv::Mat &dst);

// Applies a Sobel filter in the y-direction to detect vertical edges.
int sobelY3x3(cv::Mat &src, cv::Mat &dst);

// Calculates the magnitude of gradients from Sobel filters.
int magnitude(cv::Mat &sx, cv::Mat &sy, cv::Mat &dst);

// Calculates a histogram based on the magnitude of gradients.
cv::Mat calculateMagnitudeHistogram(cv::Mat& src, int bins);

// Computes Fourier transform features of an image.
cv::Mat computeFourierFeatures(const cv::Mat& src, const cv::Size& featureSize);

// Calculates a co-occurrence matrix for texture analysis.
cv::Mat calculateCoOccurrenceMatrix(const cv::Mat& gray, int dx, int dy);

// Normalizes a co-occurrence matrix.
cv::Mat normalizeCoOccurrenceMatrix(const cv::Mat& coMat);

// Calculates texture features from a co-occurrence matrix.
void calculateTextureFeatures(const cv::Mat& coMat, float& energy, float& entropy, float& contrast, float& homogeneity);

// Creates a set of Laws' texture energy filters.
std::vector<cv::Mat> createLawsFilters();

// Applies Laws' filters to an image and calculates the energy map.
std::vector<cv::Mat> applyLawsFiltersAndGetEnergy(const cv::Mat& src, const std::vector<cv::Mat>& filters);

// Creates histograms from energy maps.
std::vector<cv::Mat> createEnergyHistograms(const std::vector<cv::Mat>& energies, int bins);

// Reads embeddings from a file and stores them in a map.
void readEmbeddings(const std::string& filePath, std::unordered_map<std::string, std::vector<float>>& embeddings);

// Calculates the cosine distance between two vectors.
float cosineDistance(const std::vector<float>& v1, const std::vector<float>& v2);

// Extracts the filename from a filepath.
std::string extractFilename(const std::string& filepath);

// Computes a histogram from Gabor filter responses.
cv::Mat computeGaborHistogram(const cv::Mat& image, int bins);

// Extracts Histogram of Oriented Gradients (HOG) features from an image.
std::vector<float> extractHOGFeatures(const cv::Mat& image);

// Matches HOG features between two sets of descriptors.
float matchHOGFeatures(const std::vector<float>& descriptors1, const std::vector<float>& descriptors2);

//Calculating gradient Magnitude
cv::Mat calculateGradientMagnitude(const cv::Mat& src);

#endif // FUNCTIONS_H
