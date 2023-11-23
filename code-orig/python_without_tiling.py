import cv2
import numpy as np

def bright(input_image_path):
    input_image = cv2.imread(input_image_path)
    brightness_factor = 1.5 
    brightened_image = cv2.convertScaleAbs(input_image, alpha=brightness_factor)
    return brightened_image

def gray(input_image_path):
    input_image = cv2.imread(input_image_path)
    output_image = cv2.cvtColor(input_image, cv2.COLOR_BGR2GRAY)
    return output_image

def blur(input_image_path):
    input_image = cv2.imread(input_image_path)
    output_image = cv2.GaussianBlur(input_image, (5, 5), 0)
    return output_image

if __name__ == "__main__":
    input_image_path = "/home/dalviubaid02/Downloads/Practice_Halide/Mona_Lisa.jpg"
    
    user_input = input("Enter a processing choice ('bright', 'gray', 'blur'): ")

    if user_input == "bright":
        result = bright(input_image_path)
        cv2.imwrite("Mona_Lisa_bright_OpenCV.png", result)
    elif user_input == "gray":
        result = gray(input_image_path)
        cv2.imwrite("Mona_Lisa_gray_OpenCV.png", result)
    elif user_input == "blur":
        result = blur(input_image_path)
        cv2.imwrite("Mona_Lisa_blur_OpenCV.jpg", result)
    else:
        print("Invalid processing choice.")
