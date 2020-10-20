void sensor ()
{
  conta=1; // contador controla el servo, para que solo efectue el movimiento una vez durante el while
  digitalWrite(echo1Pin, LOW);   
  digitalWrite(trig1Pin, LOW);   
  delayMicroseconds(10);
  digitalWrite(trig1Pin, HIGH);  // enciende el pulso
  delayMicroseconds(10);
  digitalWrite(trig1Pin, LOW);   // apaga el pulso despues de 10 us
  duration = pulseIn(echo1Pin, HIGH);  // tiempo del pulso
  distance = (duration/2.0)*0.0343;   // convertir el tiempo a distancia
  while (distance<3) {                //mientras la persona este cerca
  digitalWrite(echo1Pin, LOW);   
  digitalWrite(trig1Pin, LOW);  
  delayMicroseconds(10);
  digitalWrite(trig1Pin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(trig1Pin, LOW);
  duration = pulseIn(echo1Pin, HIGH); 
  distance = (duration/2.0)*0.0343;   // repite los pasos dentro del while.
 // Serial.println(distance);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("su temperatura corporal es:");
  display.setCursor(50, 32);
  display.println(mlx.readObjectTempC()); //llama a la funcion para leer la temperatura y la muestra
  display.display(); 
  conta2=1;
  if (conta==1)
  {
    
     for (pos = 0; pos <= 180; pos += 1) { //ciclos for para el movimiento del servo, abre y cierra el gel antibacterial.
    // in steps of 1 degree
    lavado.write(pos);             
    delay(10);                       
  }
  
  delay(3000);
    for (pos = 180; pos >= 0; pos -= 1) { 
    lavado.write(pos);             
    delay(10);                       
  }
  conta=2;
  }
  }
  if (conta2==1) //indica que ya ha salido del while, significa que la persona se lavo las manos, la acción es apagar la pantalla.
  {
    delay(3000);
    display.clearDisplay();
    display.display();
    conta2==0;
    }
  }
