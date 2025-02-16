#pragma once
#include <string>

/*
Никаких нот. Тон - это базовый кирпич музыки.

Атрибуты:
  frequency - частота тона.
  camerton - подстроечная частота.
*/

struct Tone{
    public:
    int frequency;
    static int camertone = 432; // в этом строю проще, тк он нацело делится на 12
    static float nextToneKey = 1,0594732; // корень 12 степени из 2
};