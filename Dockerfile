# Use a base image with the necessary tools and libraries
FROM ubuntu:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the source code files into the container
COPY include include
COPY src src
COPY Makefile .
COPY packages.txt .

# Install necessary packages and dependencies
RUN apt-get update && xargs apt-get install -y < packages.txt

# Compile the project
RUN make squares_counter

# Command to run when the container starts
CMD ["bin/squares_counter"]

