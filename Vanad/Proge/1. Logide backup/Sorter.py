import os
import shutil
from datetime import datetime

def sort_files_by_date(folder_path):
    # Get a list of all text files in the folder
    files = [f for f in os.listdir(folder_path) if f.endswith('.txt')]

    for file_name in files:
        # Extract the date from the file name (assuming the date is in the format YYYY-MM-DD)
        date_str = file_name.split('_')[0]  # Extract the date part
        file_date = datetime.strptime(date_str, '%Y-%m-%d').date()

        # Create a folder for the date if it doesn't exist
        date_folder_path = os.path.join(folder_path, str(file_date))
        if not os.path.exists(date_folder_path):
            os.makedirs(date_folder_path)

        # Move the file to the corresponding folder
        file_path = os.path.join(folder_path, file_name)
        new_file_path = os.path.join(date_folder_path, file_name)
        shutil.move(file_path, new_file_path)

if __name__ == "__main__":
    # Set the path to the local folder
    local_folder_path = '.'  # You can change this to the desired folder path

    # Call the function to sort files by date
    sort_files_by_date(local_folder_path)
