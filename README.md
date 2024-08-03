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

## mqtt_client_subscriber
 C++ test application
- `mkdir build && cd build && cmake .. && make`
- run with: `./mqtt_client_publisher`
- subscribes topic "testing" and prints
- published to test:
  - `mosquitto_pub -h localhost -t testing -m "{\"value\":\"1234\"}"`
### implementation
- files:`mqtt_client.hpp` and `mqtt_client.hpp`
  - class `MqttClient` extends `mosqpp::mosquittopp`
  - needs to implement virtual `on_message`-function
    - these function is called event driven
    - `mosquitto_message` parameter has attribute `payload`
- `MqttClient` has function to register callbacks: `register_message_callback`
- in `main.cpp` a callback is implemented and registred via `register_message_callback`
