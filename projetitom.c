#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"
#include "pico/time.h" // Necessário para usar os temporizadores

const uint pinoServo = 4;
const uint pinoLDR1 = 27; // ADC1
const uint pinoLDR2 = 26; // ADC0

uint slice_num;
uint chan;
int mover = 90; // Ângulo inicial do motor

// Função para mapear valores proporcionais
long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


bool repeticao_timer_callback(struct repeating_timer *t) {
    // Leitura A/D do LDR1
    adc_select_input(1); 
    uint16_t R1 = adc_read();

    // Leitura A/D do LDR2
    adc_select_input(0); 
    uint16_t R2 = adc_read();

    int diferenca = R1 - R2;
    
    // Lógica de movimentação baseada na diferença de luz
    if (diferenca < -50) { 
        if (mover > 0) {
            mover -= 1;
        }
    } else if (diferenca > 50) { 
        if (mover < 180) {
            mover += 1;
        }
    }

    // Expandimos a escala: 0.5ms (976) até 2.5ms (4882)
    uint32_t duty = map(mover, 0, 180, 976, 4882);
    
    // Monitoramento no console
    printf("LDR1: %-4d | LDR2: %-4d | Dif: %-5d | Angulo: %-3d | PWM: %lu\n", 
           R1, R2, diferenca, mover, duty);
    
    // Atualiza o PWM do servo motor
    pwm_set_chan_level(slice_num, chan, duty);

    
    return true; 
}

int main() {
    stdio_init_all();
    

    adc_init();
    adc_gpio_init(pinoLDR1);
    adc_gpio_init(pinoLDR2);

    gpio_set_function(pinoServo, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(pinoServo);
    chan = pwm_gpio_to_channel(pinoServo);

    pwm_set_clkdiv(slice_num, 64.0f);
    pwm_set_wrap(slice_num, 39062);
    pwm_set_enabled(slice_num, true);

    struct repeating_timer timer;
    
    
    add_repeating_timer_ms(20, repeticao_timer_callback, NULL, &timer);


    while (1) {
        
        tight_loop_contents(); 
    }
    
    return 0;
}