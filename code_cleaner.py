
def clean_code_for_C(code):
    clean_code = code.replace("```c", "").replace("```", "").replace("\\n", "\n").strip()
    return clean_code

def line_cleaner (code):
    clean_code = code.splitlines()
    clean_code = clean_code[1:-1]
    code = "\n".join(clean_code)
    return code