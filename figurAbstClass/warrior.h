#pragma once
#include "abstr_unit.h"
class warrior :
    public abstr_unit
{
public:
    explicit warrior(const unit_stats& stats) : abstr_unit{ stats } {}

    void promotion() override;

    void rest() override;

};
