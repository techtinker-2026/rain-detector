#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

void setup() {

  Serial.begin(115200); // PC Serial Monitor
  BT.begin(115200);       // HC-05 normal baud rate

  Serial.println("Bluetooth Chat Ready");
}

void loop() {

  // 📱 Phone → HC-05 → Arduino → Serial Monitor
  if (BT.available()) {

    char data = BT.read();

    Serial.write(data); // print on Serial Monitor
  }

  // 💻 Serial Monitor → Arduino → HC-05 → Phone
  if (Serial.available()) {

    char data = Serial.read();

    BT.write(data); // send to phone
  }
}