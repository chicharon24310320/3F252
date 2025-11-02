#pragma once
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include "Dibujo.hpp"

class Letrero {
public:
    int x, y;
    Dibujo dibujo_letrero;
    bool color_alterno = false; // para animar el parpadeo

    Letrero(int x, int y, ftxui::Color color_inicial = ftxui::Color::White)
        : x(x), y(y),
          dibujo_letrero(x, y, GenerarFiguraCartel(), color_inicial) {}

    // Figura ASCII del cartel
    static std::vector<std::u32string> GenerarFiguraCartel() {
        return {
            U"    ____  _   _ _____ _   _",       
        U"    | __ )| | | | ____| \\ | |",     
        U"    |  _ \\| | | |  _| |  \\| | ",     
        U"    | |_) | |_| | |___| |\\  |  ",     
        U"    |____/ \\___/|_____|_| \\_| _____ ",
        U"    \\ \\   / /_ _|  / \\     | | ____|",
        U"     \\ \\ / / | |  / _ \\ _  | |  _|  ",
        U"      \\ V /  | | / ___\\ |_| | |___ ",
        U"       \\_/  |___/_/   \\_\\___/|_____|",
        };
    }

    // Alterna entre blanco y rojo
    void ActualizarColor() {
        color_alterno = !color_alterno;
        dibujo_letrero.color = color_alterno ? ftxui::Color::Red : ftxui::Color::White;
    }

    void Dibujar(ftxui::Screen& screen) const {
        dibujo_letrero.Dibujar(screen);
    }
};
