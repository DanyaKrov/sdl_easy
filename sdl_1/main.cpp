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
void swap(int &x, int &y) {
    int g = x;
    x = y;
    y = g;
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
    if (x1 > x2) {
        swap(x1, x2);
    }
    if (y1 > y2)
        swap(y1, y2);
    if (x1 == x2) {
        ver_line(x1, y1, y2 - y1, renderer);
    }
    else {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        int x, y, dx = x2 - x1, dy = y2 - y1;
        int d = (dy << 1) - dx, d1 = dy << 1, d2 = (dy - dx) << 1;
        x = x1, y = y1;
        SDL_RenderDrawPoint(renderer, x1, y1);
        SDL_RenderDrawPoint(renderer, x2, y2);
        x2--;
        while (x < x2)
        {
            x++;
            if (d < 0)
                d += d1;
            else
            {
                y++;
                d += d2;
            }
            SDL_RenderDrawPoint(renderer, x, y);
        }
        SDL_RenderPresent(renderer);
    }
}
void circle(SDL_Renderer* renderer, int x0, int y0, int radius) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
    int x = 0;
    int y = radius;
    int delta = 1 - 2 * radius;
    int error = 0;
    while (y >= 0) {
        SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
        SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);
        SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
        SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
        error = 2 * (delta + y) - 1;
        if (delta < 0 && error <= 0) {
            x++;
            delta += 2 * x + 1;
            continue;
        }
        error = 2 * (delta - x) - 1;
        if (delta > 0 && error > 0) {
            y--;
            delta += 1 - 2 * y;
            continue;
        }
        x++;
        delta += 2 * (x - y);
        y--;
    }
    SDL_RenderPresent(renderer);
}
int main(int argc, char** args) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool statement = true;
    window = SDL_CreateWindow("SDL_RenderClear", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    vector<int> vector1 = { 1, 2, 3, 4};
    //vert_Diagrm(vector1, SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h, renderer);
    //hor_Diagrm(vector1, SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h, renderer);
    circle(renderer, 100, 100, 10);
    while (statement) {
        continue;
    }
    SDL_Quit();
    return 0;
}
