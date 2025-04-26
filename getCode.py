from dotenv import load_dotenv
import os
from google import genai
import time

load_dotenv()
apiKey = os.getenv("GENAI_API_KEY")
client = genai.Client(api_key=apiKey)

apiKey2 = os.getenv("GENAI_API_KEY2")
client2 = genai.Client(api_key=apiKey2)


api_keyss = [apiKey, apiKey2]


# def response (question,language) : 
#     response = client.models.generate_content(
#     model="gemini-2.0-flash", contents=" only show me the full code for : " + question + "in" + language + "do not write comments and beautifully format the code" )
#     return response

# def inputtext (question) :
#     response = client.models.generate_content(
#     model="gemini-2.0-flash", contents="Given the following program, give only the input values as if I were entering them in the terminal, no explanation, no extra text:" + question )
#     return response

name = "Prerit || BCA-2A"

# f"Write a C program {question} Do not include any comments and also add printf(\"{name}\"); as the first line inside main code. After the code, in the same code block, simulate one terminal test run showing input and output as it would appear when running the program. Do not add any extra explanation or formatting outside the code block."
def main_response(question,count):
    client = genai.Client(api_key=api_keyss[count%2])
    response = client.models.generate_content(
        model="gemini-2.0-flash", 
        contents = f"First, provide an algorithm that directly solves the problem \"{question}\" in the following format: \"Algorithm:\n1) Step 1\n2) Step 2\n3) Step 3\n...\". Ensure the algorithm steps are specific to the problem and describe the exact process to achieve the solution. Then, write a C program for {question}. Do not include any comments in the code. Add printf(\"{name}\"); as the first line inside the main function. After the code, in the same block, simulate one terminal test run showing input and output as it would appear when running the program, ensuring all input prompts and outputs are clearly labeled (e.g., \"Enter the size: 3\nEnter elements: 1 2 3\nOutput: ...\"). Do not add any extra explanation or formatting outside the algorithm and code block.")
    return response


    


# def main_response (question):
#     response = client.models.generate_content(
#     model="gemini-2.0-flash", 
#     contents="Write a C program " + question + " Do not include any comments. After the code, in the same code block, simulate one terminal test run showing input and output as it would appear when running the program. Do not add any extra explanation or formatting outside the code block")
#     return response