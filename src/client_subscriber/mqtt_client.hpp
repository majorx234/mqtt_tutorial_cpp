#ifndef MQTT_CLIENT_HPP
#define MQTT_CLIENT_HPP

#include <string>
#include <functional>

#include <mosquittopp.h>
typedef std::function<void(std::string)> StringCB;


class MqttClient : public mosqpp::mosquittopp {
public:
  MqttClient(const char *id, bool clean_session);
  ~MqttClient();
  void register_message_callback(StringCB);
private:
  void on_message(const struct mosquitto_message* message) override;
  StringCB message_cb;
};

#endif // MQTT_CLIENT_HPP
