import cv2
import os
from data_acquisition import acquire_images
from data_preprocessing import ImagePreprocessor
from data_storage import store_image

# Hyperparameters
gaussian_kernel_size = (5, 5)
segmentation_threshold1 = 100
segmentation_threshold2 = 200
canny_threshold1 = 100
canny_threshold2 = 200

def main():
    # Folder paths
    input_folder = './data/input'
    intermediate_folder = './data/output/intermediate_preprocessed'
    output_folder = './data/output/preprocessed'

    # Create an instance of ImagePreprocessor
    preprocessor = ImagePreprocessor(save_intermediate=True,
                                     gaussian_kernel_size=gaussian_kernel_size,
                                     canny_threshold1=canny_threshold1,
                                     canny_threshold2=canny_threshold2,
                                     segmentation_threshold1=segmentation_threshold1,
                                     segmentation_threshold2=segmentation_threshold2,
                                     intermediate_folder=intermediate_folder)

    # Acquire images
    images = acquire_images(input_folder)

    # Process and store images
    for filename, image in images.items():
        # Process the image
        processed_image = preprocessor.process_image(image, filename=filename)
        
        # Store the processed image
        store_image(processed_image, filename, output_folder)

        print(f"Processed and stored image: {filename}")

if __name__ == "__main__":
    main()

