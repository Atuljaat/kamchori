from dotenv import load_dotenv
import os
from google import genai

client = genai.Client(api_key=os.getenv("GENAI_API_KEY"))
def response (question,language) : 
    response = client.models.generate_content(
    model="gemini-2.0-flash", contents=" only show me the full code for : " + question + "in" + language + "do not write comments and beautifully format the code" )
    return response