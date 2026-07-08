*Seguidor de Luz com Raspberry Pi Pico*
    Este projeto é um sistema simples de rastreamento de luz. Ele utiliza um Raspberry Pi Pico (em C/C++) para controlar um servo motor com base na leitura de dois sensores de luminosidade (LDRs), apontando o motor para a direção com maior incidência de luz.
    O diferencial deste código é o uso de Interrupções de Tempo no lugar de atrasos (delays), deixando o microcontrolador livre para outras tarefas.

*Requisitos Atendidos*
    GPIO: Configuração de pinos de entrada e saída.

    A/D (ADC): Leitura analógica dos sensores LDR.

    PWM: Controle preciso do ângulo do servo motor.

    Temporizadores e Interrupções: Uso de repeating_timer para executar a leitura e controle a cada 20ms de forma paralela (em background).

| Componente | Pino Físico | GPIO (Pico) | Função |
| :--- | :--- | :--- | :--- |
| Servo Motor (Sinal) | Pino 6 | GPIO 4 | Saída PWM |
| LDR 1 (Esquerda) | Pino 32 | GPIO 27 | Entrada Analógica (ADC 1) |
| LDR 2 (Direita) | Pino 31 | GPIO 26 | Entrada Analógica (ADC 0) |

*Como Executar*
    Tenha o Pico C/C++ SDK configurado no seu ambiente.

    Compile o projeto utilizando o CMake:

    Bash
    mkdir build
    cd build
    cmake ..
    make
    Segure o botão BOOTSEL do Pico e conecte-o ao PC via USB.

    Arraste o arquivo .uf2 gerado na pasta build para a unidade do Raspberry Pi Pico.

    Abra seu monitor serial (115200 baud) para visualizar o monitoramento dos sensores em tempo real.

!!!!!!!!!!!!!!!!!!!LINKS IMPORTANTES!!!!!!!!!!!!!!!!!!!!!

Relatorio: https://drive.google.com/file/d/1XgWQ8Vu14frLvCi5SGztrrfGeWaRDj6L/view?usp=drive_link

Video: https://youtube.com/shorts/nifKgS6Jmfo?feature=share
