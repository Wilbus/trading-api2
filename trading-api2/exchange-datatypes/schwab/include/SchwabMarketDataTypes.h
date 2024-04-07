#pragma once

#include <cmath>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace schwabMarketData {

// TODO: initialize all variables to MAX of value type

static const double MAXDOUBLE = std::numeric_limits<double>::max();
static const unsigned MAXUNSIGNED = std::numeric_limits<unsigned>::max();
static const unsigned long MAXULONG = std::numeric_limits<unsigned long>::max();

enum AssetMainType : uint8_t
{
    BOND = 0,
    EQUITY,
    FOREX,
    FUTURE,
    FUTURE_OPTION,
    INDEX,
    MUTUAL_FUND,
    OPTION
};

// clang-format off
static const std::map<std::string, AssetMainType> stringToAssetMainType = 
{
    {"BOND", AssetMainType::BOND},
    {"EQUITY", AssetMainType::EQUITY},
    {"FOREX", AssetMainType::FOREX},
    {"FUTURE", AssetMainType::FUTURE},
    {"FUTURE_OPTION", AssetMainType::FUTURE_OPTION},
    {"INDEX", AssetMainType::INDEX},
    {"MUTUAL_FUND", AssetMainType::MUTUAL_FUND},
    {"OPTION", AssetMainType::OPTION}
};
// clang-frormat on

enum AssetSubType : uint8_t
{
    COE = 0,
    PRF,
    ADR,
    GDR,
    CEF,
    ETF,
    ETN,
    UIT,
    WAR,
    RGT
};

// clang-format off
static const std::map<std::string, AssetSubType> stringToAssetSubType = 
{
    {"COE", AssetSubType::COE},
    {"PRF", AssetSubType::PRF},
    {"ADR", AssetSubType::ADR},
    {"GDR", AssetSubType::GDR},
    {"CEF", AssetSubType::CEF},
    {"ETF", AssetSubType::ETF},
    {"ETN", AssetSubType::ETN},
    {"UIT", AssetSubType::UIT},
    {"WAR", AssetSubType::WAR},
    {"RGT", AssetSubType::RGT}
};
// clang-frormat on

struct QuoteResponseBase
{
    AssetMainType assetMainType;
    AssetSubType assetSubType;
    uint64_t ssid;
    std::string symbol;
    bool realtime;
};

struct QuoteReference
{
    std::string cusip;
    std::string description;
    std::string exchange;
    std::string exchangeName;
    bool isHardToBorrow;
    bool isShortable;
    double htbRate;
};

struct QuoteEquity
{
    double yearHigh;
    double yearLow;
    std::string askMICId;
    double askPrice;
    uint64_t askSize;
    uint64_t askTime;
    std::string bidMICId;
    double bidPrice;
    uint64_t bidSize;
    uint64_t bidTime;
    double closePrice;
    double highPrice;
    std::string lastMICId;
    double lastPrice;
    uint64_t lastSize;
    double lowPrice;
    double mark;
    double markChange;
    double markPercentChange;
    double netChange;
    double netPercentChange;
    double openPrice;
    double postMarketChange;
    double postMarketPercentChange;
    uint64_t quoteTime;
    std::string securityStatus;
    uint64_t totalVolume;
    uint64_t tradeTime;
};

enum QuoteType : uint8_t
{
    NBBO = 0,
    NFL
};

struct ExtendedMarketQuoteEquity
{
    double askPrice;
    uint32_t askSize;
    double bidPrice;
    uint32_t bidSize;
    double lastPrice;
    uint32_t lastSize;
    double mark;
    uint64_t quoteTime;
    uint64_t totalVolume;
    uint64_t tradeTime;
};

struct QuoteEquityFundamentals
{
    double avg10DaysVolume;
    double avg1YearVolume;
    std::string declarationDate; //2021-04-28T00:00:00Z pattern: yyyy-MM-dd'T'HH:mm:ssZ
    double divAmount;
    std::string divExDate; //example: 2021-05-07T00:00:00ZDividend date in yyyy-mm-ddThh:mm:ssZ
    uint32_t divFreq;
    double divPayAmount;
    std::string divPayDate; //2021-05-13T00:00:00Z pattern: yyyy-MM-dd'T'HH:mm:ssZ Dividend pay date in yyyy-mm-ddThh:mm:ssZ
    double eps;
    double fundLeverageFactor;
    std::string fundStrategy; //FundStrategy "A" - Active "L" - Leveraged "P" - Passive "Q" - Quantitative "S" - Short
    std::string nextDivExDate;  //	string($date-time) example: 2021-02-12T00:00:00Z pattern: yyyy-MM-dd'T'HH:mm:ssZ
    std::string nextDivPayDate; //example: 2021-02-12T00:00:00Z pattern: yyyy-MM-dd'T'HH:mm:ssZ
    double peRatio;
};

struct QuoteEquityResponse : public QuoteResponseBase
{
    QuoteType quoteType;
    ExtendedMarketQuoteEquity extended;
    QuoteEquityFundamentals fundamenal;
    QuoteEquity quote;
};

struct QuoteOption
{
    double yearHigh;
    double yearLow;
    double askPrice;
    uint32_t askSize;
    double bidPrice;
    uint32_t bidSize;
    double closePrice;
    double delta;
    double gamma;
    double highPrice;
    double indAskPrice;
    double indBidPrice;
    uint64_t indQuoteTime;
    double impliedYield;
    double lastPrice;
    uint32_t lastSize;
    double lowPrice;
    double mark;
    double markChange;
    double markPercentChange;
    double moneyIntrinsicVlaue;
    double netChange;
    double netPercentChange;
    double openInterest;
    uint64_t quoteTime;
    double rho;
    std::string securityStatus;
    double theoreticalOptionValue;
    double theta;
    double timeValue;
    uint64_t totalVolume;
    uint64_t tradeTime;
    double underlyingPrice;
    double vega;
    double volatility;
};

struct QuoteOptionResponse : public QuoteResponseBase
{
    QuoteOption quote;
};

struct Candle
{
    double open;
    double high;
    double low;
    double close;
    uint64_t volume;
    uint64_t datetime;
};

struct PriceHistory
{
    std::string symbol;
    bool empty;
    double previousClose;
    uint64_t previousCloseDate;
    std::vector<Candle> candles;
};

struct OptionExpiration
{
    std::string expirationDate; //yyyy-MM-dd
    unsigned daysToExpiration;
    std::string expirationType;
    bool standard;
};

struct OptionUnderlying
{
    double ask;
    unsigned askSize;
    double bid;
    unsigned bidSize;
    double change;
    double close;
    bool delayed;
    std::string description;
    std::string exchangeName;
    double fiftyTwoWeekHigh;
    double fiftyTwoWeekLow;
    double highPrice;
    double last;
    double lowPrice;
    double mark;
    double markPercentChange;
    double openPrice;
    double percentChange;
    unsigned long quoteTime;
    std::string symbol;
    unsigned long totalVolume;
    unsigned long tradeTime;
};

struct OptionContract
{
    std::string putCall;
    std::string symbol;
    std::string exchangeName;
    double bidPrice{MAXDOUBLE};
    double askPrice{MAXDOUBLE};
    double lastPrice{MAXDOUBLE};
    double markPrice{MAXDOUBLE};
    unsigned bidSize{MAXUNSIGNED};
    unsigned askSize{MAXUNSIGNED};
    std::string bidAskSize;
    unsigned lastSize{MAXUNSIGNED};
    double highPrice{MAXDOUBLE};
    double lowPrice{MAXDOUBLE};
    double openPrice{MAXDOUBLE};
    double closePrice{MAXDOUBLE};
    unsigned totalVolume{MAXUNSIGNED};
    unsigned long tradeDate{MAXULONG};
    unsigned long quoteTimeInLong{MAXULONG};
    unsigned long tradeTimeInlong{MAXULONG};
    double netChange{MAXDOUBLE};
    double volatility{MAXDOUBLE};
    double delta{MAXDOUBLE};
    double gamma{MAXDOUBLE};
    double theta{MAXDOUBLE};
    double vega{MAXDOUBLE};
    double rho{MAXDOUBLE};
    double timeValue{MAXDOUBLE};
    double openInterest{MAXDOUBLE};
    bool inTheMoney;
    double theoreticalOptionValue{MAXDOUBLE};
    double theoreticalVolatility{MAXDOUBLE};
    bool mini;
    bool nonStandard;
    //TODO: optionsDelivrableList
    double strikePrice{MAXDOUBLE};
    std::string expirationDate;
    unsigned daysToExpiration{MAXUNSIGNED};
    std::string expirationType;
    unsigned long lastTradingDay{MAXULONG};
    double multiplier{MAXDOUBLE};
    //TODO: settlementType
    bool isIndexOption;
    double percentChange{MAXDOUBLE};
    double markChange{MAXDOUBLE};
    double markPercentChange{MAXDOUBLE};
    bool pennyPilot;
    double intrinsicValue{MAXDOUBLE};
    double extrinsicValue{MAXDOUBLE};
    std::string optionRoot;
    double high52Week{MAXDOUBLE};
    double low52Week{MAXDOUBLE};

    friend bool operator< (const OptionContract& lhs, const OptionContract& rhs)
    {
        return lhs.strikePrice < rhs.strikePrice;
    }
};

enum OptionStrategy : uint8_t
{
    SINGLE = 0,
    ANALYTICAL,
    COVERED,
    VERTICAL,
    CALENDAR,
    STRANGLE,
    STRADDLE,
    BUTTERFLY,
    CONDOR,
    DIAGONAL,
    COLLAR,
    ROLL
};

//clang-format off
static const std::map<std::string, OptionStrategy> optionStrategyMap =
{
    {"SINGLE", OptionStrategy::SINGLE},
    {"ANALYTICAL", OptionStrategy::ANALYTICAL},
    {"COVERED", OptionStrategy::COVERED},
    {"VERTICAL", OptionStrategy::VERTICAL},
    {"CALENDAR", OptionStrategy::CALENDAR},
    {"STRANGLE", OptionStrategy::STRANGLE},
    {"STRADDLE", OptionStrategy::STRADDLE},
    {"BUTTERFLY", OptionStrategy::BUTTERFLY},
    {"CONDOR", OptionStrategy::CONDOR},
    {"DIAGONAL", OptionStrategy::DIAGONAL},
    {"COLLAR", OptionStrategy::COLLAR},
    {"ROLL", OptionStrategy::ROLL},
};
//clang-format on
typedef std::string OptionExpDate;
typedef std::set<OptionContract> StrikesChain;
typedef std::map<OptionExpDate, StrikesChain> OptionContractMap;

struct OptionChain
{
    std::string symbol;
    std::string status;
    OptionUnderlying underlying;
    OptionStrategy strategy;
    double interval;
    bool isDelayed;
    bool isIndex;
    double daysToExpiration;
    double interestRate;
    double underlyingPrice;
    double volatility;
    OptionContractMap callExpDateMap;
    OptionContractMap putExpDateMap;
};
}