#include <Arduino.h>
#include <SPI.h>
#include <GxEPD2.h>
#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMono9pt7b.h>
#define b1 10 // BOTON DE ENCENDIDO
#define b2 11 // BOTON DE MENU
#define ARRIBA 12
#define ABAJO 13
// Pines de pi pico
#define EPD_CS 17       //5
#define EPD_DC 8        //13
#define SRAM_CS -1
#define EPD_RESET 14    //9
#define EPD_BUSY 15     //7
#define EPD_SCLK 18
#define EPD_MISO 0
#define EPD_MOSI 19

int a = 0;

GxEPD2_BW<GxEPD2_290_GDEY029T94, GxEPD2_290_GDEY029T94::HEIGHT> display(
    GxEPD2_290_GDEY029T94(EPD_CS, EPD_DC, EPD_RESET, EPD_BUSY));

void setup()
{
    // Inicializa la comunicación serial
    Serial.begin(115200);
    Serial.println("Iniciando display ePaper...");

    SPI.begin();

    // Configura pines adicionales
    pinMode(EPD_DC, OUTPUT);
    pinMode(EPD_RESET, OUTPUT);
    pinMode(EPD_BUSY, INPUT);
    pinMode(b2, INPUT);
    pinMode(b1, INPUT);
    pinMode(ARRIBA, INPUT);
    pinMode(ABAJO, INPUT);

    // Inicializa la pantalla
    display.init();

    display.setRotation(3); // Ajusta la rotación
    display.setTextColor(GxEPD_BLACK); // Selecciona el color de fuente
    display.setFont(&FreeMonoBold9pt7b); // Selecciona la fuente
    display.setFullWindow(); // Configuracion para utilizar la pantalla
    display.fillScreen(GxEPD_WHITE); // Limpia la pantalla
    display.setTextSize(1); // Selecciona el tamaño de fuente
    display.setCursor(10, 10);
    display.print("Fecha");
    display.setCursor(200, 10);
    display.print("Bateria");
    display.setCursor(110, 65);
    display.print("Inicio");
    display.display(false); // full update
    delay(2000);
    a = 1;
}

void loop()
{
    switch (a)
    {
    case 1:
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Precalentar");
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        display.setCursor(90, 65);
        display.print("Precalentar");
        display.display(false);
        delay(2000);
        a = 2;
        break;
    case 2:
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Control del aparato");
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        display.setCursor(80, 60);
        display.print("Control del");
        display.setCursor(100, 80);
        display.print("aparato");
        display.display(false);
        delay(2000);
        a = 3;
        break;
    case 3:
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Buen funcionamiento verificado");
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        display.setCursor(125, 50);
        display.print("Buen");
        display.setCursor(70, 70);
        display.print("funcionamiento");
        display.setCursor(95, 90);
        display.print("verificado");
        display.display(false);
        delay(2000);
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Listo");
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        display.setCursor(115, 65);
        display.print("Listo");
        display.setCursor(10, 120);
        display.print("menu");
        display.setCursor(200, 120);
        display.print("medicion");
        display.display(false);
        delay(100);
        a = 4;
        break;
    case 4:
        // Inicia la medicion
        if (digitalRead(b1) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            Serial.println("Control de cero");
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            display.setCursor(90, 60);
            display.print("Control de");
            display.setCursor(125, 80);
            display.print("cero");
            display.display(false);
            delay(2000);
            a = 5;
        }
        // Entra al menú
        if (digitalRead(b2) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            Serial.println("Apagar");
            display.setCursor(40, 60);
            display.print("-Apagar <<");
            Serial.println("Historial");
            display.setCursor(40, 80);
            display.print("-Historial");
            display.setCursor(10, 120);
            display.print("atras");
            display.setCursor(210, 120);
            display.print("aceptar");
            display.display(false);
            delay(100);
            a = 13;
        }
        break;
    case 5:
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Cero =");
        Serial.println("0.00 g/L");
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        display.setCursor(110, 60);
        display.print("Cero =");
        display.setCursor(100, 80);
        display.print("0.00 g/L");
        display.display(false);
        delay(2000);
        a = 6;
        break;
    case 6:
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Soplar");
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        display.setCursor(110, 65);
        display.print("Soplar");
        display.display(false);
        delay(6000);
        a = 7;
        break;
    case 7:
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Medición g/L");
        Serial.println("Nº de registro");
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        display.setCursor(80, 60);
        display.print("Medicion g/L");
        display.setCursor(77, 120);
        display.print("N de registro");
        display.display(false);
        delay(3000);
        a = 8;
        break;
    case 8:
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Imprimiendo");
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        display.setCursor(80, 65);
        display.print("Imprimiendo");
        display.display(false);
        delay(2000);
        a = 9;
        break;
    case 9:
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Listo");
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        display.setCursor(115, 65);
        display.print("Listo");
        display.setCursor(10, 120);
        display.print("menu");
        display.setCursor(200, 120);
        display.print("medicion");
        display.display(false);
        delay(100);
        a = 4;
        break;
    case 10:
        display.fillScreen(GxEPD_WHITE);
        Serial.println("Error de funcionamiento");
        display.setCursor(100, 60);
        display.print("Error de");
        display.setCursor(70, 80);
        display.print("funcionamiento");
        display.display(false);
        break;
    case 11:
        if (digitalRead(b1) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            Serial.println("Imprimiendo");
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            display.setCursor(80, 65);
            display.print("Imprimiendo");
            display.display(false);
            delay(2000);
            a = 12;
        }
        if (digitalRead(b2) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            Serial.println("Apagar");
            display.setCursor(40, 60);
            display.print("-Apagar <<");
            Serial.println("Historial");
            display.setCursor(40, 80);
            display.print("-Historial");
            display.setCursor(10, 120);
            display.print("atras");
            display.setCursor(210, 120);
            display.print("aceptar");
            display.display(false);
            delay(100);
            a = 13;
        }
        break;
    case 12:
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(115, 65);
        display.print("Listo");
        delay(1500);
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(10, 10);
        display.print("Fecha");
        display.setCursor(200, 10);
        display.print("Bateria");
        Serial.println("Apagar");
        display.setCursor(40, 60);
        display.print("-Apagar <<");
        Serial.println("Historial");
        display.setCursor(40, 80);
        display.print("-Historial");
        display.setCursor(10, 120);
        display.print("atras");
        display.setCursor(210, 120);
        display.print("aceptar");
        display.display(false);
        delay(100);
        a = 13;
        break;
    case 13:
        if (digitalRead(b1) == HIGH)
        {
            display.fillScreen(GxEPD_BLACK);
            display.display(false);
        }
        if (digitalRead(b2) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            Serial.println("Listo");
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            display.setCursor(115, 65);
            display.print("Listo");
            display.setCursor(10, 120);
            display.print("menu");
            display.setCursor(200, 120);
            display.print("medicion");
            display.display(false);
            delay(100);
            a = 4;
        }
        if (digitalRead(ABAJO) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            Serial.println("Apagar");
            display.setCursor(40, 60);
            display.print("-Apagar");
            Serial.println("Historial");
            display.setCursor(40, 80);
            display.print("-Historial <<");
            display.setCursor(10, 120);
            display.print("atras");
            display.setCursor(210, 120);
            display.print("aceptar");
            display.display(false);
            delay(100);
            a = 14;
        }
        if (digitalRead(ARRIBA) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            Serial.println("Apagar");
            display.setCursor(40, 60);
            display.print("-Apagar");
            Serial.println("Historial");
            display.setCursor(40, 80);
            display.print("-Historial <<");
            display.setCursor(10, 120);
            display.print("atras");
            display.setCursor(210, 120);
            display.print("aceptar");
            display.display(false);
            delay(100);
            a = 14;
        }
        break;
    case 14:
        if (digitalRead(b1) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            Serial.println("Medicion");
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            display.setCursor(40, 50);
            display.print("Registro N:");
            display.setCursor(90, 80);
            display.print("Medicion");
            display.setCursor(10, 120);
            display.print("atras");
            display.setCursor(200, 120);
            display.print("imprimir");
            display.display(false);
            delay(100);
            a = 11;
        }
        if (digitalRead(b2) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            Serial.println("Listo");
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            display.setCursor(115, 65);
            display.print("Listo");
            display.setCursor(10, 120);
            display.print("menu");
            display.setCursor(200, 120);
            display.print("medicion");
            display.display(false);
            delay(100);
            a = 4;
        }
        if (digitalRead(ARRIBA) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            Serial.println("Apagar");
            display.setCursor(40, 60);
            display.print("-Apagar <<");
            Serial.println("Historial");
            display.setCursor(40, 80);
            display.print("-Historial");
            display.setCursor(10, 120);
            display.print("atras");
            display.setCursor(210, 120);
            display.print("aceptar");
            display.display(false);
            delay(100);
            a = 13;
        }
        if (digitalRead(ABAJO) == HIGH)
        {
            display.fillScreen(GxEPD_WHITE);
            display.setCursor(10, 10);
            display.print("Fecha");
            display.setCursor(200, 10);
            display.print("Bateria");
            Serial.println("Apagar");
            display.setCursor(40, 60);
            display.print("-Apagar <<");
            Serial.println("Historial");
            display.setCursor(40, 80);
            display.print("-Historial");
            display.setCursor(10, 120);
            display.print("atras");
            display.setCursor(210, 120);
            display.print("aceptar");
            display.display(false);
            delay(100);
            a = 13;
        }
        break;
    }
}