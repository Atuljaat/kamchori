from dotenv import load_dotenv
import os
from google import genai

client = genai.Client(api_key=os.getenv("GENAI_API_KEY"))

def response (question,language) : 
    response = client.models.generate_content(
    model="gemini-2.0-flash", contents=" only show me the full code for : " + question + "in" + language + "do not write comments and beautifully format the code" )
    return response

def inputtext (question) :
    response = client.models.generate_content(
    model="gemini-2.0-flash", contents="Given the following program, give only the input values as if I were entering them in the terminal, no explanation, no extra text:" + question )
    return response

def main_response (question):
    response = client.models.generate_content(
    model="gemini-2.0-flash", 
    contents="Write a C program " + question + " Do not include any comments. After the code, in the same code block, simulate one terminal test run showing input and output as it would appear when running the program. Do not add any extra explanation or formatting outside the code block")
    return response