# CARE - Coastal Analysis & Risk Evaluation System

CARE is a system designed to monitor and analyze coastal erosion patterns using data provided by Sentinel-3. The system processes raw images and other telemetries, applies edge detection and other algorithms to recognize erosion patterns, and offers real-time monitoring and alerting functions.

## Table of Contents

- [CARE - Coastal Analysis \& Risk Evaluation System](#care---coastal-analysis--risk-evaluation-system)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Modules Overview](#modules-overview)
    - [User Interface (UI)](#user-interface-ui)
    - [Visualization \& Reporting Module (VRM)](#visualization--reporting-module-vrm)
    - [Data Collection Module (DCM)](#data-collection-module-dcm)
    - [Data Preprocessing Module (DPM)](#data-preprocessing-module-dpm)
    - [Erosion Pattern Analysis Module (EPAM)](#erosion-pattern-analysis-module-epam)
    - [Alerting Module (AM)](#alerting-module-am)
  - [Design Diagrams](#design-diagrams)
  - [Documentation](#documentation)
  - [Release Pipeline](#release-pipeline)
  - [License](#license)

## Introduction

Coastal erosion is a significant global concern, and timely detection and analysis are crucial for proper mitigation. CARE aims to provide a comprehensive solution to analyze and understand erosion patterns using advanced algorithms and visualization techniques.

## Modules Overview

### User Interface (UI)

- **Status:** _To-Do_ 📝
- **Description:** Enables users to interact with the CARE system. Allows viewing visualizations, setting preferences, and receiving alerts.

### Visualization & Reporting Module (VRM)

- **Status:** _To-Do_ 📝
- **Description:** Generates visualizations and reports based on processed data and analysis. Integrates with the UI to present insights to the user.

### Data Collection Module (DCM)

- **Status:** _To-Do_ 📝
- **Description:** Collects raw images and data from various sources like Sentinel-3 satellites. Interfaces with ground control stations and other data providers.

### Data Preprocessing Module (DPM)

- **Status:** _In Progress_ 🚧
- **Description:** Preprocesses the collected data through image enhancement, edge detection, and region identification. Ensures data quality for subsequent analysis.

|      Input Image       |      HSV Space      |       Segment       |
|:----------------------:|:-------------------:|:-------------------:|
| ![Input](./data/input/S3A_OL_1_ERR____20230810T091025_20230810T095440_20230810T112748_2655_102_093______PS1_O_NR_003_RGB_000.png) | ![HSV](./data/output/intermediate_preprocessed/1_hsv_S3A_OL_1_ERR____20230810T091025_20230810T095440_20230810T112748_2655_102_093______PS1_O_NR_003_RGB_000.png.png) | ![Segmented](./data/output/intermediate_preprocessed/2_segmented_S3A_OL_1_ERR____20230810T091025_20230810T095440_20230810T112748_2655_102_093______PS1_O_NR_003_RGB_000.png.png) |

|   Noise Reduction   |      Contrast      |   Edge Detection    |
|:-------------------:|:------------------:|:-------------------:|
| ![Noise Reduced](./data/output/intermediate_preprocessed/3_noise_reduced_S3A_OL_1_ERR____20230810T091025_20230810T095440_20230810T112748_2655_102_093______PS1_O_NR_003_RGB_000.png.png) | ![Contrast Enhanced](./data/output/intermediate_preprocessed/4_contrast_enhanced_S3A_OL_1_ERR____20230810T091025_20230810T095440_20230810T112748_2655_102_093______PS1_O_NR_003_RGB_000.png.png) | ![Edge Detected](./data/output/intermediate_preprocessed/5_edge_detected_S3A_OL_1_ERR____20230810T091025_20230810T095440_20230810T112748_2655_102_093______PS1_O_NR_003_RGB_000.png.png) |

### Erosion Pattern Analysis Module (EPAM)

- **Status:** _To-Do_ 📝
- **Description:** Analyzes preprocessed data to identify erosion patterns, evaluate risks, and generate analysis results. Integrates with AM and VRM for alerting and visualization.

### Alerting Module (AM)

- **Status:** _To-Do_ 📝
- **Description:** Issues alerts for detected high-risk areas. Works closely with EPAM and UI to deliver timely notifications to relevant stakeholders.

## Design Diagrams

For a detailed understanding of how the modules interact, refer to the [Architecture Design Document (ADD)](./docs/Architecture%20Design%20Document%20(ADD).md).

## Documentation

Detailed documentation for this project can be found in the [docs folder](./docs).

- [Architecture Design Document (ADD)](./docs/Architecture%20Design%20Document%20(ADD).md)
- [System Requirements Document (SRD)](./docs/System%20Requirements%20Document%20(SRD).md)
- [Verification and Validation Plan (VPP)](./docs/Verification%20and%20Validation%20Plan%20(VPP).md)

## Release Pipeline

The release pipeline is configured to automatically create a new release of the CARE project, package documentation as PDFs, and attach them to the release. The pipeline can be manually triggered via GitHub Actions, and it ensures that all important documentation and visualizations are packaged together in a structured format, making it easier for users and contributors to access relevant materials.

To trigger the pipeline manually, navigate to the "Actions" tab on the GitHub repository and select the "Create Release" workflow.

## License

This project is licensed under the terms of the [license](./LICENSE).

All the images have been downloaded from [Copernicus Open Access Hub](https://scihub.copernicus.eu/dhus/#/home)
