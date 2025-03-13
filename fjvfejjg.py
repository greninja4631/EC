class MyRange:
    def __init__(self, start=1, stop=101, step=1):
        self.current = start
        self.stop = stop
        self.step = step  

    def __iter__(self):
        return self  

    def __next__(self):
        if self.current >= self.stop:
            raise StopIteration  # ここで終わり！
        value = self.current
        self.current += self.step  
        return value  

# 🔽 ここからが重要！（MyRange を実際に使う）
r = MyRange()  # デフォルトで start=1, stop=5, step=1

for num in r:
    print(num)  # これで 1 から 4 まで出力される