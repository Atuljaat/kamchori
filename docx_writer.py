from docx import Document
from docx.shared import Inches
from pdf_reader import extract_text_from_pdf
from getCode import response , inputtext
from create_codeFile import create_code_file
from code_cleaner import clean_code_for_C , line_cleaner
from run_file import run_code

doc = Document()
doc.add_heading('COLLEGE KI FILE', 0)
doc.add_page_break()

text = extract_text_from_pdf('realtimeTesting.pdf').splitlines()

def write_to_docx(language,filename):
    for index , line in enumerate(text):
        doc.add_heading(line, level=2)
        doc.add_heading('Code : ' , level=3)
        code = (line_cleaner(response(line,language).text)).strip()
        input = (inputtext(line).text).strip()
        print("program ended")
        doc.add_paragraph(code)
        create_code_file(code, index)
        doc.add_page_break()
        doc.save( filename + '.docx')
        run_code(input,index)
