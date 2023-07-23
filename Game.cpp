#include <memory.h>
#include <stdlib.h>

#include "Circle.h"
#include "Dispatcher.h"
#include "Engine.h"
#include "GeomMaster.h"
#include "RingOfPlayer.h"

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'A', 'B')
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  clear_buffer() - set all pixels in buffer to 'black'
//  is_window_active() - returns true if window is active
//  schedule_quit_game() - quit game after act()


PlayerCircles *player;
Dispatcher *disp;

// initialize game data in this function
void initialize()
{
    const int white = 16777215;
    player = new PlayerCircles(SCREEN_HEIGHT / 6, 25, white);
    disp = new Dispatcher(player);
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
    if (player->alive_) {
        if (is_key_pressed(VK_SPACE)) {
            player->TryChangeDirection();
        }
        player->UpdateState(dt);
        disp->Update(dt);
    }
    else {
        disp->EndSpiel();
        schedule_quit_game();
    }

    if (is_key_pressed(VK_ESCAPE)) {
        schedule_quit_game();
    }
}

// required to draw the central ring, on which "a player rides"
void DrawCentralRing() {
    const int ring_color = 6000000;
    const int background_color = 0xD3D3D3;
    fillCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 137, ring_color);
    fillCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 125, background_color);  // 0xC0C0C0?
}

void DrawMovableObj() {
    player->Draw();
    disp->Draw();
}

void SpawnObjects() {
    DrawCentralRing();
    DrawMovableObj();
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw()
{
    // clear backbuffer
    const int light_grey = 211;
    memset(buffer, light_grey, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));   // 192?

    SpawnObjects();
}

// free game data in this function
void finalize()
{
    clear_buffer();
}
