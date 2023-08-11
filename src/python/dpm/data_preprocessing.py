import cv2
import numpy as np
import os

class ImagePreprocessor:
    def __init__(self, save_intermediate=False, 
                 intermediate_folder='intermediate', 
                 gaussian_kernel_size=(5, 5), 
                 canny_threshold1=100,
                 canny_threshold2=200,
                 segmentation_threshold1=127,
                 segmentation_threshold2=255):
        self.save_intermediate = save_intermediate
        self.intermediate_folder = intermediate_folder
        self.gaussian_kernel_size = gaussian_kernel_size
        self.canny_threshold1 = canny_threshold1
        self.canny_threshold2 = canny_threshold2
        self.segmentation_threshold1 = segmentation_threshold1
        self.segmentation_threshold2 = segmentation_threshold2
        if self.save_intermediate and not os.path.exists(self.intermediate_folder):
            os.makedirs(self.intermediate_folder)

    def to_grayscale(self, image):
        result = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        return result

    def reduce_noise(self, image):
        result = cv2.GaussianBlur(image, self.gaussian_kernel_size, 0)
        return result

    def enhance_contrast(self, image):
        result = cv2.equalizeHist(image)
        return result
    
    def high_pass(self, image):
        # Apply a High Pass Filter
        kernel = np.array([[-1, -1, -1], [-1, 8, -1], [-1, -1, -1]])
        result = cv2.filter2D(image, -1, kernel)
        return result

    # def segment_image(self, image):
    #     ret, result = cv2.threshold(image, self.segmentation_threshold1, self.segmentation_threshold2, cv2.THRESH_BINARY)
    #     return result

    def convert_to_hsv(self, image):
        # Convert to a color space where fog and clouds have distinct characteristics
        result = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

        return result
    
    def segment_image(self, image):
        # Define hue, saturation, and value ranges that correspond to fog/clouds
        # These values might need to be adjusted based on the specific characteristics of the images
        hue_min = 60
        hue_max = 180
        saturation_min = 15
        saturation_max = 180
        value_min = 40
        value_max = 200

        # Create lower and upper bounds using the defined variables
        lower_bound = np.array([hue_min, saturation_min, value_min])
        upper_bound = np.array([hue_max, saturation_max, value_max])

        # Create a mask based on color range
        mask = cv2.inRange(image, lower_bound, upper_bound)

        # Invert the mask if necessary
        result = cv2.bitwise_not(mask)

        return result

    
    def detect_edges(self, image):
        result = cv2.Canny(image, self.canny_threshold1, self.canny_threshold2)
        return result

    def extract_features(self, image):
        # Using SIFT to extract keypoints and descriptors
        sift = cv2.SIFT_create()
        keypoints, descriptors = sift.detectAndCompute(image, None)
        return keypoints, descriptors
    
    def save_image(self, image, filename, process):
        cv2.imwrite(f'{self.intermediate_folder}/{process}_{filename}.png', image)

    def process_image(self, image, filename=None):
        # Converting original image to HSV
        hsv_image = self.convert_to_hsv(image)
        
        # Segmenting image to remove fog/clouds using the converted HSV image
        segmented_image = self.segment_image(hsv_image)
        
        # Reducing noise in the segmented image
        noise_reduced_image = self.reduce_noise(segmented_image) # Applied to segmented image
        
        # Enhancing contrast
        contrast_enhanced_image = self.enhance_contrast(noise_reduced_image)
        
        # Detecting edges
        edge_detected_image = self.detect_edges(contrast_enhanced_image)

        # Optional saving of intermediate images
        if self.save_intermediate and filename:
            self.save_image(hsv_image, filename, '1_hsv')
            self.save_image(segmented_image, filename, '2_segmented')
            self.save_image(noise_reduced_image, filename, '3_noise_reduced')
            self.save_image(contrast_enhanced_image, filename, '4_contrast_enhanced')
            self.save_image(edge_detected_image, filename, '5_edge_detected')

        return edge_detected_image

