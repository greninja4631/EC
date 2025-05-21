FROM python:3.11

# 作業ディレクトリを設定
WORKDIR /app

# 依存関係をコピーし、キャッシュを最小化
COPY requirements.txt ./
RUN pip install --no-cache-dir -r requirements.txt

# ソースコードをコピー
COPY . .

# コンテナ実行時のコマンド
CMD ["python", "main.py"]

