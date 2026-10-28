#pragma once
#include "abstr_unit.h"
class mage :
    public abstr_unit
{
public:
    explicit mage(const unit_stats& stats) : abstr_unit{ stats } {}

    void promotion() override;

    void rest() override;

};
