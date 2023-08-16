#!/bin/bash

# Path to plantuml.jar in the main folder
PLANTUML_PATH="./plantuml.jar"
# Directory containing the PlantUML files
UML_DIR="./docs/uml"
# Absolute path where the generated images will be stored (in the docs/images folder)
IMG_DIR_ABSOLUTE_PATH="$(pwd)/docs/images"

# Check if plantuml.jar exists; if not, download it
if [ ! -f $PLANTUML_PATH ]; then
  echo "plantuml.jar not found, downloading..."
  wget "https://sourceforge.net/projects/plantuml/files/plantuml.jar/download" -O $PLANTUML_PATH
  if [ $? -ne 0 ]; then
    echo "Error downloading plantuml.jar. Please try again."
    exit 1
  fi
  echo "Downloaded plantuml.jar successfully."
fi

# Create the images directory if it doesn't exist
mkdir -p $IMG_DIR_ABSOLUTE_PATH

# Iterate through the PlantUML files in the UML directory
for uml_file in $UML_DIR/*.plantuml; do
  # Extract the base name of the file (without extension) to use for the PNG name
  base_name=$(basename $uml_file .plantuml)
  output_file="$IMG_DIR_ABSOLUTE_PATH/$base_name.png"
  # Convert the PlantUML file to PNG and save it in the images directory, using input redirection
  java -jar $PLANTUML_PATH -tpng -pipe > "$output_file" < "$uml_file"
  echo "Generated $output_file"
done

echo "All PNG files have been generated successfully."
