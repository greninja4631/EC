# ✅ ベース：Jenkins + JDK（CI/CD実行環境として安定）
FROM jenkins/jenkins:lts-jdk11

# ✅ root権限で開発環境をインストール（Jenkinsユーザーは非root）
USER root

# ✅ 必要なパッケージをインストール（C言語 / Python / Docker CLI）
RUN apt-get update && apt-get install -y \
    gcc \
    make \
    valgrind \
    python3 \
    python3-pip \
    docker.io \
    bash \
    && apt-get clean

# 🛠️ PEP668対策：pytestをインストール（強制オプション付き）
RUN pip3 install --no-cache-dir pytest --break-system-packages

# ✅ Jenkinsユーザーに戻す（セキュリティ考慮）
USER jenkins

# ✅ Jenkinsジョブでマウントされる作業ディレクトリ
WORKDIR /app

# ✅ デフォルトコマンド（ビルド＆テスト）
CMD ["make", "test"]