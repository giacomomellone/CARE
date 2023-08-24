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

## Docker Deployment

Running the DPM inside a Docker container allows for a consistent and isolated environment, ensuring that all dependencies are appropriately managed.

### Building the Docker Image

Before running the DPM inside a container, you must first build the Docker image.

1. Navigate back to the root of the `CARE` project:

2. Run the command:

   ```bash
   docker build -t dpm_image -f src/python/dpm/Dockerfile .
   ```

   This command builds a Docker image and names it `dpm_image`.

### Running the DPM using Docker

After building the image, you can run the DPM inside a Docker container using the following instructions:

1. Navigate back to the root of the `CARE` project:

2. Run the DPM inside a Docker container with the following command:

   ```bash
   docker run --name dpm_container -v $(pwd)/data:/app/data dpm_image
   ```

This command runs a container named `dpm_container`, maps the local `data` directory (from the `CARE` root) to the `/app/data` directory inside the container, and uses the `dpm_image` image to run the container.

## Dependencies

- [OpenCV](https://opencv.org/) - For image processing functionalities.
- (Any other dependencies if applicable)

## License

Please refer to the attached LICENSE file.
