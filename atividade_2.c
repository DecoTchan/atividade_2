#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definições de GPIO
#define LED_B 11  // Azul
#define LED_R 12  // Vermelho
#define LED_G 13  // Verde
#define BUTTON 5  // Botão

// Estado do sistema
volatile bool button_pressed = false;

// Callback do temporizador de um disparo
bool one_shot_callback(struct repeating_timer *t) {
    static int step = 0;
    switch (step) {
        case 0:
            gpio_put(LED_B, 1); gpio_put(LED_R, 1); gpio_put(LED_G, 1);
            step++;
            add_alarm_in_ms(3000, one_shot_callback, NULL, false);
            break;
        case 1:
            gpio_put(LED_B, 0);
            step++;
            add_alarm_in_ms(3000, one_shot_callback, NULL, false);
            break;
        case 2:
            gpio_put(LED_R, 0);
            step++;
            add_alarm_in_ms(3000, one_shot_callback, NULL, false);
            break;
        case 3:
            gpio_put(LED_G, 0);
            step = 0;
            button_pressed = false;
            break;
    }
    return true;
}

// Tratamento do botão
void gpio_callback(uint gpio, uint32_t events) {
    if (gpio == BUTTON && events == GPIO_IRQ_EDGE_FALL && !button_pressed) {
        button_pressed = true;
        add_alarm_in_ms(0, one_shot_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED_B); gpio_set_dir(LED_B, GPIO_OUT);
    gpio_init(LED_R); gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_G); gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(BUTTON); gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (1) {
        printf("Sistema aguardando acionamento do botão...\n");
        sleep_ms(1000);
    }
}