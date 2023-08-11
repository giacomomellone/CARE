import cv2
import os

def store_image(image, filename, folder_path):
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)
    output_path = os.path.join(folder_path, filename)
    cv2.imwrite(output_path, image)
