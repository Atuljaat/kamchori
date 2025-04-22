import os
def create_code_file(code,filename):
    os.makedirs("code", exist_ok=True)
    file_path = os.path.join("code",str(filename) + ".c")
    with open(file_path, "w") as file:
        file.write(code)

