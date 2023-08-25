# Alerting Module (AM)

The Alerting Module (AM) is designed to continuously evaluate and trigger alerts based on specific risk data. It supports different notification channels, such as email, and allows flexibility in defining alert criteria and templates.

## Features

- **Flexible Alert Criteria:** Define multiple alert thresholds and severity levels.
- **Customizable Alert Templates:** Format alert titles and bodies according to your needs.
- **Multiple Notification Channels:** Easily extend to support various notification methods, including email.

## How It Works

1. **Initialization:** Define the alert criteria, templates, and notification channels during initialization.
2. **Fetching Risk Data:** Risk data is continuously fetched from a specified source.
3. **Evaluating Alerts:** The risk data is evaluated against predefined criteria.
4. **Triggering Alerts:** If the criteria are met, alerts are triggered using corresponding templates and sent through the specified channels.

## Building Locally

Make sure you have the required dependencies installed, including a C++17 compatible compiler.

1. Build the project using the provided Makefile:

   ```bash
   make
   ```

2. Run the executable:

   ```bash
   make run
   ```

## Debugging

You can debug the code using the `Run and Debug` option in Visual Studio Code. The `launch.json` is configured and the Debug can be launched via the `AM - Build and Debug` option.

## Docker Deployment

Running the AM inside a Docker container allows for a consistent and isolated environment, ensuring that all dependencies are appropriately managed.

### Building the Docker Image

Before running the AM inside a container, you must first build the Docker image.

1. Navigate back to the root of the `CARE` project:

2. Run the command:

   ```bash
   docker build -t am_image -f src/cpp/am/Dockerfile .
   ```

   This command builds a Docker image and names it `am_image`.

### Running the AM using Docker

After building the image, you can run the AM inside a Docker container using the following instructions:

1. Navigate back to the root of the `CARE` project:

2. Run the AM inside a Docker container with the following command:

   ```bash
   docker run --name am_container am_image
   ```

This command runs a container named `am_container` and uses the `am_image` image to run the container.

## Customizing

### Alert Criteria

Edit or add new criteria within the initialization phase. Example:

```cpp
criteria.push_back(AlertCriteria(75.0, 3)); // threshold, severity
```

### Alert Templates

Edit or add new templates to match your alert criteria. Example:

```cpp
templates.push_back(AlertTemplate("High Alert", "High risk detected", 3)); // title, body, severity
```

### Notification Channels

Extend the `NotificationChannel` class to support other notification methods, such as SMS or push notifications.

## License

Please refer to the attached LICENSE file.
