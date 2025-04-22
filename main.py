from docx_writer import write_to_docx

print("Welcome to the College ki file program")
language = input("Enter the language : ")
filename = input("Enter the filename : ")
write_to_docx(language,filename)
print("File created successfully")