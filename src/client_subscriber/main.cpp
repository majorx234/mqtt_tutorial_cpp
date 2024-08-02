#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <signal.h>
#include <sstream>
#include <string>
#include <unistd.h>

#include <mosquittopp.h>
#include "mqtt_server_conf.hpp"
#include "mqtt_client.hpp"


#define MAX_PAYLOAD 50
#define DEFAULT_KEEP_ALIVE 60

std::atomic<int> stop_main = 0;

void catchUnixSignal(int quitSignal) {
  auto handler = [](int sig) -> void {
    stop_main.store(1);
    printf("quit application. received signal(%d)\n", sig);
  };

  sigset_t blocking_mask;
  sigemptyset(&blocking_mask);

  sigaddset(&blocking_mask, quitSignal);
  struct sigaction sa;
  sa.sa_handler = handler;
  sa.sa_mask = blocking_mask;
  sa.sa_flags = 0;

  sigaction(quitSignal, &sa, nullptr);
}

void message_callback(std::string message) {
  std::cout << "messsage: " << message << std::endl;
}

int main(int argc, char *argv[]) {
  catchUnixSignal(SIGINT);

  MqttServerConf server_args = {
      // Todo store Commandline args here
      .client_id = "client_subscriber",
      .broker_hostname = "localhost",
      .broker_port = 1883,
      .location = "location",
      .mqtt_channel_name = "testing",
      .keepalive = DEFAULT_KEEP_ALIVE,
      .qos = MQTT_QOS_0
  };

  mosqpp::lib_init();
  // create mosquitto mqtt client:
  MqttClient mqtt_client(server_args.client_id, true);
  StringCB message_cb_fct = std::bind(message_callback, std::placeholders::_1);
  mqtt_client.register_message_callback(message_cb_fct);

  int connect_status = mqtt_client.connect(server_args.broker_hostname, server_args.broker_port, server_args.keepalive);

  if (connect_status == MOSQ_ERR_SUCCESS) {
    std::cout << "Sucessfully connected!" << std::endl;
  } else {
    std::cout << "Error no: " << connect_status << std::endl;
  }
  int set = mqtt_client.subscribe(NULL, server_args.mqtt_channel_name, server_args.qos);

  uint64_t test_value = 0;
  while (!stop_main.load()) {
    /* Some workload may be here */
    // TODO receive message here
    mqtt_client.loop(10, 1);
  }
  mosqpp::lib_cleanup();

  return 0;
}

