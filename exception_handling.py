try:
    with open('file.txt', 'r') as f:
        content = f.read()
except FileNotFoundError:
    print("File not found, please check the path.")
except PermissionError:
    print("You do not have permissions to open this file.")
