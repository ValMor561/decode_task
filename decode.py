def decode_message(file_path):
    encode = {}
    with open(file_path, 'r') as file:
        for line in file:
            numbers, word = line.strip().split(' ')
            encode[int(numbers)] = word
    max_num = max(encode.keys())
    encode_pos = right_side_numbers(max_num)
    decode_message = ""
    for pos in encode_pos:
        if encode[pos]:
            decode_message += encode[pos] + " "
    return decode_message

def right_side_numbers(max_value):
    nums = []
    i = 1
    k = 2
    while i <= max_value:
        nums.append(i)
        i += k
        k += 1
    return nums

file_path = "message_file.txt"  
decoded_message = decode_message(file_path)
print(decoded_message)