#include <stdint.h>
#include "stdbool.h"

/**
 * @brief Inicializa puerto y apaga todos los LEDs,
 *
 * @param direccion
 */
void LedsCreate(uint16_t * direccion);

/**
 * @brief Enciende el LED
 *
 * @param led
 */
void LedsSetOn(int led);

/**
 * @brief Apagael LED
 *
 * @param led
 */
void LedsSetOff(int led);

/**
 * @brief Verifica el estado del led
 *
 * @param led
 * @return int
 */
int EstadoLed(int led);

/**
 * @brief Verifica los limites de led
 *
 * @param led
 * @return true
 * @return false
 */
bool LedstoLimit(int led);
