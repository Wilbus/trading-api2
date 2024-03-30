// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SCHWABOPTIONSENUMS_SCHWABMARKETDATA_H_
#define FLATBUFFERS_GENERATED_SCHWABOPTIONSENUMS_SCHWABMARKETDATA_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");


namespace schwabMarketData {

enum class ExchangeName : int8_t {
  IND = 0,
  ASE = 1,
  NYS = 2,
  NAS = 3,
  NAP = 4,
  PAC = 5,
  OPR = 6,
  BATS = 7,
  MIN = IND,
  MAX = BATS
};

inline const ExchangeName (&EnumValuesExchangeName())[8] {
  static const ExchangeName values[] = {
    ExchangeName::IND,
    ExchangeName::ASE,
    ExchangeName::NYS,
    ExchangeName::NAS,
    ExchangeName::NAP,
    ExchangeName::PAC,
    ExchangeName::OPR,
    ExchangeName::BATS
  };
  return values;
}

inline const char * const *EnumNamesExchangeName() {
  static const char * const names[9] = {
    "IND",
    "ASE",
    "NYS",
    "NAS",
    "NAP",
    "PAC",
    "OPR",
    "BATS",
    nullptr
  };
  return names;
}

inline const char *EnumNameExchangeName(ExchangeName e) {
  if (::flatbuffers::IsOutRange(e, ExchangeName::IND, ExchangeName::BATS)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesExchangeName()[index];
}

enum class OptionStrategy : int8_t {
  SINGLE = 0,
  ANALYTICAL = 1,
  COVERED = 2,
  VERTICAL = 3,
  CALENDAR = 4,
  STRANGLE = 5,
  STRADDLE = 6,
  BUTTERFLY = 7,
  CONDOR = 8,
  DIAGONAL = 9,
  COLLAR = 10,
  ROLL = 11,
  MIN = SINGLE,
  MAX = ROLL
};

inline const OptionStrategy (&EnumValuesOptionStrategy())[12] {
  static const OptionStrategy values[] = {
    OptionStrategy::SINGLE,
    OptionStrategy::ANALYTICAL,
    OptionStrategy::COVERED,
    OptionStrategy::VERTICAL,
    OptionStrategy::CALENDAR,
    OptionStrategy::STRANGLE,
    OptionStrategy::STRADDLE,
    OptionStrategy::BUTTERFLY,
    OptionStrategy::CONDOR,
    OptionStrategy::DIAGONAL,
    OptionStrategy::COLLAR,
    OptionStrategy::ROLL
  };
  return values;
}

inline const char * const *EnumNamesOptionStrategy() {
  static const char * const names[13] = {
    "SINGLE",
    "ANALYTICAL",
    "COVERED",
    "VERTICAL",
    "CALENDAR",
    "STRANGLE",
    "STRADDLE",
    "BUTTERFLY",
    "CONDOR",
    "DIAGONAL",
    "COLLAR",
    "ROLL",
    nullptr
  };
  return names;
}

inline const char *EnumNameOptionStrategy(OptionStrategy e) {
  if (::flatbuffers::IsOutRange(e, OptionStrategy::SINGLE, OptionStrategy::ROLL)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesOptionStrategy()[index];
}

enum class PutCall : int8_t {
  PUT = 0,
  CALL = 1,
  MIN = PUT,
  MAX = CALL
};

inline const PutCall (&EnumValuesPutCall())[2] {
  static const PutCall values[] = {
    PutCall::PUT,
    PutCall::CALL
  };
  return values;
}

inline const char * const *EnumNamesPutCall() {
  static const char * const names[3] = {
    "PUT",
    "CALL",
    nullptr
  };
  return names;
}

inline const char *EnumNamePutCall(PutCall e) {
  if (::flatbuffers::IsOutRange(e, PutCall::PUT, PutCall::CALL)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesPutCall()[index];
}

enum class ExpirationType : int8_t {
  M = 0,
  Q = 1,
  S = 2,
  W = 3,
  MIN = M,
  MAX = W
};

inline const ExpirationType (&EnumValuesExpirationType())[4] {
  static const ExpirationType values[] = {
    ExpirationType::M,
    ExpirationType::Q,
    ExpirationType::S,
    ExpirationType::W
  };
  return values;
}

inline const char * const *EnumNamesExpirationType() {
  static const char * const names[5] = {
    "M",
    "Q",
    "S",
    "W",
    nullptr
  };
  return names;
}

inline const char *EnumNameExpirationType(ExpirationType e) {
  if (::flatbuffers::IsOutRange(e, ExpirationType::M, ExpirationType::W)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesExpirationType()[index];
}

enum class SettlementType : int8_t {
  A = 0,
  P = 1,
  MIN = A,
  MAX = P
};

inline const SettlementType (&EnumValuesSettlementType())[2] {
  static const SettlementType values[] = {
    SettlementType::A,
    SettlementType::P
  };
  return values;
}

inline const char * const *EnumNamesSettlementType() {
  static const char * const names[3] = {
    "A",
    "P",
    nullptr
  };
  return names;
}

inline const char *EnumNameSettlementType(SettlementType e) {
  if (::flatbuffers::IsOutRange(e, SettlementType::A, SettlementType::P)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesSettlementType()[index];
}

}  // namespace schwabMarketData

#endif  // FLATBUFFERS_GENERATED_SCHWABOPTIONSENUMS_SCHWABMARKETDATA_H_
