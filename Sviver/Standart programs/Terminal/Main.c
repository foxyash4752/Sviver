#include "Vga.h"
#include "Keyboard.h"

void terminal_main(void) {
    // Пока заглушка. Будет вызываться при execute "terminal"
    vga_init();
    keyboard_init();
    vga_print("Sviver Terminal ready.\n");
}