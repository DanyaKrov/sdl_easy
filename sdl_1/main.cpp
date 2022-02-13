#include <iostream> 
#include <SDL.h> 
#include <vector> 

using namespace std;


long long sum(vector<int>vector1) {
    long long num = 0;
    for (int i = 0; i < vector1.size(); i++) 
        num += vector1[i];
    return num;
}
void hor_line(int x, int y, int length, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    for (int i = x; i < x + length; i++)
        SDL_RenderDrawPoint(renderer, i, y);
    SDL_RenderPresent(renderer);
}
void ver_line(int x, int y, int length, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    if (length < 0) {
        for (int i = y; i > y + length; i--)
            SDL_RenderDrawPoint(renderer, x, i);
    }
    else {
        for (int i = y; i < y + length; i++)
            SDL_RenderDrawPoint(renderer, x, i);
    }
    SDL_RenderPresent(renderer);
}
void rec(int x, int y, int x_len, int y_len, SDL_Renderer* renderer) {
    hor_line(x, y, x_len, renderer);
    hor_line(x, y + y_len, x_len, renderer);
    ver_line(x, y, y_len, renderer);
    ver_line(x + x_len, y, y_len, renderer);
}
void vert_Diagrm(vector<int> vector1, int x, int y, SDL_Renderer* renderer) {
    for (int i = 0; i < vector1.size(); i++) {
        rec(x / 7 + (x * 5 / 7 / vector1.size()) * i, y * 5 / 6, x * 5 / 14 / vector1.size(), y * 2 / 3 * vector1[i] / sum(vector1) * -1, renderer);
    }
}
void hor_Diagrm(vector<int> vector1, int x, int y, SDL_Renderer* renderer) {
    for (int i = 0; i < vector1.size(); i++) {
        rec(x / 6, y / 7 + (y * 5 / 7 / vector1.size()) * i, x * 2 / 3 * vector1[i] / sum(vector1), y * 5 / 14 / vector1.size(), renderer);
    }
}
void line(int x1, int y1, int x2, int y2, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    int dx = x2 - x1;
    bool statement_x = true;
    if (dx < 0)
        statement_x = false;
    bool statement_y;
    int dy = y2 - y1;
    float k = dy / dx;
    int x = x1;
    int y = y1;
    while (x < x2) {
        SDL_RenderDrawPoint(renderer, x, y);
        if (!statement_x)
            x--;
        else
            x++;
        y += int(k);
    }
    SDL_RenderPresent(renderer);
}
int main(int argc, char** args) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool statement = true;
    window = SDL_CreateWindow("SDL_RenderClear", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    vector<int> vector1 = { 1, 2, 3, 4};
    //vert_Diagrm(vector1, SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h, renderer);
    //hor_Diagrm(vector1, SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h, renderer);
    line(200, 200, 800, 800, renderer);
    line(350, 200, 650, 800, renderer);
    ver_line(500, 200, 600, renderer);
    hor_line(200, 500, 600, renderer);
    line(650, 200, 350, 800, renderer);
    line(200, 800, 800, 200, renderer);
    while (statement) {
        continue;
    }
    SDL_Quit();
    return 0;
}
