#include "unity.h"
#include "leds.h"

/** @todo
Prender un LED individual.
Apagar un LED individual.
Prender y apagar múltiples LED’s.
Prender todos los LEDs de una vez.
Apagar todos los LEDs de una vez.
Consultar el estado de un LED que está encendido
Consultar el estado de un LED que est apagado
Revisar limites de los parametros.
Revisar parámetros fuera de los limites.
*/
// se ejecuya antes de cada prueba

static uint16_t puerto_virtual_leds;
static uint16_t estado_leds;

// Se ejecuta antes de cada prueba.
void setUp(void) {

    LedsCreate(&puerto_virtual_leds);
}

// se ejecuta despue de cada prueba
void tearDown(void) {
}

// Inicializamos los LEDs, quedan apagados
void test_todos_los_leds_inician_apagados(void) {

    uint16_t puerto_virtual_leds = 0xFFFF;

    LedsCreate(&puerto_virtual_leds);

    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual_leds);
}

// Prender un led Individual
void test_prender_un_led_individual(void) {

    LedsSetOn(6);
    TEST_ASSERT_EQUAL_HEX16(1 << 5, puerto_virtual_leds);
}

// Prender un led Individual
void test_apagar_y_apagar_un_led_individual(void) {

    LedsSetOn(6);
    LedsSetOff(6);
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual_leds);
}

// Test prender y apagar varios leds
void test_prender_y_apagar_varios_led_(void) {

    LedsSetOn(5);
    LedsSetOff(2);
    LedsSetOn(7);
    LedsSetOff(7);
    LedsSetOn(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual_leds);
}

// verifica el estado del led encendidio
void test_estado_led_encendido(void) {
    LedsSetOn(5);
    LedsSetOff(7);
    TEST_ASSERT_EQUAL_HEX16(1, EstadoLed(5));
}

// verifica el estado del led apagado
void test_estado_led_apagado(void) {
    LedsSetOn(5);
    LedsSetOff(7);
    LedsSetOff(9);
    LedsSetOff(10);
    TEST_ASSERT_EQUAL_HEX16(0, EstadoLed(7));

    // TEST_ASSERT_FALSE(EstadoLed(7));
}

// Consulta  LED por fuera de los limites
void test_leds_fuera_de_los_limites(void) {
    TEST_ASSERT_FALSE(LedstoLimit(20));
    TEST_ASSERT_FALSE(LedstoLimit(0));
}

// Consulta limites de parametros LED
void test_leds_dentro_de_los_limites(void) {
    TEST_ASSERT_TRUE(LedstoLimit(1));
    TEST_ASSERT_TRUE(LedstoLimit(16));
}
