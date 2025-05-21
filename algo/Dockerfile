# ✅ ベース：Jenkins + JDK（CI/CD実行環境として安定）
FROM jenkins/jenkins:lts-jdk11

# ✅ root権限で追加インストール
USER root

# ⛏️ 必要なツール群をインストール（C開発＋Docker CLI）
RUN apt-get update && apt-get install -y \
    gcc \
    make \
    valgrind \
    docker.io \
    bash \
    && apt-get clean

# ✅ Jenkinsユーザーに戻す（セキュリティ考慮）
USER jenkins

# ✅ 作業ディレクトリ（後からJenkinsでマウントされる想定）
WORKDIR /app

