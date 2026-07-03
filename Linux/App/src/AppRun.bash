g++ src/krynet_linux_secure.cpp \
  -I sciter/include \
  -L sciter/bin.linux/x64 \
  -lsciter \
  $(pkg-config --cflags --libs gtk+-3.0) \
  -ldl \
  -std=c++17 \
  -O3 \
  -march=native \
  -flto \
  -fdata-sections \
  -ffunction-sections \
  -Wl,--gc-sections \
  -Wl,-rpath,'$ORIGIN/../lib:$ORIGIN' \
  -s \
  -DNDEBUG \
  -o krynet
