//
// Created by dat tran on 18.04.21.
//

#ifndef INC_05_UNIT_TEST_MOCK_DATA_CIMGGIP05MOCK_H
#define INC_05_UNIT_TEST_MOCK_DATA_CIMGGIP05MOCK_H
// Datei: CImgGIP05Mock.h

const unsigned char white[] = { 255, 255, 255 };
const unsigned char black[] = { 0, 0, 0 };
const unsigned char red[] = { 255, 0, 0 };
const unsigned char green[] = { 0, 255, 0 };
const unsigned char blue[] = { 0, 0, 255 };

const unsigned int gip_win_sizeX = 600; // Fenstergroesse X
const unsigned int gip_win_sizeY = 600; // Fenstergroesse Y

inline void gip_draw_rectangle(unsigned int x0, unsigned int y0,
                               unsigned int x1, unsigned int y1, const unsigned char *const color = black) {}

#endif //INC_05_UNIT_TEST_MOCK_DATA_CIMGGIP05MOCK_H
