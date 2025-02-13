#pragma once
#include <vector>
#include <string>
#include "note.h"
// Данная структура представляет аккорд. 

struct chord {
    public:
        std::vector<note> notes;
};