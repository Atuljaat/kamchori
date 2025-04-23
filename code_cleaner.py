
def clean_code_for_C(code):
    clean_code = code.replace("```c", "").replace("```", "").replace("\\n", "\n").strip()
    return clean_code

def line_cleaner (code):
    clean_code = code.splitlines()
    clean_code = clean_code[1:-1]
    code = "\n".join(clean_code)
    return code

def split_code_output_blocks(text):
    parts = text.split("```")
    cleaned = [p.strip() for p in parts if p.strip()]
    if len(cleaned) >= 2:
        code = cleaned[0].removeprefix("c").strip()
        output = cleaned[1].strip()
        return code, output
    return 0 , 0