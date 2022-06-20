// AUTHOR: Gabriel Lepinay 
// DATE: 20/06/2022
// SETUP:
// I use an extern sd card reader and an arduino uno
// GND -> GND
// VCC -> 5V
// MISO -> 12
// MOSI -> 11
// SCK -> 13
// CS -> 10

#include <SPI.h>
#include <SD.h>

char pathname[] = "test.txt"; // Path of file you want to open
File file;

void setup() {

  Serial.begin(9600);
  while (!Serial) {;}
  
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println(" failed.");
    while (1);
  }
  
  Serial.println(" done.");
  
  file = SD.open(pathname, FILE_READ);
  if (file) {
    Serial.print("File content:");
    while (file.available()) {
      Serial.write(file.read());
    }
    file.close();
  } else {
    Serial.println("Error while opening file");
  }
}

void loop() {
  Serial.print("Ending program");
  while (1);
}