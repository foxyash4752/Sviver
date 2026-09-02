#include "Vga.h" // Подключаем нашу библиотеку Vga.h
#include <stdint.h> // Подключаем библиотеку stdint.h
#include <stddef.h> // Подключаем библиоткеу stddef.h

static void vga_scroll(void); // Вызываем скрытую, пустую функцию vga_scroll

static size_t terminal_row; // Создаём скрытую переменную с типом size_t и именем terminal_row и задаём строку
static size_t terminal_column; // Создаём скрытую переменную с типом size_t и именем terminal_column и задаём столбец
static uint8_t terminal_color; // Создаём скрытую переменную с типом uint8_t и именем terminal_color и задаём цвет
static uint16_t* terminal_buffer; // Создаём скрытую переменную с типом uint16_t* и именем terminal_buffer и задаём буфер

static inline uint8_t vga_entry_color(enum VgaColor fg, enum VgaColor bg) { // Создаём скрытую, встраиваемую функцию с типом uint8_t и именем vga_entry_color и возвращаем 1 байт
    return fg | bg << 4; // Возвращаем объединение цветов в один байт
} // Закрываем скрытую, встраиваемую функцию uint8_t

static inline uint16_t vga_entry(char c, uint8_t color) { // Создаём скрытую, встраиваемую функцию uint16_t и возвращаем 2 байта
    return (uint16_t)c | (uint16_t)color << 8; // Возвращаем объединение яйчейки памяти и вывода
} // Закрываем скрытую, встраиваемую функцию uint16_t

void vga_init(void) { // Создаём пустую функцию vga_init
    terminal_row = 0; // Создаём переменную terminal_row = 0
    terminal_column = 0; // Создаём переменную terminal_column = 0
    terminal_color = vga_entry_color(COLOR_LIGHT_GREY, COLOR_BLACK); // Создаём переменную terminal_color = функции vga_entry_color
    terminal_buffer = (uint16_t*)0xB8000; // Создаём переменную terminal_buffer = uint16_t*
    vga_clear(); // Вызываем функцию vga_clear
} // Закрываем пустую функцию vga_init

void vga_clear(void) { // Создаём пустую функцию vga_clear
    for (size_t y = 0; y < VGA_HEIGHT; y++) { // Создаём цикл for
        for (size_t x = 0; x < VGA_WIDTH; x++) { // Создаём цикл for
            size_t index = y * VGA_WIDTH + x; // Создаём переменную с типом size_t index = формуле
            terminal_buffer[index] = vga_entry(' ', terminal_color); // Создаём переменную terminal_buffer = формуле
        } // Закрываем цикл for
    } // Закрываем цикл for
    terminal_row = 0; // Создаём переменную terminal_row = 0
    terminal_column = 0; // Создаём переменную terminal_column = 0
} // Закрываем пустую функцию vga_clear

void vga_set_color(enum VgaColor fg, enum VgaColor bg) { // Создаём пустую функцию vga_set_color
    terminal_color = vga_entry_color(fg, bg); // Создаём переменную terminal_color = vga_entry_color
} // Закрываем пустую функцию vga_set_color

void vga_put_char(char c) { // Создаём пустую функцию vga_put_char
    if (c == '\n') { // Создаём логическое если
        terminal_column = 0; // Создаём переменную terminal_column = 0
        terminal_row++; // Создаём переменную terminal_row
        if (terminal_row >= VGA_HEIGHT) { // Создаём логическое если
            vga_scroll(); // Вызываем функцию vga_scroll
            terminal_row = VGA_HEIGHT - 1; // Создаём переменную terminal_row = формуле
        } // Закрываем логическое если
    } else { // Закрываем логическое если и создаём логическое иначе
        size_t index = terminal_row * VGA_WIDTH + terminal_column; // Создаём переменную с типом size_t index = формуле
        terminal_buffer[index] = vga_entry(c, terminal_color); // Создаём переменную terminal_buffer = функции vga_entry
        terminal_column++; // Создаём переменную terminal_column++
        if (terminal_column >= VGA_WIDTH) { // Создаём логическое если
            terminal_column = 0; // Создаём переменную terminal_column = 0
            terminal_row++; // Создаём переменную terminal_row++
            if (terminal_row >= VGA_HEIGHT) { // Создаём логическое если
                vga_scroll(); // Вызываем функцию vga_scroll
                terminal_row = VGA_HEIGHT - 1; // Создаём переменную terminal_row
            } // Закрываем логическое если
        } // Закрываем логическое если
    } // Закрываем логическое иначе
} // Закрываем пустую функцию vga_put_char

void vga_print(const char* text) { // Создаём пустую функцию vga_print
    for (size_t i = 0; text[i] != '\0'; i++) { // Создаём цикл for
        vga_put_char(text[i]); // Вызываем функцию vga_put_char
    } // Закрываем цикл for
} // Закрываем пустую функцию vga_print

void vga_scroll(void) { // Создаём пустую функцию vga_scroll
    for (size_t y = 1; y < VGA_HEIGHT; y++) { // Создаём цикл for
        for (size_t x = 0; x < VGA_WIDTH; x++) { // Создаём цикл for
            size_t src = y * VGA_WIDTH + x; // Создаём переменную с типом size_t src = формуле
            size_t dst = (y - 1) * VGA_WIDTH + x; // Создаём переменную с типом size_t dst = формуле
            terminal_buffer[dst] = terminal_buffer[src]; // Создаём переменную terminal_buffer = формуле
        } // Закрываем цикл for
    } // Закрываем цикл for
    for (size_t x = 0; x < VGA_WIDTH; x++) { // Создаём цикл for
        size_t index = (VGA_HEIGHT - 1) * VGA_WIDTH + x; // Создаём переменную с типом size_t index = формуле
        terminal_buffer[index] = vga_entry(' ', terminal_color); // Создаём переменную terminal_buffer = функции vga_entry
    } // Закрываем цикл for
} // Закрываем пустую функцию vga_scroll

void vga_backspace(void) { // Создаём пустую функцию vga_backspace
    if (terminal_column > 0) { // Создаём логический if
        terminal_column--; // Создаём переменную terminal_column
    } else if (terminal_row > 0) { // Создаём логический else if
        terminal_row--; // Создаём переменную terminal_row
        terminal_column = VGA_WIDTH - 1; // Создаём переменную terminal_column
    } else { // Создаём логический else
        return; // Возвращаем ничего
    } // Закрываем логический else
    size_t index = terminal_row * VGA_WIDTH + terminal_column; // Создаём переменную size_t index = формуле
    terminal_buffer[index] = vga_entry(' ', terminal_color); // Создаём переменную terminal_buffer = формуле
} // Закрываем функцию vga_backspace