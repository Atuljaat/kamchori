from docx_writer import write_to_docx
import time

total_time = time.time()

print("Welcome to the College ki file program")
# language = input("Enter the language : ")
# filename = input("Enter the filename : ")
# language = "C"
# filename = "meriFile"
filename = "PreritKiFile"
write_to_docx(filename)
print("File created successfully")
print("Total time taken : " + str(time.time() - total_time) + " seconds")