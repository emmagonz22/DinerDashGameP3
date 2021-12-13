#pragma once
#include "Client.h"

class Inspector : public Client
{
    private:
        int moneyDecreaseMultiplier = 2;
        bool inspectorLeaving = false;

    public:
        Inspector(int, int, int, int, ofImage, Burger*);
        ~Inspector();
};