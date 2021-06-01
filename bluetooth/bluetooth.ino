#include <SoftwareSerial.h>
#include <Servo.h>

// HC-06 TX conectado a pin 2
// HC-06 RX conectado a pin 3
SoftwareSerial BT(2, 3);

// Crear objeto servo
Servo miservo;
// Posición servo
int prevReceived = 0;
int received = 0;

void moveServo(int pos) {
  // Mueve el servo a la posición pos
  miservo.write(pos);
  delay(15);
}

void setup()
{
  BT.begin(9600);
  Serial.begin(9600);

  // Iniciar servo en pin 9
  miservo.attach(9);
  moveServo(0);
}

void loop()
{
  // Guardar datos recibidos
  if (BT.available()) {
    received = BT.read();
    Serial.print("Posición: ");
    Serial.println(received);
  }

  if (received != prevReceived) {
    // Mover Servo
    if (received == 97) {
      moveServo(90);
    }
    else {
      moveServo(0);
    }
    prevReceived = received;
  }
}
