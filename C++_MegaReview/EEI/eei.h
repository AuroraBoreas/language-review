/** \topic   TV EEI and EEI label
 *  \article http://www.baclcorp.com.cn/show.asp?para=cn_2_7_3395
 *  \purpose abstract the calculation
 *  \ERP     (EU) 2019/2021
 *  \author  @ZL, 20210728
 *  \version v0.01
 */

#include <cmath>

const double EEI_limit1(0.90); /// resolution up to 2 138 400 pixels(HD), 1 Mar 2021: 0.90; 1 Mar 2023: 0.75;
const double EEI_limit2(1.10); /// resolution above 2 138 400 ~ 8 294 400 pixels, 1 Mar 2021: 1.10; 1 Mar 2023: 0.90;
const double EEI_limit3(0.90); /// resolution above 8 294 400 ~, 1 Mar 2021: n.a.; 1 Mar 2023: 0.90;

/**
 * \EEImax vs \electronic display resolution

   | due date   | <= 2 138 400 px | 2 138 400 ~ 8 294 400px | > 8 294 400px |
   ==========================================================================
   | 1 Mar 2021 | 0.90            | 1.10                    | n.a.          |
   | 1 Mar 2023 | 0.75            | 0.90                    | 0.90          |


 * \corr value
   | type            | corr value          |
   =========================================
   | TV              | 0.0                 |
   | Monitor         | 0.0                 |
   | Digital signage | 0.00062*(lum-500)*A |
   | Digital signage | 0.00062*(lum-500)*A |

 * \lum is the peak white luminance, in cd/m2, of the brightness on mode configuration of the electronic display
 * \A is the screen area in dm2;
*/

class OnModeEEI
{
private:
    double m_Pmeasured; /// Pmeasured是on mode模式下测得的消耗功率(W)
    double m_A;         ///  A是屏幕面积(dm2)
    double m_corr;      /// corr是修正因数(不适用于ABC功能加权的OLED电子显示器是10，其他的是0)
public:
    OnModeEEI(double, double, double);
    double getEEI(void) const;
    char getEEILable(void) const;
}; // class OnModeEEI
