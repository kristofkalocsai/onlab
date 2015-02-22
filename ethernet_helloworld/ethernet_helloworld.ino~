#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0x00, 0x1A, 0xB6, 0x02, 0xC1, 0x38 };

IPAddress thinkpad(192,168,1,23);
#define port 5005

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
  Serial.println("Starting Ethernet:");
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {  //if fails:

    Serial.println("FAIL!");
    // no point in carrying on, so do nothing forevermore:
    for(;;);
  }
  // if success"
  Serial.println("success");
  Serial.println("My IP address: ");
  Serial.println(Ethernet.localIP());
  Serial.println("Ping me!");


  Serial.print("trying to connect: ");
  while(1) {
    //trying to connect to the previously declared IP&PORT
    if (client.connect(thinkpad,port)){
      //if connection was successful
      Serial.println("connected");
      break;

    } else {
      //self explanatory
      Serial.println("connection failed, retry in 5sec");

    }

    delay(5000);

  }

}

void loop() {

  //if there is data to receive
  if (client.available()){

      char c = client.read();
      Serial.print(c);

  }

  //if SW1 pressed, send line
  if (digitalRead(SW1) == 0){

      client.println("hello thinkpad!\n");
      delay(1000);

  }


  //for debug, SW2 press writes the IP of the launchpad
  if(digitalRead(SW2) == 0){

    Serial.print("My IP address: ");
    Serial.println(Ethernet.localIP());

  }
  delay(1000);

}
