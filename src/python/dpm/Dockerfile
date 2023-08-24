# Base image
FROM python:3.8-slim

# Set working directory in container
WORKDIR /app

# Copy the entire dpm module directory
COPY . .

# Install required packages
RUN apt-get update \
    && apt-get install -y \
    libglib2.0-0 \
    libgl1-mesa-glx \
    libsm6 \
    libxext6 \
    libxrender-dev \
    && rm -rf /var/lib/apt/lists/* \
    && pip install --no-cache-dir opencv-python

# Specify the command to run on container start
CMD [ "python", "src/python/dpm/dpm_main.py" ]
