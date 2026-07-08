# Generated Cmake Pico project file
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

# Define a placa alvo (Pico 2)
set(PICO_BOARD pico2 CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(projetitom C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Define o nome do executável e vincula ao seu arquivo fonte principal (projetitom.c)
add_executable(projetitom projetitom.c)

pico_set_program_name(projetitom "projetitom")
pico_set_program_version(projetitom "0.1")

# Habilita a saída via cabo USB para visualizarmos os dados do printf no Monitor Serial
pico_enable_stdio_uart(projetitom 0)
pico_enable_stdio_usb(projetitom 1)

# LIGA AS BIBLIOTECAS: Inclui o padrão (que já traz os temporizadores), o PWM (motor) e ADC (sensores LDR)
target_link_libraries(projetitom pico_stdlib hardware_pwm hardware_adc)

# Add the standard include files to the build
target_include_directories(projetitom PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(projetitom)