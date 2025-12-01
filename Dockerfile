FROM ubuntu:22.04

# 必要なツールをインストール
RUN apt-get update && apt-get install -y \
    build-essential cmake git \
    && rm -rf /var/lib/apt/lists/*

# GoogleTest をインストール
RUN git clone https://github.com/google/googletest.git /usr/src/googletest \
    && cd /usr/src/googletest \
    && cmake . && make && make install

# 作業ディレクトリを設定
WORKDIR /app

# プロジェクトファイルをコピー
COPY . .

# ビルド
RUN cmake . && make

# コンテナ起動時にテストを実行
CMD ["ctest", "--output-on-failure"]
