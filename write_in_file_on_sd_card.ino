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

char pathname[] = "test.txt"; // Path of the file you want to write in
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
  
  file = SD.open(pathname, FILE_WRITE);
  if (file) {
    Serial.print("Writing to file...");
    file.println("This is a cool sentence in a test file :)");
    file.close();
    Serial.println(" done.");
  } else {
    Serial.println("Error while opening file");
  }
}

void loop() {
  Serial.print("Ending program");
  while (1);
}