import os
import time

def logo():
    print("---------------------------------------------------------------------------")
    print("██████╗░░█████╗░░█████╗░███╗░░░███╗  ░░███╗░░░█████╗░░░███╗░░")
    print("██╔══██╗██╔══██╗██╔══██╗████╗░████║  ░████║░░██╔══██╗░████║░░")
    print("██████╔╝██║░░██║██║░░██║██╔████╔██║  ██╔██║░░██║░░██║██╔██║░░")
    print("██╔══██╗██║░░██║██║░░██║██║╚██╔╝██║  ╚═╝██║░░██║░░██║╚═╝██║░░")
    print("██║░░██║╚█████╔╝╚█████╔╝██║░╚═╝░██║  ███████╗╚█████╔╝███████╗")
    print("╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░░░░╚═╝  ╚══════╝░╚════╝░╚══════╝")
    print("---------------------------------------------------------------------------")
    print(" Ministry of Love XOR Encryption Engine version 2.2.5                      ")
    print("---------------------------------------------------------------------------")

def split_string_by_two_bytes(input_string):
    result_list = []
    for i in range(0, len(input_string), 2):
        result_list.append(input_string[i:i+2])
    print(result_list)

def slow_print(message, delay=0.01):
    for char in message:
        print(char, end='', flush=True)
        time.sleep(delay)

random_byte = os.urandom(1)
logo()
with open('flag.txt', 'rb') as f:
    data = f.read()

encrypted_data = bytes([b ^ random_byte[0] for b in data])
hex_data = encrypted_data.hex()
slow_print("<<< Ministry of Love has securely stored the flag from thought criminals: ")
split_string_by_two_bytes(hex_data)

while (True):
    slow_print("Enter Your Secrets to Encrypt >>> ")
    data = input().encode('utf-8')
    encrypted_data = bytes([b ^ random_byte[0] for b in data])
    hex_data = encrypted_data.hex()
    slow_print("<<< Your data is safe from the thought criminals: ")
    split_string_by_two_bytes(hex_data)