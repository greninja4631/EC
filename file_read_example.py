# file_read_example.py のコード
def read_file(filename):
    try:
        with open(filename, 'r') as f:
            content = f.readlines()
            print(content)
    except Exception as e:
        print(f"エラーが発生しました: {e}")

read_file("non_existent_file.txt")