#include <Servo.h>
Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(6);

}

void loop() {
  for(pos = 0; pos < 380; pos+= 1) // perulangan untuk posisi 0 sampai 180 derajat

  { // step setiap 1 derajat

   myservo.write(pos); // memerintahkan servo ke posisi derajat sesuai nilai variabel pos

   delay(100); // menunggu 15 milidetik

  }

  for(pos = 380; pos>=1; pos-=1) // perulangan untuk posisi 180 sampai 0 derajat

  {

   myservo.write(pos); // memerintahkan servo ke posisi derajat sesuai nilai variabel pos

   delay(100); // menunggu 15 milidetik

  }

}
