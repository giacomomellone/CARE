import cv2
import os

def acquire_images(folder_path):
    images = {}
    for filename in os.listdir(folder_path):
        if filename.endswith('.png'):
            image_path = os.path.join(folder_path, filename)
            image = cv2.imread(image_path)
            images[filename] = image
    return images
