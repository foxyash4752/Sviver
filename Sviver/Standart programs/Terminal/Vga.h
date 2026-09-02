#ifndef VGA_H // Подключаем защиту от двойного включения
#define VGA_H // Подключаем определение VGA_H
#define VGA_WIDTH 80 // Подключаем макрос замены VGA_WIDTH 80
#define VGA_HEIGHT 25 // Подключаем макрос замены VGA_HEIGHT 25

enum VgaColor { // Создаём перечисление VgaColor
    COLOR_BLACK = 0, // Создаём переменную COLOR_BLACK = 0
    COLOR_BLUE = 1, // Создаём переменную COLOR_BLUE = 1
    COLOR_GREEN = 2, // Создаём переменную COLOR_GREEN = 2
    COLOR_CYAN = 3, // Создаём переменную COLOR_CYAN = 3
    COLOR_RED = 4, // Создаём переменную COLOR_RED = 4
    COLOR_MAGENTA = 5, // Создаём переменную COLOR_MAGENTA = 5
    COLOR_BROWN = 6, // Создаём переменную COLOR_BROWN = 6
    COLOR_LIGHT_GREY = 7, // Создаём переменную COLOR_LIGHT_GREY = 7
    COLOR_DARK_GREY = 8, // Создаём переменное COLOR_DARK_GREY = 8
    COLOR_LIGHT_BLUE = 9, // Создаём переменную COLOR_LIGHT_BLUE = 9
    COLOR_LIGHT_GREEN = 10, // Создаём переменную COLOR_LIGHT_GREEN = 10
    COLOR_LIGHT_CYAN = 11, // Создаём переменную COLOR_LIGHT_CYAN = 11
    COLOR_LIGHT_RED = 12, // Создаём переменную COLOR_LIGHT_RED = 12
    COLOR_LIGHT_MAGENTA = 13, // Создаём переменную COLOR_LIGHT_MAGENTA = 13
    COLOR_YELLOW = 14, // Создаём переменную COLOR_YELLOW = 14
    COLOR_WHITE = 15 // Создаём переменную COLOR_WHITE = 15
}; // Закрываем перечисление VgaColor

void vga_init(void); // Вызываем функцию vga_init с пустотой
void vga_clear(void); // Вызываем функцию vga_clear с пустотой
void vga_set_color(enum VgaColor fg, enum VgaColor bg); // Вызываем функцию vga_set_color с формулой
void vga_put_char(char c); // Вызываем функцию vga_put_char с формулой
void vga_print(const char* text); // Вызываем функцию vga_print с формулой
void vga_backspace(void); // Вызываем функцию vga_backspace с пустотой

#endif // Закрываем неопределённый конец логического if