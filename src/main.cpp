#include <iostream>
#include "gui/gui_window.h"

int main(int argc, char** argv) {
    // Initialize the GUI application
    GuiWindow gui;

    // Open the main window
    gui.open();

    // Main application loop
    while (gui.isRunning()) {
        gui.processEvents();
    }

    return 0;
}