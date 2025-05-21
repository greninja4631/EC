import os
import csv
import tarfile
import zipfile
import tempfile
import subprocess
import datetime

# 91. ファイルの作成
filename = "sample.txt"
with open(filename, "w") as f:
    f.write("Hello, Python!\nThis is a sample file.\nLet's test file operations.")

# 92. withステートメントでファイルをopenする
with open(filename, "r") as f:
    content = f.read()
    print("92. ファイルの内容:\n", content)

# 93. ファイルの読み込み
with open(filename, "r") as f:
    first_line = f.readline()
    print("93. 最初の行:", first_line.strip())

# 94. seekを使って移動する
with open(filename, "r") as f:
    f.seek(7)  # 7バイト目から読み込み
    print("94. seek(7)後の読み込み:", f.read(5))  # 5文字読む

# 95. 書き込み読み込みモード
with open(filename, "a+") as f:
    f.write("\nNew line added!")
    f.seek(0)
    print("95. 追記後の内容:\n", f.read())

# 96. テンプレート（今回はプレースホルダーを使った文字列操作）
template = "Hello, {name}. Today is {day}."
formatted = template.format(name="Alice", day=datetime.datetime.now().strftime("%A"))
print("96. フォーマット済み文字列:", formatted)

# 97. CSVファイルへの書き込みと読み込み
csv_filename = "sample.csv"
with open(csv_filename, "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["Name", "Age", "City"])
    writer.writerow(["Alice", 25, "New York"])
    writer.writerow(["Bob", 30, "Los Angeles"])

with open(csv_filename, "r") as f:
    reader = csv.reader(f)
    print("97. CSVファイルの内容:")
    for row in reader:
        print(row)

# 98. ファイル操作
os.rename(csv_filename, "renamed_sample.csv")  # 名前変更
print("98. ファイルが 'renamed_sample.csv' にリネームされました")

# 99. tarfileの圧縮展開
tar_filename = "sample.tar.gz"
with tarfile.open(tar_filename, "w:gz") as tar:
    tar.add(filename)
    tar.add("renamed_sample.csv")

with tarfile.open(tar_filename, "r:gz") as tar:
    tar.extractall("extracted_tar")
    print("99. tarファイルを展開しました")

# 100. zipfileの圧縮展開
zip_filename = "sample.zip"
with zipfile.ZipFile(zip_filename, "w") as zipf:
    zipf.write(filename)
    zipf.write("renamed_sample.csv")

with zipfile.ZipFile(zip_filename, "r") as zipf:
    zipf.extractall("extracted_zip")
    print("100. zipファイルを展開しました")

# 101. tempfile（一時ファイルの作成）
with tempfile.NamedTemporaryFile(delete=False) as tmp:
    tmp.write(b"This is a temporary file")
    temp_filename = tmp.name
print(f"101. 一時ファイルを作成しました: {temp_filename}")

# 102. subprocessでコマンドを実行する
result = subprocess.run(["echo", "Hello, subprocess!"], capture_output=True, text=True)
print("102. subprocessの出力:", result.stdout.strip())

# 103. datetime（現在の日時を取得）
now = datetime.datetime.now()
print("103. 現在の日時:", now.strftime("%Y-%m-%d %H:%M:%S"))