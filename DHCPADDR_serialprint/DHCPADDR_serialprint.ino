/*
  DHCP-based IP printer
 
 This sketch uses the DHCP extensions to the Ethernet library
 to get an IP address via DHCP and print the address obtained.
 
 created 12 April 2011
 by Tom Igoe
 
 */

#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0x00, 0x1A, 0xB6, 0x02, 0xC1, 0x38 };


#define LED1 D1_LED
#define LED2 D2_LED
#define LED3 D3_LED
#define LED4 D4_LED
#define SW1 USR_SW1
#define SW2 USR_SW2


// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

  
  // start the serial library:
  Serial.begin(9600);
  Serial.println("\n\nDhcpAddressPrinter setup");
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    digitalWrite( LED1, HIGH);
    Serial.println("Failed to configure Ethernet using DHCP");
    
    // no point in carrying on, so do nothing forevermore:
    for(;;)
      ;
  }
  // print your local IP address:
  digitalWrite( LED2, HIGH);
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print("."); 
  }
  Serial.println("\nPing me!");
  
}

void loop() {
  
  if (digitalRead(SW1) == 0){
      digitalWrite(LED3, HIGH);
      
      delay(1000);
      digitalWrite(LED3, LOW);
  }
  
  if(digitalRead(SW2) == 0){
    Serial.print("My IP address: ");
    for (byte thisByte = 0; thisByte < 4; thisByte++) {
      // print the value of each byte of the IP address:
      Serial.print(Ethernet.localIP()[thisByte], DEC);
      Serial.print("."); 
    }
    Serial.print("\n");
    delay(1000);
  }  
}
