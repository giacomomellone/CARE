# Architecture Design Document (ADD) for CARE Project

## 1. Introduction

### 1.1 Purpose

This document defines the architecture design for the Coastal Area Risk Evaluation (CARE) system. It serves as a guideline for the development and implementation of the system, describing the key components, their interactions, data flow, security measures, and overall structure. UML diagrams are used to visually represent various aspects of the system.

### 1.2 Scope

The scope of this document covers the design and architectural considerations for the CARE system. It includes detailed descriptions of the system's components and modules, interactions, data design, security policies, and user interfaces. Specific sections are dedicated to presenting visual representations using UML diagrams such as components_interaction, data_pipeline, database, security.

### 1.3 Definitions, Acronyms, and Abbreviations

- **CARE**: Coastal Area Risk Evaluation
- **DCM**: Data Collection Module
- **DPM**: Data Preprocessing Module
- **ECSS**: European Cooperation for Space Standardization
- **EPAM**: Erosion Pattern Analysis Module
- **GCS**: Ground Control Station
- **S3**: Sentinel-3
- **SSH**: Sea Surface Height
- **UI**: User Interface
- **VRM**: Visualization & Reporting Module

## 2. System Overview

### 2.1 System Context

The CARE system is designed to monitor and analyze coastal erosion patterns using SSH data from Sentinel-3 satellites. It retrieves, preprocesses, and analyzes the data, providing real-time monitoring, risk analysis, alerts, and visualizations. The system is structured into several key modules, each responsible for specific functions. Diagrams are provided to depict the overall architecture, data pipeline, database structure, and security measures.

### 2.2 Constraints

The design and development of the CARE system are guided by the following constraints:

- **Regulatory Compliance**: Compliance with ECSS standards and relevant environmental and data privacy regulations.
- **Data Availability**: Dependency on regular and reliable access to Sentinel-3 data and supplemental coastal information.
- **Performance Requirements**: Design to meet specific performance criteria as outlined in the System Requirements Document, including latency, resolution, availability, and security.

## 3. System Architecture

### 3.1 High-Level Architecture

The CARE system's architecture is designed to efficiently process and analyze coastal erosion patterns using SSH data. The architecture is modular, enabling flexibility, maintainability, and scalability. Below are the key layers and components of the system:

- **User Interface (UI)**: Provides the interface for user interaction, allowing access to visualizations, reports, and system settings.
- **Visualization & Reporting Module (VRM)**: Generates visualizations, maps, and reports based on analysis results.
- **Data Processing Layer**: Includes:
  - **Data Collection Module (DCM)**: Responsible for collecting raw images and data from sources like Sentinel-3 satellites.
  - **Data Preprocessing Module (DPM)**: Processes raw data, including image enhancement, edge detection, and region identification.
  - **Erosion Pattern Analysis Module (EPAM)**: Analyzes preprocessed data to detect erosion patterns and assess risks.
- **Alerting Module (AM)**: Issues timely alerts for high-risk areas.
- **Database Layer**: Consists of Raw Image, Processed Data, Erosion Pattern, Alert, and User entities, managing data storage, retrieval, and archiving.
- **Security Layer**: Implements measures such as authentication, encryption, and access control.

### 3.2 Modules Description

#### 3.2.1 User Interface (UI)

The UI enables users to interact with the CARE system. It provides functionalities like viewing visualizations, setting preferences, and receiving alerts.

#### 3.2.2 Visualization & Reporting Module (VRM)

VRM generates visualizations and reports based on processed data and analysis. It integrates with the UI to present these insights to the user.

#### 3.2.3 Data Collection Module (DCM)

DCM collects raw images and data from various sources like Sentinel-3 satellites. It interfaces with ground control stations and other data providers.

#### 3.2.4 Data Preprocessing Module (DPM)

DPM preprocesses the collected data through image enhancement, edge detection, and region identification. It ensures the data quality for subsequent analysis.

#### 3.2.5 Erosion Pattern Analysis Module (EPAM)

EPAM analyzes preprocessed data to identify erosion patterns, evaluate risks, and generate analysis results. It integrates with AM and VRM for alerting and visualization.

#### 3.2.6 Alerting Module (AM)

AM issues alerts for detected high-risk areas. It works closely with EPAM and UI to deliver timely notifications to relevant stakeholders.

### 3.3 Components Interaction

The interaction between different components is depicted in the `Components Interaction Design - Sequence Diagram`. This diagram showcases the data flow and collaboration between various modules and components of the CARE system.
![Components Interaction Design](./images/components_interaction.png)

### 3.4 Data Pipeline Design

The `data_pipeline` UML diagram illustrates the flow of data within the system, including collection, preprocessing, analysis, and presentation stages.

### 3.5 Database Design

The `database` UML diagram outlines the database structure, including tables and relationships between Raw Image, Processed Data, Erosion Pattern, Alert, and User entities.

### 3.6 Security Design

The `security` UML diagram highlights the security measures implemented across the system, ensuring confidentiality, integrity, and availability of data and services.

---

This section details the architecture of the CARE system and provides insight into how different modules and components interact. The UML diagrams referenced here can be embedded in the document or appended as separate files to visualize the architecture and enhance understanding. Feel free to request any specific details or adjustments!