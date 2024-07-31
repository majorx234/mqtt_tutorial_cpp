# Info
- purpose of these tutorial is to have a simple exmaple
- of a producer and a consumer application
- both communicate over MQTT Server/Broker
- sum up additional information (links + references)

# Links
- https://makesomeshit.com/how-to-mqtt-in-cpp-c/
  - example with Paho library for C++
- https://doc.qt.io/qt-6/qtmqtt-simpleclient-example.html
  - example in QT
- https://doc.qt.io/qt-6/qtmqtt-examples.html
  - more examples in QT
- https://github.com/majorx234/mqtt_paho_client
  - own example with paho library

# mosquitto
## installation
- install with pacman: `sudo pacman -S mosquitto`
- under debian with apt: `sudo apt install mosquitto libmosquitto-dev libmosquittopp-dev mosquitto-clients`

## server
- `systemctl start mosquitto.service`

## mqtt_client_publisher
- C++ test application
- `mkdir build && cd build && cmake .. && make`
- run with: `./mqtt_client_publisher`
- check if data is published:
  - `mosquitto_sub -h localhost -t testing`
