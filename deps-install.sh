sudo apt-get update
sudo apt-get install cmake -y
sudo apt-get install build-essential -y
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install libssl-dev
sudo apt-get install zlib1g-dev
sudo apt install rapidjson-dev

#install cpr
git clone https://github.com/libcpr/cpr.git
cd cpr && mkdir build && cd build
cmake .. -DCPR_USE_SYSTEM_CURL=ON
cmake --build . --parallel
sudo cmake --install .
sudo ldconfig

#install influxdb
mkdir build && cd build
cmake .. -DINFLUXCXX_WITH_BOOST=OFF -DINFLUXCXX_TESTING=OFF
sudo make install

#TA-lib install
sudo ./configure -prefix=/usr
sudo make
sudo make install