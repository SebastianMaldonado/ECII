import os

folders = ["python", "javascript", "java", "c", "cpp"]
output_file = "final_results.txt"

with open(output_file, "w") as final_file:
    for folder in folders:
        result_file = os.path.join(folder, "result.txt")
        if os.path.exists(result_file):
            with open(result_file, "r") as f:
                final_file.write(f"{folder}:\n")
                final_file.write(f.read())
                final_file.write("\n")
