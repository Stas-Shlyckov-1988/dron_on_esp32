// библиотека для работы с HTTP-протоколом
#include <HTTPClient.h>
// вводим имя и пароль точки доступа
const char* ssid = "MTS874FT_7B2B";
const char* password = "00023879";

const int LED2 = 2;
const int LED4 = 4;
 
void setup() {
    pinMode(LED2, OUTPUT);
    pinMode(LED4, OUTPUT);
    // иницилизируем монитор порта
    Serial.begin(115200);
    // запас времени на открытие монитора порта — 5 секунд
    delay(5000);
    // подключаемся к Wi-Fi сети
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to Wi-Fi..");
    }
    Serial.println("Connected to the Wi-Fi network");
}
 
void loop() {
    
    // выполняем проверку подключения к беспроводной сети
    if ((WiFi.status() == WL_CONNECTED)) {
        // создаем объект для работы с HTTP
        HTTPClient http;
        // подключаемся к тестовому серверу с помощью HTTP
        http.begin("http://192.168.1.103:8080/?CODE=1");
        // делаем GET запрос
        int httpCode = http.GET();
        // проверяем успешность запроса
        if (httpCode > 0) {
            // выводим ответ сервера
            String payload = http.getString();
            //Serial.println(httpCode);
            Serial.println(payload);
            if (payload == "11") {
              digitalWrite(LED2, HIGH);
              digitalWrite(LED4, HIGH);
            }
            else if(payload == "01") {
              digitalWrite(LED2, LOW);
              digitalWrite(LED4, HIGH);
            }
            else if(payload == "10") {
              digitalWrite(LED2, HIGH);
              digitalWrite(LED4, LOW);
            }
            else {
              digitalWrite(LED2, LOW);
              digitalWrite(LED4, LOW);
            }
        }
        else {
            Serial.println("Error on HTTP request");
        }
        // освобождаем ресурсы микроконтроллера
        http.end();
    }
    delay(1000);
}