import random
import time
import sys 

flag='............................bbctf{Ours_1s_f0und3d_upon_h4tREd}................................'

def generate_stream():
    pos = random.randint(0, len(flag))
    while True:
        yield flag[pos % len(flag)]
        pos += 1

def main():
    gen = generate_stream()
    while True:
        print(next(gen), end='')
        sys.stdout.flush()
        time.sleep(0.1)
        
if __name__ == "__main__":
    main()