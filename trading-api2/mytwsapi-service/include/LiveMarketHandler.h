#include "CandleStick.h"
#include "EWrapperBaseImp.h"

#include <ctime>
#include <iomanip>
#include <map>
#include <mutex>
#include <optional>

using namespace charting;

struct RealTimeBarBuff
{
    uint64_t currentUnixS;
    uint64_t expectedNextS;
    std::vector<RealTimeBar> barsBuff;
};

class LiveMarketHandler
{
public:
    void handleRealTimeBar(RealTimeBar b);
    void handleHistoricalData(TickerId reqId, const Bar& bar);
    void handleHistoricalDataEnd(int reqId, std::string& startDateStr, std::string& endDateStr);
    void handleHistoricalDataUpdate(TickerId reqId, const Bar& bar);

    void storeCandle(std::string symbol, CandleStick c);
    CandleStick getCurrentCandle(std::string symbol);

    void addSymbol(int id, std::string symbol);

    std::optional<CandleStick> sampleRealTimeBar(std::string symbol, RealTimeBar b);
    CandleStick finishCandle(std::string symbol);

private:
    std::map<TickerId, std::string> reqIdtoSymbolMap;
    std::map<std::string, RealTimeBarBuff> realTimeBarBuffRecord;
    std::map<std::string, CandleStick> fiveSecondCandlesMap;

    std::mutex candlesMapMutex;
};
