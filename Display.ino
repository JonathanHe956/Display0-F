// Entradas de los dipswitch
int w = 0; // Entrada dipswitch1
int x = 0; // Entrada dipswitch2
int y = 0; // Entrada dipswitch3
int z = 0; // Entrada dipswitch4

// Función para encender los segmentos del display
void encender(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(2, a);  // Segmento 'a'
  digitalWrite(3, b);  // Segmento 'b'
  digitalWrite(4, c);  // Segmento 'c'
  digitalWrite(5, d);  // Segmento 'd'
  digitalWrite(6, e);  // Segmento 'e'
  digitalWrite(7, f);  // Segmento 'f'
  digitalWrite(8, g);  // Segmento 'g'
}

// Inicializar pines
void setup() {
  // Configurar pines de salida para el display
  for (int pin = 2; pin <= 8; pin++) {
    pinMode(pin, OUTPUT);
  }
  
  // Configurar pines de entrada para los dipswitches
  for (int pin = 9; pin <= 12; pin++) {
    pinMode(pin, INPUT);
  }
}

// Función para mostrar un número en el display
void mostrarNumero(int numero) {
  switch (numero) {
    case 0: encender(1, 1, 1, 0, 1, 1, 1); break; // Muestra 0
    case 1: encender(0, 0, 1, 0, 0, 0, 1); break; // Muestra 1
    case 2: encender(1, 1, 0, 1, 0, 1, 1); break; // Muestra 2
    case 3: encender(0, 1, 1, 1, 0, 1, 1); break; // Muestra 3
    case 4: encender(0, 0, 1, 1, 1, 0, 1); break; // Muestra 4
    case 5: encender(0, 1, 1, 1, 1, 1, 0); break; // Muestra 5
    case 6: encender(1, 1, 1, 1, 1, 1, 0); break; // Muestra 6
    case 7: encender(0, 0, 1, 0, 1, 1, 1); break; // Muestra 7
    case 8: encender(1, 1, 1, 1, 1, 1, 1); break; // Muestra 8
    case 9: encender(0, 1, 1, 1, 1, 1, 1); break; // Muestra 9
    case 10: encender(1, 0, 1, 1, 1, 1, 1); break; // Muestra 10 (A)
    case 11: encender(1, 1, 1, 1, 1, 0, 0); break; // Muestra 11 (B)
    case 12: encender(1, 1, 0, 0, 1, 1, 0); break; // Muestra 12 (C)
    case 13: encender(1, 1, 1, 1, 0, 0, 1); break; // Muestra 13 (D)
    case 14: encender(1, 1, 0, 1, 1, 1, 0); break; // Muestra 14 (E)
    case 15: encender(1, 0, 0, 1, 1, 1, 0); break; // Muestra 15 (F)
    default: encender(0, 0, 0, 0, 0, 0, 0); break; // Apagar display si no hay coincidencia
  }
}

// Loop principal
void loop() {
  // Leer los estados de los dipswitches
  w = digitalRead(9);
  x = digitalRead(10);
  y = digitalRead (11);
  z = digitalRead(12);

  // Determinar el número a mostrar en el display basado en las combinaciones de dipswitch
  int numero = 0;

  if (!w && !x && !y && !z) {
    numero = 0;
  } else if (w && !x && !y && !z) {
    numero = 1;
  } else if (!w && x && !y && !z) {
    numero = 2;
  } else if (w && x && !y && !z) {
    numero = 3;
  } else if (!w && !x && y && !z) {
    numero = 4;
  } else if (w && !x && y && !z) {
    numero = 5;
  } else if (!w && x && y && !z) {
    numero = 6;
  } else if (w && x && y && !z) {
    numero = 7;
  } else if (!w && !x && !y && z) {
    numero = 8;
  } else if (w && !x && !y && z) {
    numero = 9;
  } else if (!w && x && !y && z) {
    numero = 10;
  } else if (w && x && !y && z) {
    numero = 11;
  } else if (!w && !x && y && z) {
    numero = 12;
  } else if (w && !x && y && z) {
    numero = 13;
  } else if (!w && x && y && z) {
    numero = 14;
  } else if (w && x && y && z) {
    numero = 15;
  }

  // Mostrar el número en el display
  mostrarNumero(numero);
}