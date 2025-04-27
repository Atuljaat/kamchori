import re

def clean_code_for_C(code):
    clean_code = code.replace("```c", "").replace("```", "").replace("\\n", "\n").strip()
    return clean_code

def line_cleaner (code):
    clean_code = code.splitlines()
    clean_code = clean_code[1:-1]
    code = "\n".join(clean_code)
    return code


def split_gemini_response(response):
    algo = ''
    code = ''
    output = ''

    # Step 1: Extract Algorithm part
    algo_match = re.search(r'Algorithm:\s*(.*?)```', response, re.DOTALL)
    if algo_match:
        algo = algo_match.group(1).strip()

    # Step 2: Extract Code block
    code_match = re.search(r'```c(.*?)```', response, re.DOTALL)
    if not code_match:
        code_match = re.search(r'```(.*?)```', response, re.DOTALL)
    
    if code_match:
        code = code_match.group(1).strip()

    # Step 3: Extract Output
    if code_match:
        # Find the position where code block ends
        end_pos = code_match.end()
        remaining_text = response[end_pos:].strip()
        
        # Now check if remaining text has triple backticks again
        output_match = re.search(r'```(.*?)```', remaining_text, re.DOTALL)
        if output_match:
            output = output_match.group(1).strip()
        else:
            # Otherwise take the plain text directly
            output = remaining_text.strip()

    return algo, code, output




name = "Prerit || BCA-2A"

def clean_output_for_C(output):
    if (output[0].strip() == "text"):
        output.pop(0)
    if (output[0].strip() != name):
        output.insert(0, name)
    return output