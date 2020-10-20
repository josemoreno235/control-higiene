#include <WiFi.h>  // libreria conexión wifi
#include <FirebaseESP32.h>  //libreria para utilizar Firebase
#include <ESP32Servo.h>  //libreria para utilizar servomotor con esp32
#include <SPI.h>     // libreria que habilita el protocolo SPI
#include <MFRC522.h> // libreria modulo mfrc522
#include <Wire.h>  //libreria protocolo i2c
#include <Adafruit_GFX.h>   
#include <Adafruit_SSD1306.h> //librerias pantalla oled 0.96 
#include <Adafruit_MLX90614.h> //libreria sensor infrarrojo
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#define FIREBASE_HOST "****" // autenticacion en firebase
#define FIREBASE_AUTH "****"
#define WIFI_SSID "***"   //autenticacion zona wifi
#define WIFI_PASSWORD "****"
// Firebase Data object
FirebaseData firebaseData;
#define SS_PIN 2 //Pin ss mfrc 522
#define RST_PIN 4 
MFRC522 mfrc522(SS_PIN, RST_PIN);   // instancia mfrc522.
#define SCREEN_WIDTH 128 // pixels pantalla eje x
#define SCREEN_HEIGHT 64 // pixels pantalla eje y
int trig1Pin = 13;            // HC-SR04 trigger pin
int echo1Pin = 12;            // HC-SR04 echo pin
int trig2Pin = 14;          
int echo2Pin = 27;
float duration, distance, duration2, distance2;   
Servo lavado; 
int pos=0; 
int conta=0; 
int conta2=0;    
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
String nodo = "/Sensor";
String nodo2= "/estudiantes";
void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectado al Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  lavado.attach(26);   // declaración pin servo 
  pinMode(trig1Pin, OUTPUT);
  pinMode(trig2Pin, OUTPUT);
  mlx.begin();    // se inicializa el sensor mlx
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3c for 128x64
  Serial.println(F("SSD1306 allocation failed"));
  for(;;);
  }
delay(2000);
}
void mfrc();
void sensor();
void loop() {
  sensor(); 
  mfrc();
}
