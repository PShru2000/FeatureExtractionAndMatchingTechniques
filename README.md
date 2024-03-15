# Multi-Feature Image Matching and Pattern Recognition Pipeline - Using Classic Features and Deep Network Embeddings

## Introduction

The core objective of this project is to find images within a given database that bear similarity to a specified target image. By employing both traditional image features and deep network embeddings, the project aims to identify matches based on color, texture, spatial layout, and high-level features derived from a ResNet18 network. This approach not only solidifies the understanding of image manipulation at a pixel level but also introduces the complex domain of pattern recognition through both classic and contemporary methodologies.

## Setup

A large database of diverse images serves as the foundation for this project. These images vary in size, quality, and content, providing a rich dataset for testing and development. A subset of the database is recommended for initial experimentation, focusing on a mix of similar and distinctly different images to refine the matching algorithms. 

Few Test images Used are given in this folder **[outputs](https://github.com/PShru2000/FeatureExtractionAndMatchingTechniques/tree/main/test%20images)**

## Installations:

OpenCV

C++ Compiler (Visual Studio)

Visual Studio Code (IDE)

MinGW

## Tasks Completed

### Baseline Matching
- **Task 1:** Implemented basic image comparison using the Sum of Squared Differences (SSD), focusing on a 7x7 square in the middle of the image as a feature vector for image pic.1016.jpg.
- **Task 2:** Performed histogram comparison using a single normalized color histogram and histogram intersection as the distance metric for image pic.0164.jpg.
- **Task 21:** Advanced histogram analysis with a 3D RGB histogram for the same image, enhancing color distribution comparison accuracy.

### Spatial and Texture Analysis
- **Task 3 & 31:** Combined whole image and centered region histogram matching, including dual histogram analysis for images pic.0164.jpg and pic.1016.jpg, leveraging both color and spatial information.
- **Task 4 & 41:** Integrated color and texture analysis using a whole image color histogram and texture histogram for image pic.0535.jpg, and explored Fourier Transform features for image pic.0628.jpg.
- **Task 42:** Utilized co-occurrence matrix features for image pic.0746.jpg, analyzing texture in depth.

### Deep Network Embeddings and Comparison
- **Task 5 & 51:** Employed deep network embeddings extracted from a ResNet18 network for images pic.0893.jpg and pic.0164.jpg, comparing using cosine distance.
- **Task 6:** Analyzed the differences between classical features and deep learning embeddings to assess their effectiveness in image matching.

### Extensions and Custom Design
- **Task 7:** Explored the use of Gabor filters for specific image features like detecting trash cans.
- **Task 8:** Applied Histogram of Oriented Gradients (HOG) features for structural and content-based image matching for pic.0164.jpg.
- **Task 9:** Investigated feature matching considering spatial variance, focusing on the distribution and orientation of color spaces within images.

## Extensions Implemented

The project extends beyond the foundational tasks, incorporating novel methods and optimizations to enhance the matching accuracy and efficiency:
- Integrated RGB and Hue-Saturated Histograms with advanced distance metrics.
- Divided images into spatial segments for nuanced analysis using dual histograms.
- Extracted and utilized Fourier Transform and co-occurrence matrix features for in-depth texture analysis.
- Implemented deep network embeddings for high-level feature comparison.
- Developed a comprehensive evaluation mechanism, including computation time and similarity scores, for thorough analysis.

## Running the Code

To execute the image matching system, use the following command format in the terminal, specifying the directory path, the number of top matches to return, the task number, and the embeddings file path as needed:

```
<directory path> <top N matches> <task number> <embeddings file path>
```

This command-line interface allows for flexible and efficient experimentation with various feature vectors, matching methodologies, and target images.

## Results

Please refer to the **[outputs](https://github.com/PShru2000/FeatureExtractionAndMatchingTechniques/tree/main/results)** folder for results

## Conclusion

Through the successful completion of these tasks, the project not only achieves its goal of matching images based on classic features and deep network embeddings but also lays a solid foundation for further exploration in the field of computer vision. The implemented system showcases the potential of combining traditional image analysis techniques with modern deep learning approaches, opening avenues for advanced pattern recognition and image classification applications.
