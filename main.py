from docx_writer import write_to_docx

print("Welcome to the College ki file program")
# language = input("Enter the language : ")
# filename = input("Enter the filename : ")
language = "C"
# filename = "meriFile"
filename = "meriFile"
write_to_docx(language,filename)
print("File created successfully")