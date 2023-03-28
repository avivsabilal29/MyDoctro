#include <Servo.h>
#include <SunPosition.h>
#include <SIM808.h>

// Deklarasi pin yang akan digunakan untuk mengontrol servo
const int servoVertikalPin = 9;
const int servoHorizontalPin = 10;

// Buat objek servo
Servo servoVertikal;
Servo servoHorizontal;

// Buat objek SIM808
SIM808 sim808;

void setup() {
  // Inisialisasi servo
  servoVertikal.attach(servoVertikalPin);
  servoHorizontal.attach(servoHorizontalPin);

  // Inisialisasi SIM808
  sim808.begin();
}

void loop() {
  // Baca waktu dan koordinat pengguna dari SIM808
  DateTime waktuSekarang = sim808.getTime();
  double latitude = sim808.getLatitude();
  double longitude = sim808.getLongitude();

  // Hitung posisi sudut elevasi dan azimut matahari
  double sudutElevasi = SunPosition::elevation(latitude, longitude, waktuSekarang.hour(), waktuSekarang.minute(), waktuSekarang.second(), timeZone);
  double sudutAzimut = SunPosition::azimuth(latitude, longitude, waktuSekarang.hour(), waktuSekarang.minute(), waktuSekarang.second(), timeZone);

  // Atur posisi servo vertikal dan servo horizontal sesuai dengan sudut elevasi dan azimut matahari
  servoVertikal.write(sudutElevasi);
  servoHorizontal.write(sudutAzimut);

  // Tunggu selama 1 menit sebelum menghitung posisi sudut matahari kembali
  delay(60000);
}
