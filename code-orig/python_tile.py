# /*
# perf stat python3 tile.py
# */

import cv2
import numpy as np

def bright(input_image):
    brightness_factor = 1.5 
    brightened_image = cv2.convertScaleAbs(input_image, alpha=brightness_factor)
    return brightened_image

def gray(input_image):
    output_image = cv2.cvtColor(input_image, cv2.COLOR_BGR2GRAY)
    output_image = cv2.cvtColor(output_image, cv2.COLOR_GRAY2BGR)
    return output_image

def blur(input_image):
    output_image = cv2.GaussianBlur(input_image, (5, 5), 0)
    return output_image

def tile_process(image, func, tile_size):
    height, width, _ = image.shape
    result = np.zeros_like(image)

    for y in range(0, height, tile_size):
        for x in range(0, width, tile_size):
            tile = image[y:y+tile_size, x:x+tile_size, :]
            processed_tile = func(tile)
            result[y:y+tile_size, x:x+tile_size, :] = processed_tile

    return result

if __name__ == "__main__":
    input_image_path = "/home/dalviubaid02/Downloads/Practice_Halide/Mona_Lisa.jpg"
    tile_size = 64  

    input_image = cv2.imread(input_image_path)

    user_input = input("Enter a processing choice ('bright', 'gray', 'blur'): ")

    if user_input == "bright":
        result = tile_process(input_image, bright, tile_size)
        cv2.imwrite("Mona_Lisa_bright_OpenCV_tiled.png", result)
    elif user_input == "gray":
        result = tile_process(input_image, gray, tile_size)
        cv2.imwrite("Mona_Lisa_gray_OpenCV_tiled.png", result)
    elif user_input == "blur":
        result = tile_process(input_image, blur, tile_size)
        cv2.imwrite("Mona_Lisa_blur_OpenCV_tiled.jpg", result)
    else:
        print("Invalid processing choice.")
