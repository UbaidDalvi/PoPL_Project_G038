# Performance Analysis of Tiled Image Processing in Halide vs. Python

## Problem Statement

The project aims to compare the performance of image processing implemented in Halide and Python. The focus is on tiled image processing, specifically evaluating the execution time and resource utilization for various operations such as brightness adjustment, grayscale conversion, and blur. The primary goal is to identify the efficiency and computational advantages of Halide compared to a Python implementation.

### POPL Angle

This project aligns with the Principle of Programming Languages (POPL) perspective by exploring the performance implications of using different programming languages for image processing. The POPL angle involves investigating how the choice of programming language influences the execution time, resource utilization, and overall efficiency of the image processing tasks. The key aspects include optimizing code for parallelism, minimizing memory access patterns, and leveraging language-specific features for efficient computation.

## Software Architecture

The software architecture is with distinct implementations in both Halide and Python. The architecture includes the following components:

1. **Halide Implementation:**
   - The Halide implementation consists of three main image processing functions: brightness adjustment, grayscale conversion, and blur.
   - The code utilizes Halide's tile and parallelization features to optimize performance.
   - Tiled processing is employed to break down the image into smaller chunks, enabling parallel execution and efficient memory access patterns.

2. **Python Implementation:**
   - The Python implementation mirrors the functionality of the Halide code, providing brightness adjustment, grayscale conversion, and blur operations.
   - Tiled processing is achieved through nested loops, processing image chunks in a similar manner to Halide.

3. **Testing Component:**
   - Testing is conducted using the `perf stat` tool for both Halide and Python implementations.
   - The tool measures various performance metrics, including execution time and resource utilization.

4. **Dataset:**
   - The image dataset used for testing is available in the `tests` folder.

5. **Results:**
   - The results include performance metrics obtained from `perf stat` for both Halide and Python implementations.

## POPL Aspects

The following POPL aspects are considered in the implementation:

1. **Parallelism in Halide:**
   - Lines 44-45, 57-58,78-79 in the Halide code demonstrate parallelism by using `tile` and `parallel` directives. These directives optimize the execution of image processing functions by enabling parallel hardware capabilities.

2. **Memory Optimization in Halide:**
   - The use of tiled processing in Halide (Lines 44-45, 57-58,78-79) enhances memory access patterns, reducing data movement between levels of the memory hierarchy.

3. **Python Code Structure:**
   - The Python implementation adopts nested loops for tiled processing (Lines 27-31). While lacking explicit parallelism directives, the structure reflects an attempt to optimize the code for performance.

4. **Language-Specific Features in Python:**
   - The use of OpenCV in Python (Lines 11,15-16,20,39,45,48,51) showcases using external libraries for Image processing in python.

5. **Experience with Difficulties:**
   - Implementing parallelism in Halide was challenging due to the need for explicit directives and understanding the tile-based optimization.
   - Python lacked explicit parallelism, requiring a different approach to achieve similar results.

## Results

### Tests Conducted

The following tests were conducted using `perf stat`:

1. Brightness adjustment in Halide and Python.
2. Grayscale conversion in Halide and Python.
3. Blur operation in Halide and Python.

### Dataset Used

The image dataset used for testing is available in tests folder

### Benchmarks Run

Benchmarks were run using the `perf stat` tool to measure execution time, cache utilization, and other performance metrics.


### Validation

The validation of results aligns with the initial problem statement. By comparing the performance metrics obtained from Halide and Python implementations, we aim to demonstrate the efficiency and advantages of using Halide for tiled image processing.

## Potential for Future Work

Given more time, the project could explore the following areas:

1. **Further Optimization in Halide:**
   - Explore additional Halide features for optimizing image processing further, such as scheduling strategies and memory management.

2. **Integration of Machine Learning Models:**
   - Extend the project to include the integration of machine learning models for image processing tasks, exploring the impact on performance.

3. **Dynamic Testing and Benchmarking:**
   - Implement dynamic testing and benchmarking strategies to adapt to varying input sizes and complexities.

4. **Exploration of Language Extensions:**
   - Investigate language extensions or features that enhance parallelism in Python, addressing limitations observed in the current implementation.

5. **Comparison with Other Image Processing Libraries:**
   - Extend the comparison to include other image processing libraries in Python, such as NumPy and scikit-image, to provide a comprehensive analysis.

## Conclusion

This project delves into the comparative analysis of Halide and Python for tiled image processing, emphasizing the importance of programming language choices in achieving optimal performance. The results and insights gained contribute to the broader understanding of language-specific optimizations in image processing applications.

