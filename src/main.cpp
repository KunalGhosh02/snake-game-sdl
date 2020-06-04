#include <iostream>

#include "controller.h"
#include "game.h"
#include "renderer.h"

int main(int argc, const char **argv) {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

  // For taking user input for custom maps
    std::string map_file_path = "";
    if (argc > 1) {
        for (int i = 1; i < argc; ++i)
            if (std::string_view{argv[i]} == "-m" && ++i < argc)
                map_file_path = argv[i];

    } else {
        std::cout << "To specify a map file use the following format: " << std::endl;
        std::cout << "Usage: [executable] [-m path_to_map.map]" << std::endl;
        map_file_path = "../maps/map2.map";
    }

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight, map_file_path);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    return 0;
}