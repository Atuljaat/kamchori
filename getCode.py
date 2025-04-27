from dotenv import load_dotenv
from openai import OpenAI
import os
from google import genai
import time

load_dotenv()
apiKey = os.getenv("GENAI_API_KEY")
apiKey2 = os.getenv("GENAI_API_KEY2")

deep_key = os.getenv("DEEP_API_KEY")
deep_key2 = os.getenv("DEEP_API_KEY2")


api_keyss = [apiKey, apiKey2]
deep_keyss = [deep_key, deep_key2]


# def response (question,language) : 
#     response = client.models.generate_content(
#     model="gemini-2.0-flash", contents=" only show me the full code for : " + question + "in" + language + "do not write comments and beautifully format the code" )
#     return response

# def inputtext (question) :
#     response = client.models.generate_content(
#     model="gemini-2.0-flash", contents="Given the following program, give only the input values as if I were entering them in the terminal, no explanation, no extra text:" + question )
#     return response

name = "Prerit BCA-2A \nEnrollment No: 05817702024"
# printf("\nPrerit Bhatia BCA 2-A\n");
# printf("Enrollment No: 05817702024\n\n");

# f"Write a C program {question} Do not include any comments and also add printf(\"{name}\"); as the first line inside main code. After the code, in the same code block, simulate one terminal test run showing input and output as it would appear when running the program. Do not add any extra explanation or formatting outside the code block."
def main_response(question,count):
    client = genai.Client(api_key=api_keyss[count%2])
    response = client.models.generate_content(
        model="gemini-2.0-flash", 
        contents = f"First, provide an algorithm that directly solves the problem \"{question}\" in the following format: \"Algorithm:\n1) Step 1\n2) Step 2\n3) Step 3\n...\". Ensure the algorithm steps are specific to the problem and describe the exact process to achieve the solution. Then, write a C program for {question}. Do not include any comments in the code. Add printf(\"{name}\"); as the first line inside the main function. After the code, in the same block, simulate one terminal test run showing input and output as it would appear when running the program, ensuring all input prompts and outputs are clearly labeled (e.g., \"Enter the size: 3\nEnter elements: 1 2 3\nOutput: ...\"). Do not add any extra explanation or formatting outside the algorithm and code block.")
    return response

def algo_response(code,count):
    client = genai.Client(api_key=api_keyss[count%2])
    prompt = f"Write the algorithm for the below code in a clean, textbook style. Number each step (Step 1, Step 2, etc.). Use all-caps keywords like SET, IF, ELSE, EXIT, and use → for pointer access (e.g., PTR→NEXT). Keep the steps short and to the point — avoid unnecessary explanations. Indent actions inside IF or loops, and mark their end with [END OF IF] or [END OF LOOP]. Start with initialization, perform condition checks and updates, and end with EXIT. Keep the entire algorithm as concise as possible."
    response = client.models.generate_content(
        model="gemini-2.0-flash", 
        contents = f"{prompt} \n {code}")
    return response.text





    


# def main_response (question):
#     response = client.models.generate_content(
#     model="gemini-2.0-flash", 
#     contents="Write a C program " + question + " Do not include any comments. After the code, in the same code block, simulate one terminal test run showing input and output as it would appear when running the program. Do not add any extra explanation or formatting outside the code block")
#     return response