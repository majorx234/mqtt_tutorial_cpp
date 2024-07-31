#include <cstdint>

/**
 * @brief New enum data type. Represents the posible quality of service levels in MQTT messages
 * supported by libmosquitto.
 */
typedef enum { MQTT_QOS_0 = 0, MQTT_QOS_1, MQTT_QOS_2 } mqtt_qos_t;

struct MqttServerConf {
  char client_id[128];         /**< client id ~ name */
  char broker_hostname[128];   /**< Hostname/IP of the MQTT broker host. */
  uint16_t broker_port;        /**< MQTT broker listens on this port for MQTT messages. */
  char location[64];           /**< MQTT location string. */
  char mqtt_channel_name[256]; /**< MQTT channel name */
  int keepalive;               /**< how long (sec) keep TCP Seesion alive  */
  mqtt_qos_t qos;
};
