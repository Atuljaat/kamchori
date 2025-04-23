from docx import Document
from docx.shared import Inches
from pdf_reader import extract_text_from_pdf
from getCode import response , inputtext , main_response
from create_codeFile import create_code_file
from code_cleaner import clean_code_for_C , line_cleaner , split_code_output_blocks
from run_file import run_code 
import time
from generate_output import output_to_image
from docx.shared import RGBColor
from docx.shared import Inches


# pixels = 800
# dpi = 96
# inches = pixels / dpi
doc = Document()
doc.add_heading('COLLEGE KI FILE', 0)
doc.add_page_break()

text = extract_text_from_pdf('PROGRAMS.pdf').splitlines()


def write_to_docx (language,filename):
    for index , line in enumerate(text):
        heading = doc.add_heading(line, level=2)
        for run in heading.runs:
             run.font.color.rgb = RGBColor(0, 0, 0)
        heading = doc.add_heading('Code : ' , level=3)
        for run in heading.runs:
             run.font.color.rgb = RGBColor(0, 0, 0)
        
        code = (main_response(line).text)
        # input = (inputtext(line).text).strip()
        code_string , output_string = split_code_output_blocks(code)
        print(code_string)
        print("program ended")
        code_para = doc.add_paragraph(code_string)
        code_para.paragraph_format.space_after = 0
        code_para.paragraph_format.line_spacing = 1
        heading = doc.add_heading('Output : ' , level=3)
        for run in heading.runs:
             run.font.color.rgb = RGBColor(0, 0, 0)
        # doc.add_paragraph(output_string)
        image_path = output_to_image(output_string, f"images/output{index}.png")        
        doc.add_picture(image_path)
        create_code_file(code_string, index)
        doc.add_paragraph("")
        doc.save( filename + '.docx')
        # run_code(input,index)
        # time.sleep(1)
