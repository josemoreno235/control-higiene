void mfrc ()
{
  SPI.begin();      // inicializa el protocolo SPI
  mfrc522.PCD_Init();   // inicializa el mfrc522
    // si detecta una tarjeta 
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  //Serial.print("UID tag :");
  String content= "";//
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  String nodo3=content.substring(1); //declara el nodo en el cual buscara
//  Serial.print(nodo3);
  Firebase.getString(firebaseData, nodo2 + "/"+nodo3);//lee el contenido de la base de datos en la coordenada indicada
  String dato=firebaseData.stringData();  // regresa el dato leido en formato string
  //Serial.println(firebaseData.stringData());
 if (dato.length()==0) {  // si no lee nada, debe registrarse
  display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("BIENVENIDO:");
    display.setCursor(30, 32);
    display.println("por favor registrese con el docente");
    display.setCursor(0,36);
    display.println("UID:"+ content.substring(1)); 
    display.display();
    delay(3000);
    display.clearDisplay();
    display.display();
  }
  else {  //si la lectura es exitosa, da la bienvenida al estudiante
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("BIENVENIDO:");
    display.setCursor(30, 32);
    display.println(firebaseData.stringData());
    display.display(); 
    delay(3000);
    display.clearDisplay();
    display.display();
  }
//  if (content.substring(1) == "B9 28 41 E8") //change here the UID of the card/cards that you want to give access
//  {
//    display.clearDisplay();
//    display.setTextSize(1);
//    display.setTextColor(WHITE);
//    display.setCursor(0, 0);
//    display.println("BIENVENIDO:");
//    display.setCursor(30, 32);
//    display.println("SAMUEL DAVID");
//    display.display(); 
//    delay(3000);
//    display.clearDisplay();
//    display.display();
//  }
//    else if (content.substring(1) == "9A BA 48 41") //change here the UID of the card/cards that you want to give access
//  {
//    delay(250);
//    display.clearDisplay();
//    display.setTextSize(1);
//    display.setTextColor(WHITE);
//    display.setCursor(0, 0);
//    display.println("BIENVENIDO:");
//    display.setCursor(30, 32);
//    display.println("MONI");
//    display.display(); 
//    delay(3000);
//    display.clearDisplay();
//    display.display();
//  }
//    else if (content.substring(1) == "6A BD 38 41") //change here the UID of the card/cards that you want to give access
//  {
//    
//  }
//  else if (content.substring(1) == "DA 71 19 35") //change here the UID of the card/cards that you want to give access
//  {
//    display.clearDisplay();
//    display.setTextSize(1);
//    display.setTextColor(WHITE);
//    display.setCursor(0, 0);
//    display.println("BIENVENIDO:");
//    display.setCursor(30, 32);
//    display.println("ALDE");
//    display.display(); 
//    delay(3000);
//    display.clearDisplay();
//    display.display();
//  }
//    else if (content.substring(1) == "FA B4 28 28") //change here the UID of the card/cards that you want to give access
//  {
//    display.clearDisplay();
//    display.setTextSize(1);
//    display.setTextColor(WHITE);
//    display.setCursor(0, 0);
//    display.println("BIENVENIDO:");
//    display.setCursor(30, 32);
//    display.println("DINA");
//    display.display(); 
//    delay(3000);
//    display.clearDisplay();
//    display.display();
//  }
// else   {
//    Serial.println(" Access denied");
//    delay(3000);
//  }

  }
