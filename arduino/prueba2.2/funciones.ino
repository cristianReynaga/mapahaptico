void Apagar()
{
   digitalWrite(h1,OFF);
   digitalWrite(h2,OFF);
   digitalWrite(h3,OFF);
   digitalWrite(h4,OFF);
   digitalWrite(h5,OFF);
   digitalWrite(h6,OFF);
   digitalWrite(h7,OFF);
   
 analogWrite(R,0);
 analogWrite(G,0);
 analogWrite(B,0);
   hled = 0x00;
}

void Rgb(int r, int g , int b, bool H1, bool H2 , bool H3, bool H4, bool H5, bool H6, bool H7)
{
 analogWrite(R,r);
 analogWrite(G,g);
 analogWrite(B,b);
 digitalWrite(h1,H1);
 digitalWrite(h2,H2);
 digitalWrite(h3,H3);
 digitalWrite(h4,H4);
 digitalWrite(h5,H5);
 digitalWrite(h6,H6);
 digitalWrite(h7,H7);
} 


ISR(TIMER3_OVF_vect)
{ 
  static unsigned int tiempo_giro = TiempoGiro ;//tiempo en el cual gira el robot o retrocede
  TCNT3 = 3036;
  tiempo_giro --;
  if(tiempo_giro == 0){ 
    if ( aux == 0 ) {
       digitalWrite(ledPin,LOW);   
       aux = 1 ;   
    } else{
      digitalWrite(ledPin,HIGH);
      aux = 0 ;
    }
    tiempo_giro = TiempoGiro ;
  }      
}
