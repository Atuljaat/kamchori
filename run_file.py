import subprocess
import os

def run_code(input_str, index):
    folder = "code"
    source_path = f"{folder}/{index}.c"
    binary_path = f"{folder}/{index}.exe"

    # Step 1: Compile
    compile = subprocess.run(["gcc", source_path, "-o", binary_path], capture_output=True, text=True)
    if compile.returncode != 0:
        print("Compilation Error:")
        print(compile.stderr)
        return

    # Step 2: Run the program with input and let output show in terminal
    print("Program is running...")
    run = subprocess.run(
        [binary_path],
        input=input_str,
        text=True,
        stdout=None,  # Send output to terminal
        stderr=None   # Send errors to terminal
    )

    # Optional: Clean up binary
    os.remove(binary_path)
