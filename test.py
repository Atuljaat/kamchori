from getCode import main_response
import time
for a in range(1, 101):
    start_time = time.time()
    print(main_response(a).text)
    end_time = time.time()
    print("Time taken for prompt " + str(a) + " : " + str(end_time - start_time) + " seconds")
