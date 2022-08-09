# Introduction
This code in mainly based on [this tutorial](https://www.emqx.com/en/blog/esp32-connects-to-the-free-public-mqtt-broker).

In this project, we will connect ESP32 to a free public MQTT server operated and maintained by EMQX MQTT Cloud, and use the Arduino IDE to program the ESP32. EMQX Cloud is a secure MQTT IoT cloud service platform launched by EMQ. It provides MQTT 5.0 access service with one-stop operation and maintenance management and a unique isolation environment[^1].

![](https://assets.emqx.com/images/d6265585d6257fc02c722fe45888bdac.png?imageMogr2/thumbnail/1520x)

# Arduino Configuration 
It is necessary to add ESP32 library to the Arduino IDE by Click `Tools -> Development Board -> Development Board Management -> Search ESP32 -> Install`

![](https://assets.emqx.com/images/99c502b39ef7d21dc75632e42aa89708.png?imageMogr2/thumbnail/1520x)

Then, install the PubSubClient library by `Project -> Load library -> Library manager... -> Search PubSubClient -> Install PubSubClient by Nick O’Leary`

![](ihttps://assets.emqx.com/images/cb7b0228aa91bf300eec5a725da159d3.png?imageMogr2/thumbnail/1520x)

---

[^1]: https://www.emqx.com/en/blog/esp32-connects-to-the-free-public-mqtt-broker
