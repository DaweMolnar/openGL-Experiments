# OS X
# ====

# GLFW
git clone https://github.com/glfw/glfw.git
cd ./glfw
git checkout latest

cmake .
make

# Alternatively, just `sudo make install`
mkdir -p /usr/local/include/GLFW/
cp ./include/GLFW/glfw3.h /usr/local/include/GLFW/
cp ./src/libglfw3.a /usr/local/lib/

go get -u "github.com/go-gl/glfw3"

# Linux
# =====

# Make sure glfw (or any previous version) is not already installed
sudo apt-get update
sudo apt-get install build-essential cmake git xorg-dev libglu1-mesa-dev
git clone https://github.com/glfw/glfw.git /tmp/glfw
cd /tmp/glfw
git checkout latest
cmake . -DBUILD_SHARED_LIBS=ON
make
sudo make install
sudo ldconfig
# rm -rf /tmp/glfw
