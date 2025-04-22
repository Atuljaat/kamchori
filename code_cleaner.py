
def clean_code_for_C(code):
    clean_code = code.replace("```c", "").replace("```", "").replace("\\n", "\n").strip()
    return clean_code
