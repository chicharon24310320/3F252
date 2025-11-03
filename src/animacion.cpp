#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "Dibujo.hpp"
#include "GestorDibujos.hpp"
#include "Letrero.hpp"  
using namespace ftxui;

int main() {

    auto screen = Screen::Create(Dimension::Fixed(80), Dimension::Fixed(24));


    const std::vector<std::u32string> cohete = {
        U"     ^     ",
        U"    /^\\    ",
        U"   /___\\   ",
        U"  |  o  |  ",
        U"  |     |  ",
        U"  |     |  ",
        U"  |_____|  ",
        U"   /   \\   ",
        U"  /_____\\  "
    };

    const std::vector<std::u32string> fuego1 = {
        U"    ***    ",
        U"   *****   ",
        U"    ***    "
    };

    const std::vector<std::u32string> fuego2 = {
        U"     *     ",
        U"   *****   ",
        U"  *******  ",
        U"   *****   ",
        U"     *     "
    };

    const std::vector<std::u32string> estrellas = {
        U"    *     *       *        *   *  ",
        U"  *     *    *        *         * ",
        U"        *         *      *        ",
    };

  
    const std::vector<std::u32string> persona1 = {
        U"  \\\\O//  ",
        U"    |    ",
        U"   / \\\\   "
    };

    const std::vector<std::u32string> persona2 = {
        U"   _O_   ",
        U"    |    ",
        U"   / \\\\   "
    };

    // ===== GESTOR DE DIBUJOS =====
    GestorDibujos gestor;
    gestor.Agregar(Dibujo(20, 2, estrellas, ftxui::Color::Yellow));    // 0: fondo
    gestor.Agregar(Dibujo(35, 10, cohete, ftxui::Color::White));       // 1: cohete
    gestor.Agregar(Dibujo(35, 20, fuego1, ftxui::Color::Red));         // 2: fuego
    gestor.Agregar(Dibujo(5, 18, persona1, ftxui::Color::GreenLight)); // 3: persona


    Letrero letrero(3, 2, ftxui::Color::White);


    int frames = 120;

    std::cout << "\033[2J\033[1;1H";

    for (int frame = 0; frame < frames; ++frame) {
        screen.Clear();

        // Movimiento del cohete hacia arriba
        int desplazamiento = frame / 2;
        gestor.dibujos[1].y = 10 - desplazamiento; // cohete
        gestor.dibujos[2].y = 20 - desplazamiento; // fuego (sigue al cohete)

    
        if (frame % 4 < 2)
            gestor.dibujos[2].figura = fuego1;
        else
            gestor.dibujos[2].figura = fuego2;

        // Persona moviendo brazos
        if (frame % 6 < 3)
            gestor.dibujos[3].figura = persona1;
        else
            gestor.dibujos[3].figura = persona2;

        // Parpadeo del letrero (rojo/blanco)
        if (frame % 6 == 0)
            letrero.ActualizarColor();

 
        gestor.DibujarTodos(screen);
        letrero.Dibujar(screen);

      
        std::cout << screen.ToString()
                  << screen.ResetPosition()
                  << std::flush;

  
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
