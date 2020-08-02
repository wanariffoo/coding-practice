import json

# numbers = [0,1,2,3,4,5,6,7]

# # store numbers in a json file
# filename = 'file.json'

# with open(filename, 'w') as f_obj:
#     json.dump( numbers, f_obj )


# read numbers from a json file


filename = 'file.json'
with open(filename) as f_obj:
    numbers = json.load(f_obj)

print(numbers)