// C++ code
//
int buzzer = 8; //Buzzer sur broche 8.
int sensor = A2; //Photorésistance sur broche A2.

void setup()
{
  Serial.begin(9600); //Initilialisation port série.
  pinMode(buzzer, OUTPUT); //Buzzer en sortie.
  pinMode(sensor, INPUT); //Photorésistance en entrée.
}

void loop()
{
  //Lecture valeur de la photorésistance.
  int caption = analogRead(sensor);
  //Renvoi d'une valeur proportionnelle de la plage 54 à 974 ...
  //... dans une plage de 50 à 30 000 Hertz.
  int sound = map(caption, 54, 974, 50, 30000);
  //Lecture du son sur le buzzer.
  tone(buzzer, sound);
  
  //Pour débogage, affichage de la mesure de la photorésistance ...
  Serial.print("caption = ");
  Serial.print(caption);
  //... et de la fréquence envoyé au buzzer.
  Serial.print("sound = ");
  Serial.print(sound);
  Serial.println(" Hz");
}