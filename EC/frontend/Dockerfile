FROM node:20

# 作業ディレクトリを設定
WORKDIR /app

# 依存関係のインストール
COPY package.json ./
RUN npm install

# TypeScript の設定ファイルをコピー
COPY tsconfig.json ./

# 残りのソースコードをコピー
COPY . .

# TypeScript をビルド（必要に応じて）
RUN npm run build

# コンテナ実行時のコマンド
CMD ["npm", "run", "dev"]