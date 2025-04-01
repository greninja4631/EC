numbers = [3, 7, 2, 8, 5]

# リストの最初の要素を「仮の最大値」とする
max_value = numbers[0]

# リストの2番目以降の要素と「仮の最大値」を比較する
for number in numbers[1:]:
  if number > max_value:
    # リストの要素の方が大きければ、「仮の最大値」を更新する
    max_value = number

# 最大値を出力する
print(max_value)