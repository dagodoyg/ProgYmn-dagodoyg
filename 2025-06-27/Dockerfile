FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# Crear directorio de trabajo
WORKDIR /app

# Instalación de dependencias necesarias
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    libx11-dev \
    libopenblas-dev \
    liblapack-dev \
    libeigen3-dev \
    libboost-all-dev \
    libopencv-dev \
    pkg-config \
    fish \
    && rm -rf /var/lib/apt/lists/*

# Descargar y compilar dlib desde fuente
RUN git clone https://github.com/davisking/dlib.git /usr/src/dlib
RUN cd /usr/src/dlib && mkdir build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && make install && ldconfig

# Crear el script de compilación
RUN echo '#!/bin/bash\n\
g++ "$@" -std=c++17 -ldlib -lpthread -ljpeg -lpng -lwebp $(pkg-config --cflags --libs opencv4)' > /usr/local/bin/cvd++ && \
    chmod +x /usr/local/bin/cvd++

# Ejecutar la aplicación por defecto
CMD ["/bin/fish"]