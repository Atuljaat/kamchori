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
import re

# pixels = 800
# dpi = 96
# inches = pixels / dpi
doc = Document()
doc.add_heading('COLLEGE KI FILE', 0)
doc.add_page_break()

# text = extract_text_from_pdf('realtimeTesting.pdf').splitlines()
# text = [line.strip() for line in text if re.match(r'^\d+\.', line.strip())]
text = extract_text_from_pdf('fulltesting.pdf')

# Fix: Better split that avoids splitting 10 into 1 and 0.
questions = re.split(r'(?<!\d)(?=\d{1,2}\.\s)', text)

# Clean each question
questions = [q.strip() for q in questions if q.strip()]
text = questions
print(text)

total_time = time.time()

def write_to_docx (language,filename):
    
    for index , line in enumerate(text):
        start_time = time.time()
        heading = doc.add_heading(line, level=2)
        for run in heading.runs:
             run.font.color.rgb = RGBColor(0, 0, 0)
        heading = doc.add_heading('Code : ' , level=3)
        for run in heading.runs:
             run.font.color.rgb = RGBColor(0, 0, 0)
        
        code = (main_response(line).text)
        # input = (inputtext(line).text).strip()
        code_string , output_string = split_code_output_blocks(code)
        code_para = doc.add_paragraph(code_string)
        code_para.paragraph_format.space_after = 0
        code_para.paragraph_format.line_spacing = 1
        heading = doc.add_heading('Output : ' , level=3)
        for run in heading.runs:
             run.font.color.rgb = RGBColor(0, 0, 0)
        # doc.add_paragraph(output_string)

     #    output_string = "PS C:\\Users\\Atul\\Desktop\\collegeFile> cd \"c:\\Users\\Atul\\Desktop\\collegeFile\\code\" ; if ($?) { gcc " + str(index)+ ".c -o" + str(index) + " } ; if ($?) { .\\" + str(index) + " }"

             output_string = str(output_string)

        image_path = output_to_image(output_string, f"images/output{index}.png")        
        doc.add_picture(image_path)
        create_code_file(code_string, index)
        doc.add_paragraph("")
        doc.save( filename + '.docx')
        endtime = time.time()
        print("Time taken for question " + str(index) + " : " + str(endtime - start_time) + " seconds")
        # run_code(input,index)
        time.sleep(3)

print("Total time taken : " + str(time.time() - total_time) + " seconds")