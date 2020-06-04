#include "map.h"

#include <fstream>
#include <iostream>
#include <sstream>
void Map::LoadMap() {
    // std::ifstream filestream{_filepath};
    // std::ofstream file("file.save");
    // for (size_t i = 0; i < 32; i++) {
    //     file << "\n";
    //     for (size_t j = 0; j < 32; j++) {
    //         map_array[i][j] = array_temp_map[i][j];
    //         file << map_array[i][j] << " ";
    //     }
    // }
    std::string line, cell_value;
    SDL_Point point;
    std::ifstream map{"../maps/file.save"};
    if (map.is_open()) {
        for (size_t ii = 0; ii < 32; ii++) {
            getline(map, line);
            std::istringstream linestream(line);
            for (size_t jj = 0; jj < 32; jj++) {
                linestream >> cell_value;
                if (std::stoi(cell_value) == 1) {
                    point.x = jj;
                    point.y = ii;
                    _map.push_back(point);
                }
            }
        }
    }
}

void Map::RenderMap(SDL_Renderer* sdl_renderer, int grid_width, int grid_height, SDL_Rect* block) {
    int state_of_block = 0;
    SDL_SetRenderDrawColor(sdl_renderer, 221, 221, 221, 1);
    // for (size_t i = 0; i < grid_width; i++) {
    //     for (size_t j = 0; j < grid_height; j++) {
    //         if (map_array[j][i] == 1) {
    //             block->x = i * block->w;
    //             block->y = j * block->h;
    //             SDL_RenderFillRect(sdl_renderer, block);
    //         }
    //     }
    // }
    for (auto const& points : _map) {
        block->x = points.x * block->w;
        block->y = points.y * block->h;
        SDL_RenderFillRect(sdl_renderer, block);
    }
}

bool Map::MapCell(int x, int y) {
    for (auto const& points : _map) {
        if (points.x == x && points.y == y)
            return true;
    }
    return false;
}
