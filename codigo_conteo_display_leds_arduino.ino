int A = 1;
int B = 2;
int C = 3;
int D = 4;
int E = 5;
int F = 6;
int G = 7;

int LED8 = 8;
int LED9 = 9;
int LED10 = 10;
int LED11 = 11;
int LED12 = 12;
int LED13 = 13;
int LED14 = 14;
int LED15 = 15;
int LED16 = 16;
int LED17 = 17;

int boton1 = 19;  // Primer botón
int boton2 = 18;  // Segundo botón
int estado_btn1;
int estado_btn2;
int delay_time = 10;  // Valor inicial del delay
int delays[5];  // Arreglo para guardar los valores del delay
int index = 0;    // Índice para almacenar el valor de delay en el arreglo

// Arreglo con los números a mostrar en el display de 7 segmentos (0-9)
int numeros[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0}  // 9
};

void setup() {
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
  pinMode(LED12, OUTPUT);
  pinMode(LED13, OUTPUT);
  pinMode(LED14, OUTPUT);
  pinMode(LED15, OUTPUT);
  pinMode(LED16, OUTPUT);
  pinMode(LED17, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  
  // Inicializamos el arreglo con el valor de delay inicial
  delays[index] = delay_time;

  // Configuración de los pines del display de 7 segmentos
  for (int a = 1; a <= 7; a++) {
    pinMode(a, OUTPUT);
  }
}

void loop() {
  estado_btn1 = digitalRead(boton1);
  estado_btn2 = digitalRead(boton2);

  // Si el primer botón es presionado, incrementamos la velocidad
  if (estado_btn1 == HIGH) {
    delay_time += 30;  // Aumentar el delay en 50 ms
    index++;
    if (index >= 5) {  // Si el arreglo llega a su límite (tamaño 5), lo reiniciamos
      index = 0;
    }
    delays[index] = delay_time;  // Guardamos el nuevo valor
    delay(100);  // Delay para evitar múltiples incrementos en una sola pulsación
  }

  // Si el segundo botón es presionado, incrementamos la velocidad
  if (estado_btn2 == HIGH) {
    delay_time += 30;  // Aumentar el delay en 50 ms
    index++;
    if (index >= 5) {  // Si el arreglo llega a su límite (tamaño 5), lo reiniciamos
      index = 0;
    }
    delays[index] = delay_time;  // Guardamos el nuevo valor
    delay(100);  // Delay para evitar múltiples incrementos en una sola pulsación
  }

  // Contar de 0 a 9 con LEDs y display
  for (int i = LED8; i <= LED17; i++) {
    digitalWrite(i, HIGH);
    int num = i - LED8; // Calcular el número a mostrar en el display
    mostrarNumero(num);  // Mostrar el número correspondiente en el display
    delay(delay_time);   // Esperar el tiempo de delay
    digitalWrite(i, LOW);
  }

  // Contar de 9 a 0 con LEDs y display
  for (int i = LED17; i >= LED8; i--) {
    digitalWrite(i, HIGH);
    int num = i - LED8; // Calcular el número a mostrar en el display
    mostrarNumero(9 - num);  // Mostrar el número correspondiente en el display (invertido)
    delay(delay_time);   // Esperar el tiempo de delay
    digitalWrite(i, LOW);
  }
}

void mostrarNumero(int num) {
  // Mostrar el número correspondiente en el display de 7 segmentos
  digitalWrite(A, numeros[num][0]);
  digitalWrite(B, numeros[num][1]);
  digitalWrite(C, numeros[num][2]);
  digitalWrite(D, numeros[num][3]);
  digitalWrite(E, numeros[num][4]);
  digitalWrite(F, numeros[num][5]);
  digitalWrite(G, numeros[num][6]);
}
