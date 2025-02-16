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
    static int camertone = 440;
};