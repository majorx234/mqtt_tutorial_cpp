#include <mosquittopp.h>
#include "mqtt_client.hpp"

MqttClient::MqttClient(const char *id, bool clean_session)
    : mosqpp::mosquittopp(id, clean_session) {}

MqttClient::~MqttClient() {
  mosqpp::mosquittopp::~mosquittopp();
}

void MqttClient::on_message(const struct mosquitto_message* message) {
  if (this->message_cb) {
    std::string string_payload(static_cast<char*>(message->payload), message->payloadlen);
    this->message_cb(string_payload);
  }
}

void MqttClient::register_message_callback(StringCB new_message_cb) {
  this->message_cb = new_message_cb;
}
