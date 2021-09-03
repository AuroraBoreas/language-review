#include "eei.h"

OnModeEEI::OnModeEEI(double pmeas, double area, double corr=0.0)
: m_Pmeasured(pmeas), m_A(area), m_corr(corr) {}

double OnModeEEI::getEEI(void) const
{
    return (m_Pmeasured + 1) / ((3 * (90 * std::tanh(0.02 + 0.004 * (m_A - 11)) + 4) + 3) + m_corr);
}

char OnModeEEI::getEEILable(void) const
{
    double EEI_Lable = (m_Pmeasured + 1) / ((3 * (90 * std::tanh(0.025 + 0.0035 * (m_A - 11)) + 4) + 3) + m_corr);
    if(EEI_Lable < 0.30)
    {
        return 'A';
    }
    else if(EEI_Lable >= 0.30 && EEI_Lable < 0.40)
    {
        return 'B';
    }
    else if(EEI_Lable >= 0.40 && EEI_Lable < 0.50)
    {
        return 'C';
    }
    else if(EEI_Lable >= 0.50 && EEI_Lable < 0.60)
    {
        return 'D';
    }
    else if(EEI_Lable >= 0.60 && EEI_Lable < 0.75)
    {
        return 'E';
    }
    else if(EEI_Lable >= 0.75 && EEI_Lable < 0.90)
    {
        return 'F';
    }
    else /// EEI_Lable >= 0.90
    {
        return 'G';
    }
}
