#include <SDL.h>
#include <emscripten.h>
#include <stdlib.h>

#ifndef GameOfLife_h
#define GameOfLife_h

#include <string.h>

class GameOfLife
{
public:
    GameOfLife(int width, int height, int* values = nullptr);

    void evolve();
    void assignTempValue(int i, int j);
    int getCell(int x, int y);
    void setCell(int x, int y, int v);
    int* getCellValues() { return m_values; };

    int width();
    int height();
    int getIndex(int x, int y);

private: // helper functions
    // Evolve a cell, returning new cell value based on three rules of game of life
    // taking pre-evolve neighbor values into account.
    int evolveCell(int x, int y);

    int getNeighbors(int x, int y);

    bool isValid(int i, int j, int x, int y);

    int checkRules(int x, int y, int numNeighbors);
    bool checkRule1(bool cellIsAlive, int numNeighbors);
    bool checkRule2(bool cellIsAlive, int numNeighbors);

    bool isCellAlive(int x, int y);

private:
    int* m_values;
    int* m_tempValues;
    int m_width;
    int m_height;
};


GameOfLife::GameOfLife(int w, int h, int* values)
    : m_width(w)
    , m_height(h)
    , m_values()
{
    // let's assume values are correctly initialized to size of width * height for now.
    if (values != nullptr)
        m_values = values;

    m_tempValues = new int[w * h];
}

void GameOfLife::evolve()
{
    // evolve all cells
    for (int i = 0; i < width(); i++) {
        for (int j = 0; j < height(); j++) {
            assignTempValue(i, j);
        }
    }

    // memmove
    // TODO: might just swap the pointers
    /*for (int i = 0; i < width() * height(); i++) {
        m_values[i] = m_tempValues[i];
    }*/
    memmove(m_values, m_tempValues, sizeof(int) * width() * height());
}

void GameOfLife::assignTempValue(int i, int j)
{
    m_tempValues[getIndex(i, j)] = evolveCell(i, j);
}


int GameOfLife::evolveCell(int x, int y)
{
    int numNeighbors = getNeighbors(x, y);
    return checkRules(x, y, numNeighbors);
}

int GameOfLife::getNeighbors(int x, int y)
{
    int numNeighbors = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (isValid(i, j, x, y) && isCellAlive(i, j)) {
                numNeighbors++;
            }
        }
    }

    return numNeighbors;
}

bool GameOfLife::isValid(int i, int j, int x, int y)
{
    return (i != x || j != y)
        && i >= 0 && i < width() && j >= 0 && j < height();
}

int GameOfLife::checkRules(int x, int y, int numNeighbors)
{
    bool cellIsAlive = isCellAlive(x, y);

    return
        (checkRule1(cellIsAlive, numNeighbors)
            || checkRule2(cellIsAlive, numNeighbors)) 
        ? 1 
        // Rule 3: All other live cells die in the next generation.Similarly, all other dead cells stay dead.
        : 0;
}


// Rule 1: Any live cell with two or three live neighbours survives.
bool GameOfLife::checkRule1(bool cellIsAlive, int numNeighbors)
{
    return cellIsAlive && (numNeighbors == 2 || numNeighbors == 3);
}

// Rule 2: Any dead cell with three live neighbours becomes a live cell.
bool GameOfLife::checkRule2(bool cellIsAlive, int numNeighbors)
{
    return !cellIsAlive && numNeighbors == 3;
}

int GameOfLife::getCell(int x, int y)
{
    int index = getIndex(x, y);
    return m_values[index];
}

bool GameOfLife::isCellAlive(int x, int y)
{
    return getCell(x, y) == 1;
}

void GameOfLife::setCell(int x, int y, int v)
{
    int index = getIndex(x, y);
    m_values[index] = v;
}

int GameOfLife::width()
{
    return m_width;
}

int GameOfLife::height()
{
    return m_height;
}

int GameOfLife::getIndex(int x, int y) {
    return y * width() + x;
}


#endif


SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;
GameOfLife *gameOfLife;

#define WIDTH 200
#define HEIGHT 200
#define NUMBER_OF_CHANNEL 4
#define NUMBER_OF_BIT 8

#define GML_WIDTH 10
#define GML_HEIGHT 10

void initGameOfLife()
{
    if (gameOfLife == nullptr)
    {
        int cells[100] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
            0, 1, 0, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        };
        gameOfLife = new GameOfLife(10, 10, &cells[0]);
    }
    else
    {
        gameOfLife->evolve();
    }
}

void drawRandomPixels()
{
    initGameOfLife();

    if (SDL_MUSTLOCK(surface))
        SDL_LockSurface(surface);

    Uint8 *pixels = (Uint8 *)surface->pixels;
    int *cellValues = gameOfLife->getCellValues();
    for (int i = 0; i < gameOfLife->width() * gameOfLife->height(); i++)
    {
        int v = cellValues[i];
        int pixelOffset = i * NUMBER_OF_CHANNEL;

        if (v == 1)
        {
            pixels[pixelOffset] = 0;
            pixels[pixelOffset + 1] = 0;
            pixels[pixelOffset + 2] = 0;
            pixels[pixelOffset + 3] = 0;
        }
        else
        {
            pixels[pixelOffset] = 255;
            pixels[pixelOffset + 1] = 255;
            pixels[pixelOffset + 2] = 255;
            pixels[pixelOffset + 3] = 255;
        }
    }

    // for (int i = 0; i < GML_WIDTH * GML_HEIGHT * NUMBER_OF_CHANNEL; i++)
    // {
    //     char randomByte = rand() % 255;
    //     pixels[i] = randomByte;
    // }

    if (SDL_MUSTLOCK(surface))
        SDL_UnlockSurface(surface);

    SDL_Texture *screenTexture = SDL_CreateTextureFromSurface(renderer, surface);

    // scale up from the texture?
    SDL_Rect dstrect;
    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.h = HEIGHT;
    dstrect.w = WIDTH;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screenTexture, NULL, &dstrect);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(screenTexture);
}

int main(int argc, char *argv[])
{
    gameOfLife = nullptr;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    // surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, NUMBER_OF_BIT * NUMBER_OF_CHANNEL, 0, 0, 0, 0);
    surface = SDL_CreateRGBSurface(0, GML_WIDTH, GML_HEIGHT, NUMBER_OF_BIT * NUMBER_OF_CHANNEL, 0, 0, 0, 0);

    emscripten_set_main_loop(drawRandomPixels, 0, 1);

    delete gameOfLife;

    return 0;
}
