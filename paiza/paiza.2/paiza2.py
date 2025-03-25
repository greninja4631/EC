from collections import defaultdict

s = "fdjsafiewafjdsaeiwfdafke"  # 文字列を定義

d = defaultdict(int)  # デフォルト値が 0 の辞書を作成

for c in s:  # 文字列 s の各文字 c を1つずつ処理
    d[c] += 1  # その文字のカウントを 1 増やす

print(dict(d))  # 文字の出現回数を表示