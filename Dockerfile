# Use a base image with the necessary tools and libraries
FROM ubuntu:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the source code files into the container
COPY include include
COPY src src
COPY Makefile .

# Install necessary packages and dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    libgmp-dev

# Compile the project
RUN make squares_counter

# Command to run when the container starts
CMD ["bin/squares_counter"]

