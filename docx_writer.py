from docx import Document
from docx.shared import Inches
from pdf_reader import extract_text_from_pdf
from getCode import response
from create_codeFile import create_code_file
from code_cleaner import clean_code_for_C

doc = Document()
doc.add_heading('COLLEGE KI FILE', 0)
doc.add_page_break()

text = extract_text_from_pdf('PROGRAMS.pdf').splitlines()

def write_to_docx(language,filename):
    for index , line in enumerate(text):
        doc.add_heading(line, level=2)
        doc.add_heading('Code : ' , level=3)
        code = clean_code_for_C(response(line,language).text)
        doc.add_paragraph(code)
        create_code_file(code, index)
        doc.add_page_break()
    doc.save( filename + '.docx')
