#include "parking.h"
#include "arduino.h"

void commandeBarriere(int sens, int tours)
{
  pinMode(PAS1, OUTPUT);
  pinMode(PAS2, OUTPUT);
  pinMode(PAS3, OUTPUT);
  pinMode(PAS4, OUTPUT);
  if (sens)
  {
    ouvrir(tours);
  }
  else
  {
    fermer(tours);
  }
}
void ouvrir (int tours)
{
  int i, j;
  for (i = 0; i < tours; i++)
  {
    for (j = 0; j < 12; j++)
    {
      seq(1);
      delay(TEMPO);
      seq(2);
      delay(TEMPO);
      seq(3);
      delay(TEMPO);
      seq(4);
      delay(TEMPO);
    }
  }
}
void fermer (int tours)
{
  int i, j;
  for (i = 0; i < tours; i++)
  {
    for (j = 0; j < 12; j++)
    {
      seq(4);
      delay(TEMPO);
      seq(3);
      delay(TEMPO);
      seq(2);
      delay(TEMPO);
      seq(1);
      delay(TEMPO);
    }
  }
}
void seq(int numeroSeq)
{
  switch (numeroSeq)
  {
    case 1:
      digitalWrite(PAS1, HIGH);
      digitalWrite(PAS2, LOW);
      digitalWrite(PAS1, LOW);
      digitalWrite(PAS2, HIGH);
    case 2:
      digitalWrite(PAS1, LOW);
      digitalWrite(PAS2, HIGH);
      digitalWrite(PAS1, LOW);
      digitalWrite(PAS2, HIGH);
    case 3:
      digitalWrite(PAS1, LOW);
      digitalWrite(PAS2, HIGH);
      digitalWrite(PAS1, HIGH);
      digitalWrite(PAS2, LOW);
    case 4:
      digitalWrite(PAS1, HIGH);
      digitalWrite(PAS2, LOW);
      digitalWrite(PAS1, HIGH);
      digitalWrite(PAS2, LOW);
  }
}
