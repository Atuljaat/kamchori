
def clean_code_for_C(code):
    clean_code = code.replace("```c", "").replace("```", "").replace("\\n", "\n").strip()
    return clean_code

def line_cleaner (code):
    clean_code = code.splitlines()
    clean_code = clean_code[1:-1]
    code = "\n".join(clean_code)
    return code

def split_algo_code_output(text):
    sections = text.split("```")
    cleaned = [s.strip() for s in sections if s.strip()]
    
    algorithm = ""
    code = ""
    output = ""

    if cleaned:
        if cleaned[0].lower().startswith("algorithm:"):
            algorithm = cleaned[0][len("algorithm:"):].strip()
        else:
            algorithm = cleaned[0]

    if len(cleaned) >= 2:
        code = cleaned[1]
        if code.startswith("c"):
            code = code[1:].strip()

    if len(cleaned) >= 3:
        output = cleaned[2]

    return algorithm, code, output


name = "Prerit || BCA-2A"

def clean_output_for_C(output):
    if (output[0].strip() == "text"):
        output.pop(0)
    if (output[0].strip() != name):
        output.insert(0, name)
    return output