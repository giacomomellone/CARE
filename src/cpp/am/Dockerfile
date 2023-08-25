# Use a base image with a C++17 compatible compiler
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /am

# Copy necessary files to build the project
COPY . /am/

# Build the project using the provided Makefile
RUN make

# Command to run the executable
CMD ["make", "run"]
