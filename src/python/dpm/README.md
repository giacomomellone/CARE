# Data Processing Module (DPM)

The Data Processing Module (DPM) is engineered to acquire, process, and store images related to coastal erosion analysis.

## Features

- **Image Acquisition:** Streamlined acquisition of images from designated folders.
- **Image Processing:** Apply Gaussian filters, edge detection, and segmentation techniques on the acquired images.
- **Intermediate and Final Storage:** Capability to save intermediate steps of image processing and the final processed image.

## How It Works

1. **Setup and Initialization:** Hyperparameters related to image processing are defined.
2. **Image Acquisition:** Images are fetched from the specified `input_folder`.
3. **Image Processing:** Acquired images are passed through a series of processing steps, including Gaussian filtering, segmentation, and edge detection.
4. **Storage:** Both intermediate and final processed images are stored in their respective folders.

## Execution

1. Ensure you have all the required dependencies, notably the OpenCV library.
2. To execute the Data Processing Module, simply run the script:

   ```bash
   python dpm_main.py
   ```

## Customizing

### Hyperparameters

You can adjust the hyperparameters at the beginning of the `dpm_main.py` script, such as:

```python
gaussian_kernel_size = (5, 5)
segmentation_threshold1 = 100
segmentation_threshold2 = 200
canny_threshold1 = 100
canny_threshold2 = 200
```

### Processing Steps

If you'd like to add or remove certain image processing techniques, modify the `ImagePreprocessor` class or adjust the processing steps in the `main()` function.

### Data Acquisition and Storage Paths

By default, images are acquired from `./data/input` and processed images are saved in `./data/output/intermediate_preprocessed` and `./data/output/preprocessed`. Modify these paths in the `main()` function as required.

## Dependencies

- [OpenCV](https://opencv.org/) - For image processing functionalities.
- (Any other dependencies if applicable)

## License

Please refer to the attached LICENSE file.
