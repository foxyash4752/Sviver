#ifndef KEYBOARD_H // Подключаем нашу библиотеку KEYBOARD_H
#define KEYBOARD_H // Подключаем нашу библиотеку KEYBOARD_H

void keyboard_init(void); // Вызываем функцию keyboard_init с пустотой
int keyboard_has_input(void); // Вызываем функцию keyboard_has_input
char keyboard_get_char(void); // Вызываем функцию keyboard_get_char

#endif // Закрываем неопределённый конец логического if