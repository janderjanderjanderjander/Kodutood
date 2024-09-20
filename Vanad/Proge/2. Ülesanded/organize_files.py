import os
import shutil
from datetime import datetime

def organize_python_files(directory):
    # Get the list of Python files in the directory
    python_files = [f for f in os.listdir(directory) if f.endswith('.py') and f != 'organize_files.py']

    for file in python_files:
        # Get the last modification time of the file
        file_path = os.path.join(directory, file)
        mod_time = os.path.getmtime(file_path)

        # Convert the modification time to a readable format
        mod_date = datetime.fromtimestamp(mod_time).strftime('%Y-%m-%d')

        # Create a folder with the modification date if it doesn't exist
        folder_path = os.path.join(directory, mod_date)
        os.makedirs(folder_path, exist_ok=True)

        # Move the file to the corresponding folder
        new_file_path = os.path.join(folder_path, file)
        shutil.move(file_path, new_file_path)

if __name__ == "__main__":
    current_directory = os.path.dirname(os.path.abspath(__file__))
    organize_python_files(current_directory)
    print("Files organized successfully.")
