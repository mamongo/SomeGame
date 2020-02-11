/*#include <SFML/Graphics.hpp>

const int HEIGHT_MAP = 15;//25;//размер карты высота
const int WIDTH_MAP = 20;//40;//размер карты ширина  
sf::String TileMap[HEIGHT_MAP] = {
    "00000000000000000000",
    "0                  0",
    "0                  0",
    "0    s             0",
    "0    s             0",
    "0                  0",
    "0                  0",
    "0    s             0",
    "0    s             0",
    "0                  0",
    "0                  0",
    "0    s             0",
    "0    s             0",
    "0    s             0",
    "00000000000000000000",
};*/
#pragma once

#include <iostream>

const int RES_WIDTH = 416;
const int RES_HEIGHT = 416;

std::string randLine(int res_w){
    std::string mid = "0";
    int iter = 0;
    for(int i = 1; i < res_w/32 - 1; i++){
        int a = rand()%22;
        if(a == 1 && iter > 2){
            mid += "s";
            iter = 0;
        }
        else{
            mid += " ";
        }
        iter++;
    }
    mid += "0";
    return mid;
}

std::vector<string> mapCreate(int res_w, int res_h){
    std::vector<string> map;
    std::string border = "";
    std::string mid = "";
    for(int i = 0; i < res_w/32; i++){
        border += "0";
    }
    for(int j = 0; j < res_h/32; j++){
        if(j == 0 || j == res_h/32 - 1)
            map.push_back(border);
        else
            map.push_back(randLine(res_w));
        cout << map[j] << endl;
    }
    return map;
}


std::vector<string> m = mapCreate(RES_WIDTH, RES_HEIGHT);
