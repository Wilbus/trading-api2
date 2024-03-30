#include "IndicatorTypes.h"
#include "MultiCandle.h"
#include "ta-lib/ta_abstract.h"
#include "ta-lib/ta_common.h"
#include "ta-lib/ta_defs.h"
#include "ta-lib/ta_func.h"
#include "ta-lib/ta_libc.h"

#include <vector>

namespace ta_lib_wrapper {

using charting::IndicatorTypes;
using charting::IndicatorValue;
using charting::MultiCandle;

class TALIB
{
public:
    TALIB();
    ~TALIB();

    std::vector<IndicatorValue> copyOutToIndicatorValues(
        const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, TA_Integer outBeg, TA_Real out[]);

    std::vector<IndicatorValue> SMA(const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, int periods);
    std::vector<IndicatorValue> EMA(
        const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, int periods, int smoothing);
    std::vector<IndicatorValue> BB(const std::vector<MultiCandle>& mcandles, IndicatorTypes bbtype, int startIdx,
        int endIdx, int periods, double devUp, double devDown);
    std::vector<IndicatorValue> ADX(const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, int periods);
    std::vector<IndicatorValue> RSI(const std::vector<MultiCandle>& mcandles, int startIdx, int endIdx, int periods);
};
} // namespace ta_lib_wrapper