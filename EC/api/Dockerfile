FROM golang:1.21

# 作業ディレクトリを設定
WORKDIR /app

# `go.mod` と `go.sum` をコピー
COPY go.mod go.sum ./
RUN go mod tidy

# ソースコードをコピー
COPY . .

# バイナリをビルド
RUN go build -o main github.com/greninja4631/EC/api

# コンテナ実行時のコマンド
CMD ["./main"]