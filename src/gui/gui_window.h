#pragma once

class GuiWindow {
public:
    GuiWindow();
    void open();
    bool isRunning();
    void processEvents();
};