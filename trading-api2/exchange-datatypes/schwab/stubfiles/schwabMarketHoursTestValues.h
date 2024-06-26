#pragma once

#include <string>

static std::string marketHoursExample =
                       R"({
  "future": {
    "DFE": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "DFE",
      "productName": "kern river natural gas (platts iferc) fixed price futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ]
      }
    },
    "NZN": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "NZN",
      "productName": "transco zone 6 natural gas (platts iferc) basis futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ]
      }
    },
    "Z1A": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "CMED",
      "category": "Energy",
      "product": "Z1A",
      "productName": "european ethanol t2 fob rotterdam inc duty (platts) calendar month future",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ]
      }
    },
    "BBT": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "BBT",
      "productName": "brent crude oil tas futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T14:30:00-04:00"
          }
        ],
        "outcryMarket": [
          {
            "start": "2024-06-03T09:00:00-04:00",
            "end": "2024-06-03T14:30:00-04:00"
          }
        ]
      }
    },
    "HOB": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "HOB",
      "productName": "ny harbor ulsd brent crack spread options",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ],
        "outcryMarket": [
          {
            "start": "2024-06-03T09:00:00-04:00",
            "end": "2024-06-03T14:30:00-04:00"
          }
        ]
      }
    },
    "AF": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "AF",
      "productName": "gulf coast jet (argus) futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ]
      }
    },
    "AJ": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "AJ",
      "productName": "gulf coast ulsd (argus) futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ]
      }
    },
    "YQB": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "ICE",
      "category": "Energy",
      "product": "YQB",
      "productName": "transco leidy basis future",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T19:40:00-04:00",
            "end": "2024-06-02T19:50:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T19:50:00-04:00",
            "end": "2024-06-03T18:05:00-04:00"
          }
        ]
      }
    },
    "HOT": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "HOT",
      "productName": "ny harbor ulsd tas",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T14:30:00-04:00"
          }
        ],
        "outcryMarket": [
          {
            "start": "2024-06-03T09:00:00-04:00",
            "end": "2024-06-03T14:30:00-04:00"
          }
        ]
      }
    },
    "B0": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "B0",
      "productName": "mont belvieu ldh propane (opis) futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ]
      }
    },
    "QAA": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "CMED",
      "category": "Energy",
      "product": "QAA",
      "productName": "european low sulphur gasoil (ice) calendar month future",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ]
      }
    },
    "YQI": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "ICE",
      "category": "Energy",
      "product": "YQI",
      "productName": "transco leidy index future",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T19:40:00-04:00",
            "end": "2024-06-02T19:50:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T19:50:00-04:00",
            "end": "2024-06-03T18:05:00-04:00"
          }
        ]
      }
    },
    "AR": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "ICE",
      "category": "FX",
      "product": "AR",
      "productName": "cross currency pairs australian dollar new zealand dollar futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T19:30:00-04:00",
            "end": "2024-06-02T20:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T20:00:00-04:00",
            "end": "2024-06-03T17:00:00-04:00"
          }
        ]
      }
    },
    "AS": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "ICE",
      "category": "FX",
      "product": "AS",
      "productName": "cross currency pairs australian dollar canadian dollar futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T19:30:00-04:00",
            "end": "2024-06-02T20:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T20:00:00-04:00",
            "end": "2024-06-03T17:00:00-04:00"
          }
        ]
      }
    },
    "AW": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "CME",
      "category": "Agriculture",
      "product": "AW",
      "productName": "bloomberg commodity index futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T09:15:00-04:00",
            "end": "2024-06-02T14:30:00-04:00"
          },
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T09:15:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T20:00:00-04:00",
            "end": "2024-06-03T08:45:00-04:00"
          }
        ]
      }
    },
    "SEK": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "CME",
      "category": "FX",
      "product": "SEK",
      "productName": "swedish krona futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:00:00-04:00"
          }
        ]
      }
    },
    "AY": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "AY",
      "productName": "wts (argus) trade month futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ]
      }
    },
    "YQS": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "ICE",
      "category": "Energy",
      "product": "YQS",
      "productName": "transco leidy swing future",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T19:40:00-04:00",
            "end": "2024-06-02T19:50:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T19:50:00-04:00",
            "end": "2024-06-03T18:05:00-04:00"
          }
        ]
      }
    },
    "HPE": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "NYMEX",
      "category": "Energy",
      "product": "HPE",
      "productName": "hdpe high density polyethylene (pcw) financial futures",
      "isOpen": true,
      "sessionHours": {
        "preMarket": [
          {
            "start": "2024-06-02T17:45:00-04:00",
            "end": "2024-06-02T18:00:00-04:00"
          }
        ],
        "regularMarket": [
          {
            "start": "2024-06-02T18:00:00-04:00",
            "end": "2024-06-03T17:15:00-04:00"
          }
        ]
      }
    },
    "UIS": {
      "date": "2024-06-03",
      "marketType": "FUTURE",
      "exchange": "CMED",
      "category": "FX",
      "product": "UIS",
      "productName": "u.s. dollar   israeli shekel (usd ils) physically deliverable future (cls eligible)",
                   "isOpen" : true, "sessionHours":
{
    "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                  "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
}
}
, "BA" : {
    "date" : "2024-06-03",
    "marketType" : "FUTURE",
    "exchange" : "NYMEX",
    "category" : "Energy",
    "product" : "BA",
    "productName" : "brent financial average price futures",
    "isOpen" : true,
    "sessionHours" : {
        "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
        "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
    }
},
         "BB" : {
             "date" : "2024-06-03",
             "marketType" : "FUTURE",
             "exchange" : "NYMEX",
             "category" : "Energy",
             "product" : "BB",
             "productName" : "brent crude oil futures",
             "isOpen" : true,
             "sessionHours" : {
                 "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                 "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
             }
         },
                "BE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "BE",
        "productName" : "brent last day financial (european) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "BG" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "BG",
          "productName" : "european low sulphur gasoil (1000mt) bullet futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "BK" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "BK",
                 "productName" : "wti-brent financial futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "FLP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "FLP",
        "productName" : "freight route liquid petroleum gas (baltic) future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "BR" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "BR",
          "productName" : "brazilian real futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "SFC" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "SFC",
                 "productName" : "singapore fuel oil 180 cst (platts) brent crack spread futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "Z3N"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Interest Rate",
        "product" : "Z3N",
        "productName" : "3-year t-note futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "C7" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "C7",
          "productName" : "oneok, oklahoma natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "C8" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "C8",
                 "productName" : "algonquin city-gates natural gas (platts gas daily) swing futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "C9"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "C9",
        "productName" : "southern star, tx.-okla.-kan. natural gas (platts gas daily platts iferc) index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "BZ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "BZ",
          "productName" : "brent last day financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "SFN" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "SFN",
                 "productName" : "socal natural gas (platts gas daily) swing futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "CB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Agriculture",
        "product" : "CB",
        "productName" : "cash-settled butter futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "BEA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "BEA",
          "productName" : "european benzene cif ara (argus) trade month futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Agriculture",
                  "product" : "CC",
                  "productName" : "cocoa futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-02T04:45:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-03T05:45:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
                  }
              },
                     "SFT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "SFT",
        "productName" : "supramax timecharter average (baltic) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "DIH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "DIH",
          "productName" : "dominion, south point natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CJ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Agriculture",
                  "product" : "CJ",
                  "productName" : "cocoa futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "CK"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CK",
        "productName" : "gulf coast unl 87 (argus) crack spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CL",
          "productName" : "crude oil futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "UKE" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CMED",
                 "category" : "Energy",
                 "product" : "UKE",
                 "productName" : "uk nbp natural gas (icis heren) calendar month future",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "UKD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "Energy",
        "product" : "UKD",
        "productName" : "uk nbp natural gas (icis heren) daily future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "SGB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "SGB",
          "productName" : "singapore gasoil (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CT" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Agriculture",
                  "product" : "CT",
                  "productName" : "cotton no. 2 futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T21:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T22:00:00-04:00", "end" : "2024-06-03T15:20:00-04:00"} ]
                  }
              },
                     "CU"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CU",
        "productName" : "chicago ethanol (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CW",
          "productName" : "pge citygate natural gas (platts iferc) \"pipe\" option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
             "CY" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "CY",
                 "productName" : "brent financial futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "HRC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Metals",
        "product" : "HRC",
        "productName" : "u.s. midwest domestic hot-rolled coil steel (cru) index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "QCN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Equities",
          "product" : "QCN",
          "productName" : "e-mini nasdaq composite futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
          }
      },
              "DC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Agriculture",
                  "product" : "DC",
                  "productName" : "class iii milk futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                     "UKW"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "UKW",
        "productName" : "u.s. dollar   korean won (usd krw) cash settled future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "SGW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "SGW",
          "productName" : "socal gas city-gate natural gas (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "DI" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "DI",
                  "productName" : "demarc natural gas (platts gas daily platts iferc) index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "E7"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "E7",
        "productName" : "e-mini euro fx futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "DX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "DX",
          "productName" : "us dollar index® futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T21:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
             "Z5P" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "Z5P",
                 "productName" : "texas eastern zone m-3 natural gas (platts iferc) fixed price futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "DY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Agriculture",
        "product" : "DY",
        "productName" : "dry whey futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "EB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Interest Rate",
          "product" : "EB",
          "productName" : "three-month euribor futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "EH" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Energy",
                 "product" : "EH",
                 "productName" : "ethanol futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "EJ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Interest Rate",
        "product" : "EJ",
        "productName" : "euroyen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "EN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "EN",
          "productName" : "european naphtha (platts) crack spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "DKR" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Energy",
                 "product" : "DKR",
                 "productName" : "transco zone 5 basis future",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
                 }
             },
                     "DKT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Energy",
        "product" : "DKT",
        "productName" : "transco zone 5 index future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
        }
    },
      "DKS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Energy",
          "product" : "DKS",
          "productName" : "transco zone 5 swing future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
          }
      },
              "ES" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Equities",
                  "product" : "ES",
                  "productName" : "e-mini sp 500 futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                     "EW"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "EW",
        "productName" : "e-mini sp 500 eom futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "F8" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "F8",
          "productName" : "european-style low sulphur gasoil futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "EZ" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "FX",
                 "product" : "EZ",
                 "productName" : "euro currency pairs euro czech koruna futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                    "SIL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "COMEX",
        "category" : "Metals",
        "product" : "SIL",
        "productName" : "1,000-oz. silver futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "FPB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "Energy",
          "product" : "FPB",
          "productName" : "french power baseload (epex spot) calendar month future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "SIR" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "SIR",
                  "productName" : "indian rupee usd futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "FC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "FC",
        "productName" : "ny harbor ulsd calendar spread option - 3 month",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "SIT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "SIT",
          "productName" : "silver tas futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [
                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T13:25:00-04:00"},
                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"}
              ]
          }
      },
              "FPN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "FPN",
                  "productName" : "florida gas, zone 3 natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "FM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "FM",
        "productName" : "ny harbor ulsd calendar spread option - 6 month",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "G2" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "G2",
          "productName" : "russell 2000 growth index mini futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
             "_1NA" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "1NA",
                 "productName" : "singapore mogas 92 unleaded (platts) dubai (platts) crack spread futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                      "HUF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "HUF",
        "productName" : "hungarian forint futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "GC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "GC",
          "productName" : "gold futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "GD" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CME",
                 "category" : "Agriculture",
                 "product" : "GD",
                 "productName" : "sp-gsci commodity index futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                    "GE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Interest Rate",
        "product" : "GE",
        "productName" : "eurodollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "GF" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Agriculture",
          "product" : "GF",
          "productName" : "feeder cattle futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T07:00:00-04:00", "end" : "2024-06-02T10:05:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "DML" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "DML",
                 "productName" : "malin natural gas (platts iferc) fixed price futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "SJY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "SJY",
        "productName" : "swiss franc japanese yen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "GL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "GL",
          "productName" : "columbia gulf, louisiana natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "GN" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "FX",
                 "product" : "GN",
                 "productName" : "cross currency pairs british pound sterling new zealand dollar futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                    "DMR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Energy",
        "product" : "DMR",
        "productName" : "tennessee zone 4 300l basis future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
        }
    },
      "BIO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Equities",
          "product" : "BIO",
          "productName" : "e-mini nasdaq biotechnology index options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
          }
      },
              "DMQ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Energy",
                  "product" : "DMQ",
                  "productName" : "tennessee zone 4 300l index future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
                  }
              },
                      "DMS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Energy",
        "product" : "DMS",
        "productName" : "tennessee zone 4 300l swing future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
        }
    },
      "OCD" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "OCD",
          "productName" : "short-dated new crop corn options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
          }
      },
              "GY" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "GY",
                  "productName" : "gulf coast ulsd (platts) crack spread futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "GZ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "GZ",
        "productName" : "european low sulphur gasoil brent crack spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "FRC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "FRC",
          "productName" : "freight route tc14 (baltic) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "G3B" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "G3B",
                  "productName" : "natural gas (henry hub) last-day financial 3 month spread futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "HB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "HB",
        "productName" : "henry hub natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "DNG" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "Energy",
          "product" : "DNG",
          "productName" : "dutch ttf natural gas (icis heren) daily future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "HE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Agriculture",
                  "product" : "HE",
                  "productName" : "lean hog futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T07:00:00-04:00", "end" : "2024-06-02T10:05:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:05:00-04:00"} ]
                  }
              },
                     "HG"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "COMEX",
        "category" : "Metals",
        "product" : "HG",
        "productName" : "copper futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "HH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "HH",
          "productName" : "natural gas (henry hub) last-day financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "FRS" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "FRS",
                 "productName" : "freight route tc12 (baltic) futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "DNP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "DNP",
        "productName" : "demarc natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "HO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "HO",
          "productName" : "ny harbor ulsd options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
             "DNS" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "DNS",
                 "productName" : "ngpl stx natural gas (platts iferc) fixed price futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "HP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "HP",
        "productName" : "natural gas (henry hub) penultimate financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "HR" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "HR",
          "productName" : "euro currency pairs euro hungarian forint futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "ODB" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "ODB",
                 "productName" : "brent crude oil daily options",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
                     "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
                 }
             },
                     "WTI"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "WTI",
        "productName" : "wti midland (argus) trade month futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "HY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "HY",
          "productName" : "cross currency pairs canadian dollar japanese yen futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "DOB" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "DOB",
                 "productName" : "dme oman crude oil balmo swap options",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
                     "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
                 }
             },
                     "DOA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "DOA",
        "productName" : "dme oman crude oil average price option options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "WTS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "WTS",
          "productName" : "wts (argus) financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "FSF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Metals",
                  "product" : "FSF",
                  "productName" : "hms 80 20 ferrous scrap, cfr turkey (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "IB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "IB",
        "productName" : "natural gas 2 month calendar spread option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "IF" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "IF",
          "productName" : "socal natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "II" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "II",
                 "productName" : "enable natural gas (platts gas daily platts iferc) index futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "IJ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "IJ",
        "productName" : "san juan natural gas (platts gas daily platts iferc) index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "IK" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "IK",
          "productName" : "pge citygate natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "IL" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "IL",
                 "productName" : "permian natural gas (platts gas daily platts iferc) index futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "IM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "IM",
        "productName" : "natural gas 6 month calendar spread option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "DOO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "DOO",
          "productName" : "dme oman crude oil swap options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "IN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "IN",
                  "productName" : "henry hub natural gas (platts gas daily platts iferc) index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "SMC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "SMC",
        "productName" : "e-mini sp 600 smallcap futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "IQ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "IQ",
          "productName" : "anr, oklahoma natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "IR" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "IR",
                 "productName" : "rockies natural gas (platts gas daily platts iferc) index futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "IS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Agriculture",
        "product" : "IS",
        "productName" : "us soybean futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "G4X" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "G4X",
          "productName" : "natural gas (henry hub) last-day financial 1 month spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "IU" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "IU",
                  "productName" : "sumas natural gas (platts gas daily platts iferc) index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "J7"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "J7",
        "productName" : "e-mini japanese yen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "IV" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "IV",
          "productName" : "panhandle natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "IW" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Agriculture",
                 "product" : "IW",
                 "productName" : "us wheat futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
                 }
             },
                    "IX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "IX",
        "productName" : "tetco m-3 natural gas (platts gas daily platts iferc) index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "IY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "IY",
          "productName" : "waha natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "MAE" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "MAE",
                 "productName" : "mini argus propane far east index futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "OEH"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Energy",
        "product" : "OEH",
        "productName" : "ethanol options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "HXE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "HXE",
          "productName" : "copper futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T08:10:00-04:00", "end" : "2024-06-03T13:00:00-04:00"} ]
          }
      },
              "SMN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "SMN",
                  "productName" : "houston ship channel natural gas (platts gas daily) swing futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "JA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "JA",
        "productName" : "japan cf naphtha (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "JE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "JE",
          "productName" : "eia flat tax u.s. retail gasoline futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "SMW" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "SMW",
                 "productName" : "singapore 380cst fuel oil (platts) mini weekly spread futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "MB4"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Energy",
        "product" : "MB4",
        "productName" : "tetco m2 index future (receipts)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
        }
    },
      "MAS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MAS",
          "productName" : "mini argus propane (saudi aramco) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "MAW" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Equities",
                  "product" : "MAW",
                  "productName" : "mini msci all country world index future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                  }
              },
                      "DPP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "DPP",
        "productName" : "dominion, south point natural gas (platts iferc) pipe futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "_5ZN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "5ZN",
          "productName" : "columbia gulf, mainline natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
               "BM3"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Energy",
        "product" : "BM3",
        "productName" : "tetco m2 swing future (receipts)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
        }
    },
      "MBB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MBB",
          "productName" : "mont belvieu ethylene (pcw) balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "OFF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "OFF",
        "productName" : "ontario off-peak calendar-month options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "MBC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MBC",
          "productName" : "mini brent financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "MBE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "MBE",
                  "productName" : "mont belvieu spot ethylene in-well futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "G6B"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "G6B",
        "productName" : "natural gas (henry hub) last-day financial 6 month spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "SNO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Energy",
          "product" : "SNO",
          "productName" : "spp north hub day-ahead off-peak daily fixed price future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
          }
      },
              "SNR" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Energy",
                  "product" : "SNR",
                  "productName" : "spp north hub day-ahead peak daily fixed price future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
                  }
              },
                      "MBL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MBL",
        "productName" : "mont belvieu ldh iso-butane (opis) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "KC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Agriculture",
          "product" : "KC",
          "productName" : "coffee c futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-02T04:15:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-03T05:15:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
             "KE" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Agriculture",
                 "product" : "KE",
                 "productName" : "kc hrw wheat futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [
                         {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                         {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                     ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
                 }
             },
                    "MBR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MBR",
        "productName" : "mont belvieu ethylene (pcw) financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "KJ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KJ",
          "productName" : "cross currency pairs swedish krona japanese yen futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "KT" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Agriculture",
                 "product" : "KT",
                 "productName" : "coffee futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "MCC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MCC",
        "productName" : "indonesian coal (mccloskey sub-bituminous) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "KX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KX",
          "productName" : "dollar based currency pairs us dollar swedish krona",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "MCE" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Equities",
                 "product" : "MCE",
                 "productName" : "mini msci europe index future",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                 }
             },
                     "KY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "KY",
        "productName" : "cross currency pairs norwegian krone japanese yen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "MCD" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "MCD",
          "productName" : "e-micro canadian dollar american dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "LB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "LB",
        "productName" : "ny harbor ulsd european financial option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "MCL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "MCL",
          "productName" : "mini msci canada index future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "LE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Agriculture",
                  "product" : "LE",
                  "productName" : "live cattle futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T07:00:00-04:00", "end" : "2024-06-02T10:05:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:05:00-04:00"} ]
                  }
              },
                     "MCU"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Equities",
        "product" : "MCU",
        "productName" : "mini msci usa value index future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
        }
    },
      "MCW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "MCW",
          "productName" : "mgex-chicago srw wheat spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
          }
      },
              "LL" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "LL",
                  "productName" : "los angeles jet (opis) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "LO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "LO",
        "productName" : "crude oil options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "DRS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "DRS",
          "productName" : "bloomberg roll select commodity index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ]
          }
      },
              "LT" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "LT",
                  "productName" : "gulf coast ulsd (platts) up-down futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "QLD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "QLD",
        "productName" : "central appalachian coal futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "T1E" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Interest Rate",
          "product" : "T1E",
          "productName" : "2-year euro deliverable interest rate swap futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "_8AN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "8AN",
                  "productName" : "florida gas, zone 2 natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                       "M7"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "M7",
        "productName" : "trunkline ela natural gas (platts gas daily platts iferc) index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "MDB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MDB",
          "productName" : "mini dated brent (platts) financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "M8"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "M8",
        "productName" : "southern natural, louisiana natural gas (platts gas daily platts iferc) index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "UTL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "UTL",
          "productName" : "u.s. dollar   turkish lira (usd try) physically deliverable future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "M9" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "M9",
                  "productName" : "texas eastern, ela natural gas (platts gas daily platts iferc) index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "SPP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "Energy",
        "product" : "SPP",
        "productName" : "spanish power peakload (omip) calendar month future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "SPO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Interest Rate",
          "product" : "SPO",
          "productName" : "eurodollar calendar spread options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
          }
      },
              "MB" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "MB",
                  "productName" : "loop gulf coast sour crude oil futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "DSF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "DSF",
        "productName" : "dominion, south point natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ME" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ME",
          "productName" : "gulf coast jet (platts) up-down futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "T1U" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Interest Rate",
                 "product" : "T1U",
                 "productName" : "2-year usd deliverable interest rate swap futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                     "MDR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Energy",
        "product" : "MDR",
        "productName" : "miso texas hub day-ahead peak daily fixed price future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
        }
    },
      "MH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MH",
          "productName" : "los angeles carbob gasoline (opis) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "MDS" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Energy",
                 "product" : "MDS",
                 "productName" : "miso texas hub day-ahead off-peak daily fixed price future",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
                 }
             },
                     "MO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MO",
        "productName" : "mars (argus) trade month options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "MP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "MP",
          "productName" : "dollar based currency pairs british pound us dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "N7" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "N7",
                 "productName" : "algonquin city-gates natural gas (platts gas daily platts iferc) index futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "MEB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MEB",
        "productName" : "mini gasoline euro-bob oxy nwe barges (argus) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "MX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MX",
          "productName" : "mars (argus) financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "MEE" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "MEE",
                 "productName" : "mini european naphtha (platts) balmo futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "FXD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "FXD",
        "productName" : "fx$index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "MEO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MEO",
          "productName" : "mini gasoline euro-bob oxy nwe barges (argus) options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "NG" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "NG",
                  "productName" : "henry hub natural gas futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                     "MEU"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Equities",
        "product" : "MEU",
        "productName" : "mini msci euro index future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
        }
    },
      "NJ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "NJ",
          "productName" : "san juan natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"},
                  {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"},
                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"}
              ]
          }
      },
             "KAU" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "FX",
                 "product" : "KAU",
                 "productName" : "dollar based currency pairs aus. dollar us dollar",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                     "NL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NL",
        "productName" : "ngpl mid-con natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "DTN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "DTN",
          "productName" : "demarc natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "NM" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "NM",
                  "productName" : "tennessee 500 leg natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "NN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NN",
        "productName" : "henry hub natural gas last day financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "NQ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Equities",
          "product" : "NQ",
          "productName" : "e-mini nasdaq 100 futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "NR" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "NR",
                 "productName" : "rockies natural gas (platts iferc) basis futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "NS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NS",
        "productName" : "socal natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "NT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "NT",
          "productName" : "dollar based currency pairs us dollar norw. krone",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "NV" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "NV",
                 "productName" : "kern river natural gas (platts iferc) basis futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "QNE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "QNE",
        "productName" : "e-mini nasdaq 100 end-of-month futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "NW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "NW",
          "productName" : "waha natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "NX" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "NX",
                 "productName" : "texas eastern zone m-3 natural gas (platts iferc) basis futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "MFF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MFF",
        "productName" : "coal (api4) fob richards bay (argus-mccloskey) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "OB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "OB",
          "productName" : "rbob gasoline physical options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
             "DUE" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CMED",
                 "category" : "Energy",
                 "product" : "DUE",
                 "productName" : "dutch ttf natural gas (icis heren) calendar month future",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "MFO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MFO",
        "productName" : "coal (api 4) fob richards bay (argus mccloskey) options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "OH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "OH",
          "productName" : "ny harbor ulsd option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
             "OI" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "OI",
                 "productName" : "ngpl texok natural gas (platts gas daily platts iferc) index options",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
                     "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
                 }
             },
                    "OJ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Agriculture",
        "product" : "OJ",
        "productName" : "fcoj-a futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-02T08:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "MFS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "MFS",
          "productName" : "michcon natural gas (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"},
                  {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"},
                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"}
              ]
          }
      },
              "MFU" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Equities",
                  "product" : "MFU",
                  "productName" : "mini msci eafe net total return (ntr) index future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                  }
              },
                      "E6M"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "E6M",
        "productName" : "mini japan cf naphtha (platts) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ON" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ON",
          "productName" : "natural gas options (american)",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
             "KBX" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "FX",
                 "product" : "KBX",
                 "productName" : "dollar based currency pairs brazilian real us dollar",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                     "BR7"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "BR7",
        "productName" : "gasoline euro-bob oxy nwe barges (argus) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "SSF" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Metals",
          "product" : "SSF",
          "productName" : "steel billet, fob black sea (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "OKE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Agriculture",
                  "product" : "OKE",
                  "productName" : "kc hrw wheat options",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                          {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                      ],
                      "regularMarket" : [
                          {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                          {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                      ],
                      "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
                  }
              },
                      "MGC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "COMEX",
        "category" : "Metals",
        "product" : "MGC",
        "productName" : "e-micro gold futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "SSI" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "SSI",
          "productName" : "coal (api 8) cfr south china (argus mccloskey) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "_8BN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "8BN",
                  "productName" : "texas eastern, wla natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                       "OX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "OX",
        "productName" : "ngpl texok natural gas (platts gas daily) swing options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "MGE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "MGE",
          "productName" : "mini msci europe growth index future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
              "SSO" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Energy",
                  "product" : "SSO",
                  "productName" : "spp south hub real-time off-peak daily fixed price future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
                  }
              },
                      "DVA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "DVA",
        "productName" : "ventura natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "MGH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MGH",
          "productName" : "gulf coast no. 6 fuel oil (platts) crack spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "FZE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Energy",
                  "product" : "FZE",
                  "productName" : "ethanol forward month futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "PA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Metals",
        "product" : "PA",
        "productName" : "palladium futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "SSR" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Energy",
          "product" : "SSR",
          "productName" : "spp south hub real-time peak daily fixed price future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
          }
      },
              "PC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "FX",
                  "product" : "PC",
                  "productName" : "cross currency pairs british pound sterling canadian dollar futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                     "PD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "PD",
        "productName" : "ngpl texok natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "SSU" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "SSU",
          "productName" : "sumas natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "PE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "PE",
                  "productName" : "demarc natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "PF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "PF",
        "productName" : "ventura natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "PH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PH",
          "productName" : "panhandle natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "PK" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "FX",
                 "product" : "PK",
                 "productName" : "cross currency pairs british pound sterling norwegian krone futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                    "KCU"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "KCU",
        "productName" : "dollar based currency pairs colombian peso us dollar",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "PL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Metals",
          "product" : "PL",
          "productName" : "platinum futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "BRL" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CMED",
                 "category" : "FX",
                 "product" : "BRL",
                 "productName" : "u.s. dollar   brazilian real (usd brl) cash settled future",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                     "PM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "PM",
        "productName" : "permian natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "KCW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Agriculture",
          "product" : "KCW",
          "productName" : "weekly coffee \"c\" options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-02T03:30:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-03T03:30:00-04:00", "end" : "2024-06-03T14:00:00-04:00"} ]
          }
      },
              "PO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Metals",
        "product" : "PO",
        "productName" : "platinum option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T13:05:00-04:00"} ]
        }
    },
      "DVS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "DVS",
          "productName" : "sumas natural gas (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "PS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "FX",
                  "product" : "PS",
                  "productName" : "cross currency pairs british pound sterling swedish krona futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                     "OLD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Agriculture",
        "product" : "OLD",
        "productName" : "short-dated option on new crop soybean oil options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [
                {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
            ],
            "regularMarket" : [
                {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
            ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
        }
    },
      "PW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PW",
          "productName" : "enable natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "PX" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "PX",
                 "productName" : "ngpl mid-con natural gas (platts gas daily) swing futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "Q9"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "Q9",
        "productName" : "florida gas, zone 3 natural gas (platts gas daily platts iferc) index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "PY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PY",
          "productName" : "chicago natural gas (platts iferc) \"pipe\" option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
             "STI" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "STI",
                 "productName" : "singapore fuel oil 380 cst (platts) 6.35 dubai (platts) crack spread futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "ZAR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "ZAR",
        "productName" : "u.s. dollar south african rand futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "PZ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "PZ",
          "productName" : "cross currency pairs british pound sterling south african rand futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "STL" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "STL",
                 "productName" : "singapore gasoil 10 ppm (platts) balmo futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "MHE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MHE",
        "productName" : "mini middle east hsfo 180 cst fob arab gulf (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "T5N" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "T5N",
          "productName" : "ngpl stx natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "_8EN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "8EN",
                  "productName" : "transco zone 1 natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                       "QA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "QA",
        "productName" : "cross currency pairs british pound sterling australian dollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "STR" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "STR",
          "productName" : "singapore fuel oil 180 cst (platts) 6.35 brent crack spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "QC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "COMEX",
                  "category" : "Metals",
                  "product" : "QC",
                  "productName" : "e-mini copper futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "C4D"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "C4D",
        "productName" : "daily mont belvieu normal butane (non-ldh) (opis) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ZAY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ZAY",
          "productName" : "rbob gasoline 1 month calendar spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "QG" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "QG",
                  "productName" : "e-mini natural gas futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "A0F"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A0F",
        "productName" : "mini singapore fuel oil 180 cst (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "QH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "QH",
          "productName" : "e-mini ny harbor ulsd futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "QI" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "COMEX",
                 "category" : "Metals",
                 "product" : "QI",
                 "productName" : "miny silver futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "MHS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MHS",
        "productName" : "mini middle east hsfo 380 cst fob arab gulf (platts) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "STY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "STY",
          "productName" : "singapore fuel oil 180 cst (platts) 6.35 dubai (platts) crack spread balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "QM" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "QM",
                  "productName" : "e-mini crude oil futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "QO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "COMEX",
        "category" : "Metals",
        "product" : "QO",
        "productName" : "miny gold futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "QP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "QP",
          "productName" : "powder river basin coal (platts otc broker index) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "QU" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "QU",
                 "productName" : "e-mini rbob gasoline futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "BSW"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Agriculture",
        "product" : "BSW",
        "productName" : "black sea wheat futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T02:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-03T02:00:00-04:00", "end" : "2024-06-03T13:15:00-04:00"} ]
        }
    },
      "OMD" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "OMD",
          "productName" : "short-dated option on new crop soybean meal options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
          }
      },
              "OMM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "OMM",
        "productName" : "ontario peak calendar-month options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "RA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "RA",
          "productName" : "rbob gasoline average price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "RB" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "RB",
                 "productName" : "rbob gasoline physical futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "KEJ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "KEJ",
        "productName" : "euro currency pairs euro japanese yen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "RE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "RE",
          "productName" : "russian export blend crude oil (rebco) physical futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "RF" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CME",
                 "category" : "FX",
                 "product" : "RF",
                 "productName" : "euro swiss franc futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [
                         {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"},
                         {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"}
                     ],
                     "regularMarket" : [
                         {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"},
                         {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"}
                     ]
                 }
             },
                    "KEO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "KEO",
        "productName" : "dollar based currency pairs euro us dollar",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "A1D" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A1D",
          "productName" : "rbob gasoline balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "RG" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Equities",
                  "product" : "RG",
                  "productName" : "russell 1000 growth index mini futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                  }
              },
                     "MIR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "MIR",
        "productName" : "e-micro indian rupee usd futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "KEP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KEP",
          "productName" : "euro currency pairs euro canadian dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "A1G" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A1G",
                  "productName" : "ny harbor ulsd balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "KET" : {
                          "date" : "2024-06-03",
                          "marketType" : "FUTURE",
                          "exchange" : "CBOT",
                          "category" : "Agriculture",
                          "product" : "KET",
                          "productName" : "kc hrw wheat tas futures",
                          "isOpen" : true,
                          "sessionHours" : {
                              "preMarket" : [
                                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                              ],
                              "regularMarket" : [
                                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                              ]
                          }
                      },
                              "A1K"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A1K",
        "productName" : "gulf coast unl 87 (platts) up-down balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "IAU" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "IAU",
          "productName" : "millions fx australian dollar   u.s. dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "A1L" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A1L",
                  "productName" : "gulf coast ulsd (platts) up-down balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "A1M"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A1M",
        "productName" : "gulf coast jet (platts) up-down balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "RP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "RP",
          "productName" : "euro british pound futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "A1P" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "A1P",
                 "productName" : "singapore mogas 92 unleaded (platts) balmo futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "IAY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "IAY",
        "productName" : "natural gas 1 month calendar spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "A1Q" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A1Q",
          "productName" : "ny jet fuel (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "A1R" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A1R",
                  "productName" : "propane non-ldh mont belvieu (opis) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "RT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "RT",
        "productName" : "rbob gasoline bullet futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "RV" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "RV",
          "productName" : "russell 1000 value index mini futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
             "RX" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Equities",
                 "product" : "RX",
                 "productName" : "dow jones real estate futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
                 }
             },
                    "RY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "RY",
        "productName" : "euro japanese yen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "T7K" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "T7K",
          "productName" : "gasoline euro-bob oxy nwe barges (argus) crack spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ZCT" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Agriculture",
                  "product" : "ZCT",
                  "productName" : "corn tas futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                          {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                      ],
                      "regularMarket" : [
                          {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                          {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                      ]
                  }
              },
                      "IBE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "IBE",
        "productName" : "brent (euro denominated) financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ZCW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "ZCW",
          "productName" : "chicago srw wheat-corn intercommodity spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
          }
      },
              "SB" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Agriculture",
                  "product" : "SB",
                  "productName" : "sugar no. 11 futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-02T03:30:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-03T04:30:00-04:00", "end" : "2024-06-03T14:00:00-04:00"} ]
                  }
              },
                     "MJN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MJN",
        "productName" : "mini japan cf naphtha (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "SE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "SE",
          "productName" : "singapore fuel oil 380 cst (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "SF" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Agriculture",
                 "product" : "SF",
                 "productName" : "sugar no. 16 futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T08:45:00-04:00", "end" : "2024-06-02T09:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-03T10:00:00-04:00", "end" : "2024-06-03T14:00:00-04:00"} ]
                 }
             },
                    "SG"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "SG",
        "productName" : "sp 500 growth futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "SH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "SH",
          "productName" : "dominion, south point natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "SI" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "COMEX",
                 "category" : "Metals",
                 "product" : "SI",
                 "productName" : "silver futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                    "IBO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Agriculture",
        "product" : "IBO",
        "productName" : "us soybean oil futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "SJ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "SJ",
          "productName" : "san juan natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "SL" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "SL",
                 "productName" : "permian natural gas (platts gas daily) swing futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "IBS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "IBS",
        "productName" : "brent (singapore marker) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "IBV" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Equities",
          "product" : "IBV",
          "productName" : "usd-denominated ibovespa index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T05:00:00-04:00", "end" : "2024-06-02T07:15:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-03T07:15:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "SO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "COMEX",
        "category" : "Metals",
        "product" : "SO",
        "productName" : "silver options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:25:00-04:00", "end" : "2024-06-03T13:25:00-04:00"} ]
        }
    },
      "SP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Equities",
          "product" : "SP",
          "productName" : "sp 500 futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T16:00:00-04:00", "end" : "2024-06-02T16:30:00-04:00"},
                  {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"}
              ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
          }
      },
             "MJY" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CME",
                 "category" : "FX",
                 "product" : "MJY",
                 "productName" : "e-micro japanese yen american dollar futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                     "A30"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A30",
        "productName" : "european jet kerosene cargoes cif nwe (platts) average price option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "SS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "SS",
          "productName" : "chicago natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"},
                  {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"},
                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"}
              ]
          }
      },
             "BUS" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Metals",
                 "product" : "BUS",
                 "productName" : "u.s. midwest busheling ferrous scrap (amm) futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "SU"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "SU",
        "productName" : "sp 500 value futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "SV" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "SV",
          "productName" : "panhandle natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "T7" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "T7",
                 "productName" : "tennessee 500 leg natural gas (platts gas daily) swing futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "MKC" : {
                        "date" : "2024-06-03",
                        "marketType" : "FUTURE",
                        "exchange" : "CBOT",
                        "category" : "Agriculture",
                        "product" : "MKC",
                        "productName" : "mini-sized kc hrw wheat futures",
                        "isOpen" : true,
                        "sessionHours" : {
                            "preMarket" : [
                                {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                                {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                            ],
                            "regularMarket" : [
                                {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:45:00-04:00"},
                                {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                            ]
                        }
                    },
                            "OOD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "OOD",
        "productName" : "ontario off-peak calendar-day options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "T9" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "T9",
          "productName" : "socal city-gate natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "SY" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "FX",
                 "product" : "SY",
                 "productName" : "waha natural gas (platts gas daily) swing futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [
                         {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"},
                         {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"}
                     ],
                     "regularMarket" : [
                         {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"},
                         {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"}
                     ]
                 }
             },
                    "ICA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ICA",
        "productName" : "indonesian coal (mccloskey sub-bituminous) average price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "KGB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KGB",
          "productName" : "euro currency pairs euro british pound futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "ICC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "ICC",
                  "productName" : "indonesian coal (mccloskey sub-bituminous) calendar futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ICD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ICD",
        "productName" : "light sweet crude oil (wti) daily physical futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "TC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "TC",
          "productName" : "columbia gas tco (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "TF" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Equities",
                 "product" : "TF",
                 "productName" : "russell 2000 index mini futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                 }
             },
                    "TH"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "TH",
        "productName" : "freight route tc5 (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ICN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Agriculture",
          "product" : "ICN",
          "productName" : "us corn futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "A3G" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A3G",
                  "productName" : "premium unleaded gasoline 10 ppm fob med (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "TK"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "TK",
        "productName" : "freight route td7 (baltic) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "MKW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "MKW",
          "productName" : "mgex-kc hrw wheat intercommodity spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
          }
      },
              "XAB" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Equities",
                  "product" : "XAB",
                  "productName" : "e-mini materials select sector futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
                  }
              },
                      "TL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "TL",
        "productName" : "freight route td3 (baltic) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "TM" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "TM",
          "productName" : "freight route tc2 (baltic) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "XAD" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CME",
                 "category" : "FX",
                 "product" : "XAD",
                 "productName" : "australian dollar option (european)",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
                     "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
                 }
             },
                     "A3M"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A3M",
        "productName" : "mont belvieu physical normal butane (opis) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "XAC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "XAC",
          "productName" : "algonquin natural gas (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XAF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Equities",
                  "product" : "XAF",
                  "productName" : "e-mini financial select sector futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
                  }
              },
                      "A3N"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A3N",
        "productName" : "mont belvieu physical ldh propane (opis) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "XAE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Equities",
          "product" : "XAE",
          "productName" : "e-mini energy select sector futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
          }
      },
              "A3Q" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A3Q",
                  "productName" : "mont belvieu physical ethane (opis) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "TT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Agriculture",
        "product" : "TT",
        "productName" : "cotton futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "A3R" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A3R",
          "productName" : "mont belvieu physical natural gasoline (opis) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XAI" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Equities",
                  "product" : "XAI",
                  "productName" : "e-mini industrial select sector futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
                  }
              },
                      "XAK"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "XAK",
        "productName" : "e-mini technology select sector futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "A3U" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A3U",
          "productName" : "european low sulphur gasoil brent crack average price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "U8" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "U8",
                  "productName" : "cig rockies natural gas (platts gas daily) swing futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "A47"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A47",
        "productName" : "pjm meted zone peak calendar-month day-ahead lmp futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "U9" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "U9",
          "productName" : "low sulphur gasoil balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "A3W" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "A3W",
                 "productName" : "ny harbor ulsd crack spread average price option",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
                     "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
                 }
             },
                     "XAP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "XAP",
        "productName" : "e-mini consumer staples select sector futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "A49" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A49",
          "productName" : "pjm penelec zone peak calendar-month day-ahead lmp futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "TZ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "TZ",
        "productName" : "transco zone 6 natural gas (platts iferc) \"pipe\" option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "MLE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "MLE",
          "productName" : "mini msci emerging markets latin america index future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
              "A3Y" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A3Y",
                  "productName" : "rbob gasoline crack spread average price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "XAV"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "XAV",
        "productName" : "e-mini health care select sector futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "UA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "UA",
          "productName" : "singapore fuel oil 180 cst (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "UB" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Interest Rate",
                 "product" : "UB",
                 "productName" : "ultra u.s. treasury bond futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                    "XAU"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "XAU",
        "productName" : "e-mini utilities select sector futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "OPO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "OPO",
          "productName" : "ontario peak calendar-day options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "XAY" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Equities",
                  "product" : "XAY",
                  "productName" : "e-mini consumer discretionary select sector futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
                  }
              },
                      "A4D"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A4D",
        "productName" : "natural gas summer strip futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "A4H" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A4H",
          "productName" : "mont belvieu ldh propane (opis) average price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "A4J" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A4J",
                  "productName" : "mont belvieu ethane (opis) average price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "A4K"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A4K",
        "productName" : "mont belvieu normal butane (opis) average price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "UN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "UN",
          "productName" : "european naphtha cargoes cif nwe (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "V2" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Equities",
                 "product" : "V2",
                 "productName" : "russell 2000 value index mini futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                 }
             },
                    "A50"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A50",
        "productName" : "pjm penelec zone off-peak calendar-month day-ahead lmp futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "UR" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "UR",
          "productName" : "european jet kerosene barges fob rdam (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "A4S" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "A4S",
                 "productName" : "pjm western hub 50 mw peak calendar-month real-time lmp futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "V7"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "V7",
        "productName" : "argus wti trade month futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "UX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Metals",
          "product" : "UX",
          "productName" : "uxc uranium u3o8 futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "MME" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Equities",
                 "product" : "MME",
                 "productName" : "mini middle east naphtha fob arab gulf (platts) futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [
                         {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"},
                         {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"}
                     ],
                     "regularMarket" : [ {"start" : "2024-06-02T21:00:00-04:00", "end" : "2024-06-03T19:00:00-04:00"} ]
                 }
             },
                     "A4W"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A4W",
        "productName" : "michcon natural gas (platts iferc) basis option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "VC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "VC",
          "productName" : "dollar based currency pairs us dollar czech koruna",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "MMN" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Equities",
                 "product" : "MMN",
                 "productName" : "mini msci emerging markets net total return (ntr) index future",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                 }
             },
                     "IEJ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "IEJ",
        "productName" : "millions fx euro   japanese yen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "IEO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "IEO",
          "productName" : "millions fx euro   u.s. dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "VI" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "VI",
                  "productName" : "ventura natural gas (platts gas daily platts iferc) index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "IEP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "IEP",
        "productName" : "millions fx euro   canadian dollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "MMW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "MMW",
          "productName" : "mini msci acwi ntr index future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
              "KIU" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "FX",
                  "product" : "KIU",
                  "productName" : "dollar based currency pairs indian rupee us dollar",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "A5K"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A5K",
        "productName" : "panhandle natural gas (platts iferc) basis option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "W0" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "W0",
          "productName" : "singapore mogas 95 unleaded (platts) balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "A5N" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "A5N",
                 "productName" : "texas eastern zone m-3 natural gas (platts iferc) basis option",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
                     "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
                 }
             },
                     "A5O"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A5O",
        "productName" : "waha, texas basis swap options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "VU" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "VU",
          "productName" : "dollar based currency pairs us dollar hungarian forint",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "MNB" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "MNB",
                 "productName" : "mont belvieu normal butane ldh (opis) futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "W9"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "W9",
        "productName" : "malin natural gas (platts gas daily) swing futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "MNC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MNC",
          "productName" : "mini european naphtha cif nwe (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "MNF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Equities",
                  "product" : "MNF",
                  "productName" : "e-mini cnx nifty index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T17:00:00-04:00", "end" : "2024-06-02T18:00:00-04:00"},
                          {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"},
                          {"start" : "2024-06-02T22:30:00-04:00", "end" : "2024-06-02T23:30:00-04:00"}
                      ],
                      "regularMarket" : [
                          {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"},
                          {"start" : "2024-06-03T18:00:00-04:00", "end" : "2024-06-03T22:30:00-04:00"},
                          {"start" : "2024-06-02T23:30:00-04:00", "end" : "2024-06-03T17:15:00-04:00"}
                      ]
                  }
              },
                      "MNH"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "MNH",
        "productName" : "e-micro size usd offshore rmb (cnh) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "SZN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "SZN",
          "productName" : "southern natural, louisiana natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "GBA" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "GBA",
                  "productName" : "gulf coast jet (argus) up-down balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "MNG"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MNG",
        "productName" : "henry hub natural gas last day physically-delivered futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "A6F" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A6F",
          "productName" : "crude oil calendar strip futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "_1E" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "1E",
                  "productName" : "rbob gasoline crack spread balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "GBP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "GBP",
        "productName" : "british pound   u.s. dollar (gbp usd) physically deliverable future (cls eligible)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "A6I" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A6I",
          "productName" : "natural gas winter strip futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "A6J" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A6J",
                  "productName" : "natural gas calendar strip futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "GBR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "GBR",
        "productName" : "daily gasoline euro-bob oxy nwe barges (argus) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "_1H" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "1H",
          "productName" : "ny harbor ulsd crack spread balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "X0" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "X0",
                  "productName" : "singapore mogas 97 unleaded (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "MNY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "MNY",
        "productName" : "e-micro usd chinese renminbi futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "_1J" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "1J",
          "productName" : "gulf coast unl 87 (platts) crack spread balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "A6O"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A6O",
        "productName" : "pjm electricity option on calendar options strip options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "WS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "WS",
          "productName" : "crude oil financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "X7" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "X7",
                 "productName" : "ulsd 10ppm cif med (platts) balmo futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "_1S"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "1S",
        "productName" : "propane non-ldh mont belvieu (opis) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "X8" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "X8",
          "productName" : "texas eastern, wla natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "OSD" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Agriculture",
                 "product" : "OSD",
                 "productName" : "short-dated new crop soybean options",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [
                         {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                         {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                     ],
                     "regularMarket" : [
                         {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                         {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                     ],
                     "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
                 }
             },
                     "X9"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "X9",
        "productName" : "jet fuel barges fob rdam (platts) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "_1T" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "1T",
          "productName" : "jet aviation fuel cargoes fob med (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "IGB" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "FX",
                  "product" : "IGB",
                  "productName" : "millions fx euro   british pound futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "_27"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "27",
        "productName" : "rbob gasoline last day financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "_29" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "29",
          "productName" : "argus sour crude index (\"asci\") trade month futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "GCE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "GCE",
                  "productName" : "gasoline euro-bob oxy nwe barges (argus) crack spread average price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "XB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "XB",
        "productName" : "british pound option (european)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "GCG" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "GCG",
          "productName" : "gulf coast cbob gasoline a2 (platts) crack spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Agriculture",
                  "product" : "XC",
                  "productName" : "mini-corn futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                          {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                      ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
                  }
              },
                     "XD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "XD",
        "productName" : "canadian dollar option (european)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "GCK" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "GCK",
          "productName" : "gold kilo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "A7E" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A7E",
                  "productName" : "argus propane far east index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "GCM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "GCM",
        "productName" : "gulf coast unl 87 gasoline m2 (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "XH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "XH",
          "productName" : "panhandle natural gas (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "_2C" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "2C",
                 "productName" : "chicago cbob gasoline (platts) futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "A7G"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A7G",
        "productName" : "dated brent (platts) daily futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "XJ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "XJ",
          "productName" : "japanese yen option (european)",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
          }
      },
             "XK" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Agriculture",
                 "product" : "XK",
                 "productName" : "mini soybean futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [
                         {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                         {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                     ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
                 }
             },
                    "A7I"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A7I",
        "productName" : "gasoline euro-bob oxy nwe barges (argus) crack spread balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "BZL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "BZL",
          "productName" : "brent crude oil london trade at marker futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "OSX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "OSX",
        "productName" : "brent last day financial options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "A7L" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A7L",
          "productName" : "premium unleaded gasoline 10 ppm barges fob rdam (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "XN",
                  "productName" : "socal natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "XO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "XO",
        "productName" : "chicago natural gas (platts iferc) fixed price options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "GCT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "GCT",
          "productName" : "gold tas futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [
                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T13:30:00-04:00"},
                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"}
              ],
              "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T13:30:00-04:00"} ]
          }
      },
              "XQ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "XQ",
                  "productName" : "pge citygate natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "BZS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "BZS",
        "productName" : "brent crude oil singapore trade at marker futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "QXB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "QXB",
          "productName" : "csx coal (platts otc broker index) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XR" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "XR",
                  "productName" : "rockies natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "XS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "XS",
        "productName" : "swiss franc option (european)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "A7Q" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A7Q",
          "productName" : "mont belvieu natural gasoline (opis) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "XT",
        "productName" : "euro fx option (european)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "BZT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "BZT",
          "productName" : "brent crude oil last day tas futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "N1B" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "N1B",
                  "productName" : "singapore mogas 92 unleaded (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "Y7"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "Y7",
        "productName" : "tennessee 500 leg natural gas (platts gas daily platts iferc) index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "XW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "XW",
          "productName" : "mini-sized chicago srw wheat futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
          }
      },
             "Y8" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "Y8",
                 "productName" : "michcon natural gas (platts gas daily platts iferc) index futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                    "XX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "XX",
        "productName" : "san juan natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "Y9" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "Y9",
          "productName" : "texas gas, zone 1 natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "_37" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "37",
                 "productName" : "argus sour crude index (\"asci\") calendar month futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "XZ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "XZ",
        "productName" : "transco zone 6 natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "N1E" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Interest Rate",
          "product" : "N1E",
          "productName" : "10-year euro deliverable interest rate swap futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T03:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-03T03:00:00-04:00", "end" : "2024-06-03T11:00:00-04:00"} ]
          }
      },
              "MPE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "MPE",
                  "productName" : "middle east gasoil fob arab gulf (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "VAQ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "VAQ",
        "productName" : "australian dollar quarterly variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "YA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "YA",
          "productName" : "cross currency pairs australian dollar japanese yen futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "GDF" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "Metals",
                 "product" : "GDF",
                 "productName" : "nyse arca gold miners index future",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                 }
             },
                     "VAS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "VAS",
        "productName" : "australian dollar semi-annual variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "MPP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "MPP",
          "productName" : "mini msci pan-euro index future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
              "A8C" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A8C",
                  "productName" : "mont belvieu ethane (opis) balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "YF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "YF",
        "productName" : "ny heating oil (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "YG" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Metals",
          "product" : "YG",
          "productName" : "mini-gold future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T21:00:00-04:00", "end" : "2024-06-03T19:00:00-04:00"} ]
          }
      },
             "GDK" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CME",
                 "category" : "Agriculture",
                 "product" : "GDK",
                 "productName" : "class iv milk futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                     "VAY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "VAY",
        "productName" : "australian dollar annual variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "YI" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Metals",
          "product" : "YI",
          "productName" : "mini-silver future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T21:00:00-04:00", "end" : "2024-06-03T19:00:00-04:00"} ]
          }
      },
             "A8G" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "A8G",
                 "productName" : "premium unleaded gasoline 10 ppm fob med (platts) balmo futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "A8H"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A8H",
        "productName" : "singapore fuel oil 380 cst (platts) average price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "A8I" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A8I",
          "productName" : "mont belvieu iso-butane (opis) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "N1U" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Interest Rate",
                  "product" : "N1U",
                  "productName" : "10-year usd deliverable interest rate swap futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T03:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-03T03:00:00-04:00", "end" : "2024-06-03T11:00:00-04:00"} ]
                  }
              },
                      "GE0"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Interest Rate",
        "product" : "GE0",
        "productName" : "eurodollar 1yr mc futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "MPU" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "MPU",
          "productName" : "mini msci europe value index future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
              "A8J" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "A8J",
                  "productName" : "mont belvieu normal butane (opis) balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "YM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Equities",
        "product" : "YM",
        "productName" : "e-mini dow ($5) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "A8K" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A8K",
          "productName" : "conway propane (opis) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "MPX" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "MPX",
                  "productName" : "ny harbor ulsd financial futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "XFC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "XFC",
        "productName" : "florida gas zone 3 natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "A8L" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A8L",
          "productName" : "conway natural gasoline (opis) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "YO" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Agriculture",
                  "product" : "YO",
                  "productName" : "no. 11 sugar options",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "A8M"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "A8M",
        "productName" : "conway normal butane (opis) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "A8O" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A8O",
          "productName" : "mont belvieu ldh propane (opis) balmo options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "YS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "YS",
                  "productName" : "ny ulsd (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                     "OUB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Interest Rate",
        "product" : "OUB",
        "productName" : "ultra u.s. treasury bond options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "Z8" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "Z8",
          "productName" : "cig rockies natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
             "YZ" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "ICE",
                 "category" : "FX",
                 "product" : "YZ",
                 "productName" : "euro currency pairs euro south african rand futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                    "VBQ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "VBQ",
        "productName" : "brent crude oil quarterly variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "KMF" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KMF",
          "productName" : "dollar based currency pairs swiss franc us dollar",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "VBS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "VBS",
                  "productName" : "brent crude oil semi-annual variance futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ZB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Interest Rate",
        "product" : "ZB",
        "productName" : "u.s. treasury bond futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "ZC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "ZC",
          "productName" : "corn futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
          }
      },
             "EAD" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CME",
                 "category" : "FX",
                 "product" : "EAD",
                 "productName" : "euro australian dollar futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                     "EAF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "EAF",
        "productName" : "in delivery month european union allowance (eua) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ZF" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Interest Rate",
          "product" : "ZF",
          "productName" : "5-year t-note futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "VBY" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "NYMEX",
                 "category" : "Energy",
                 "product" : "VBY",
                 "productName" : "brent crude oil annual variance futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                 }
             },
                     "ZG"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Metals",
        "product" : "ZG",
        "productName" : "100oz gold future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T21:00:00-04:00", "end" : "2024-06-03T19:00:00-04:00"} ]
        }
    },
      "KMP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KMP",
          "productName" : "dollar based currency pairs mexican peso us dollar",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "ZI" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Metals",
                  "product" : "ZI",
                  "productName" : "5000oz silver future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T21:00:00-04:00", "end" : "2024-06-03T19:00:00-04:00"} ]
                  }
              },
                     "_4C"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "4C",
        "productName" : "chicago ulsd (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ZJ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "ZJ",
          "productName" : "cross currency pairs new zealand dollar japanese yen futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "ZL" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Agriculture",
                 "product" : "ZL",
                 "productName" : "soybean oil futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [
                         {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                         {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                     ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
                 }
             },
                    "ZM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Agriculture",
        "product" : "ZM",
        "productName" : "soybean meal futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [
                {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
            ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
        }
    },
      "ZN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Interest Rate",
          "product" : "ZN",
          "productName" : "10-year t-note futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
             "ZO" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Agriculture",
                 "product" : "ZO",
                 "productName" : "oats options",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [
                         {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                         {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                     ],
                     "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
                 }
             },
                    "XGC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "XGC",
        "productName" : "florida gas zone 2 natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "A9N" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "A9N",
          "productName" : "argus propane (saudi aramco) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ZQ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Interest Rate",
                  "product" : "ZQ",
                  "productName" : "30 day federal funds futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                     "ZR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Agriculture",
        "product" : "ZR",
        "productName" : "rough rice futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [
                {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"},
                {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"}
            ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
        }
    },
      "ZS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "ZS",
          "productName" : "soybean futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
          }
      },
             "ZT" : {
                 "date" : "2024-06-03",
                 "marketType" : "FUTURE",
                 "exchange" : "CBOT",
                 "category" : "Interest Rate",
                 "product" : "ZT",
                 "productName" : "2-year t-note futures",
                 "isOpen" : true,
                 "sessionHours" : {
                     "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                     "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                 }
             },
                    "ZW"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Agriculture",
        "product" : "ZW",
        "productName" : "chicago srw wheat futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [
                {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
            ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"} ]
        }
    },
      "EAX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "EAX",
          "productName" : "in delivery month european union allowance (eua) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "_4U" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "4U",
                  "productName" : "gulf coast heating oil (argus) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "MRG"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Equities",
        "product" : "MRG",
        "productName" : "mini msci usa growth index future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
        }
    },
      "_4Y" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "4Y",
          "productName" : "ny jet fuel (argus) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "GFC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "GFC",
                  "productName" : "gulf coast no. 6 fuel oil (platts) crack spread balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "_5E"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "5E",
        "productName" : "henry hub natural gas (platts iferc) basis option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "EBP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "EBP",
          "productName" : "euro   british pound (eur gbp) physically deliverable future (cls eligible)",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "_5I"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "5I",
        "productName" : "rockies natural gas (platts iferc) basis option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "_5H" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "5H",
          "productName" : "ngpl texok natural gas (platts iferc) basis option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "GFT" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Agriculture",
                  "product" : "GFT",
                  "productName" : "feeder cattle tas futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T07:00:00-04:00", "end" : "2024-06-02T10:05:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-03T10:05:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "_5L"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "5L",
        "productName" : "mini singapore fuel oil 180 cst (platts) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "OWD" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "OWD",
          "productName" : "short dated new crop chicago srw wheat options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
          }
      },
              "MSE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "MSE",
                  "productName" : "mini middle east hsfo 380 cst fob arab gulf (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "MSG"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MSG",
        "productName" : "mini singapore gasoil (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "MSF" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "MSF",
          "productName" : "e-micro swiss franc american dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "_5Y" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "5Y",
                  "productName" : "ny ulsd (argus) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ZLT" : {
                          "date" : "2024-06-03",
                          "marketType" : "FUTURE",
                          "exchange" : "CBOT",
                          "category" : "Agriculture",
                          "product" : "ZLT",
                          "productName" : "soybean oil tas futures",
                          "isOpen" : true,
                          "sessionHours" : {
                              "preMarket" : [
                                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                              ],
                              "regularMarket" : [
                                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                              ]
                          }
                      },
                              "ECD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "ECD",
        "productName" : "euro canadian dollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "KOL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KOL",
          "productName" : "euro currency pairs euro norwegian krone futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "_6B" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "6B",
                  "productName" : "british pound futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "_6A"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "6A",
        "productName" : "australian dollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "ECH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "ECH",
          "productName" : "euro   chinese offshore renminbi (eur cnh) physically deliverable future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "ECK" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "ECK",
                  "productName" : "czech koruna euro (czk eur) cross rate futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "_6C"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "6C",
        "productName" : "canadian dollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "_6E" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "6E",
          "productName" : "euro fx futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "_6J" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "6J",
                  "productName" : "japanese yen futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "VEA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "VEA",
        "productName" : "euro annual variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "MSX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MSX",
          "productName" : "anr, louisiana natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XIC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "XIC",
                  "productName" : "cig rockies natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "_6L"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "6L",
        "productName" : "brazilian real futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "_6N" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "6N",
          "productName" : "new zealand dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "_6M" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "6M",
                  "productName" : "mexican peso futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "IKX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "IKX",
        "productName" : "millions fx u.s. dollar   swedish krona futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "_6R" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "6R",
          "productName" : "russian ruble futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "MTB" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "MTB",
                  "productName" : "mini singapore fuel oil 380 cst (platts) balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "_6S"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "6S",
        "productName" : "swiss franc futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "ECZ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "ECZ",
          "productName" : "czech koruna euro (czk eur) cross rate futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "MTC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "MTC",
                  "productName" : "coal (api 2) cif ara (argus mccloskey) short dated calendar futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ILB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ILB",
        "productName" : "illinois basin coal futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "MTF" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MTF",
          "productName" : "coal (api2) cif ara (argus-mccloskey) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ZMT" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Agriculture",
                  "product" : "ZMT",
                  "productName" : "soybean meal tas futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                          {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                      ],
                      "regularMarket" : [
                          {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                          {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                      ]
                  }
              },
                      "_6Z"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "6Z",
        "productName" : "south african rand futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "VEQ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "VEQ",
          "productName" : "euro quarterly variance futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "_6Y" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "6Y",
                  "productName" : "crude oil option semi-annual strip futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "VES"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "VES",
        "productName" : "euro semi-annual variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "MTO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MTO",
          "productName" : "coal (api 2) cif ara (argus mccloskey) options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "EDK" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "FX",
                  "product" : "EDK",
                  "productName" : "euro   danish krone (eur dkk) physically deliverable future (cls eligible)",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "MTS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "MTS",
        "productName" : "mini singapore fuel oil 380 cst (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ZNC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "ZNC",
          "productName" : "zinc futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ILS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "ILS",
                  "productName" : "israeli shekel futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"},
                          {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"}
                      ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "_7N"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "7N",
        "productName" : "premium unleaded gasoline 10 ppm barges fob rdam (platts) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ZNP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ZNP",
          "productName" : "tennessee 500 leg natural gas (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ZNT" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "ZNT",
                  "productName" : "tennessee zone 0 natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "OYM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Equities",
        "product" : "OYM",
        "productName" : "e-mini dow ($5) options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "GIE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Agriculture",
          "product" : "GIE",
          "productName" : "sp-gsci er index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "IMF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "FX",
                  "product" : "IMF",
                  "productName" : "millions fx u.s. dollar   swiss franc futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "XJT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "XJT",
        "productName" : "houston ship channel natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CAD" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "CAD",
          "productName" : "u.s. dollar   canadian dollar future (usd cad) physically deliverable future (cls eligible)",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "MUN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Equities",
                  "product" : "MUN",
                  "productName" : "mini msci usa index future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                  }
              },
                      "IMP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "IMP",
        "productName" : "millions fx british pound   u.s. dollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "MV8" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "MV8",
          "productName" : "malin natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CAO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CAO",
        "productName" : "california carbon allowance (cca) options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "VGA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "VGA",
          "productName" : "gold calendar variance futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XKC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "XKC",
                  "productName" : "oneok, oklahoma natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "OZB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Interest Rate",
        "product" : "OZB",
        "productName" : "u.s. treasury bond options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "OZC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "OZC",
          "productName" : "corn options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
          }
      },
              "OZF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Interest Rate",
        "product" : "OZF",
        "productName" : "5-year t-note options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "KRA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KRA",
          "productName" : "euro currency pairs euro australian dollar futures (125)",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "TCI" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "TCI",
                  "productName" : "freight route tc5 (platts) average price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "OZL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Agriculture",
        "product" : "OZL",
        "productName" : "soybean oil options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [
                {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
            ],
            "regularMarket" : [
                {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
            ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
        }
    },
      "VGQ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "VGQ",
          "productName" : "gold quarterly variance futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "OZN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Interest Rate",
        "product" : "OZN",
        "productName" : "10-year t-note options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "OZM" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "OZM",
          "productName" : "soybean meal options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
          }
      },
              "VGS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "COMEX",
                  "category" : "Metals",
                  "product" : "VGS",
                  "productName" : "gold semi-annual variance futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "OZO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Agriculture",
        "product" : "OZO",
        "productName" : "oats options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [
                {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
            ],
            "regularMarket" : [
                {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
            ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
        }
    },
      "KRK" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KRK",
          "productName" : "euro currency pairs euro swedish krona futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "CBC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "CBC",
                  "productName" : "gulf coast cbob gasoline a1 (platts) crack spread futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "OZR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Agriculture",
        "product" : "OZR",
        "productName" : "rough rice options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [
                {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
            ],
            "regularMarket" : [
                {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
            ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
        }
    },
      "_9A" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "9A",
          "productName" : "socal city-gate natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "OZQ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Interest Rate",
        "product" : "OZQ",
        "productName" : "30 day federal funds options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "OZT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Interest Rate",
          "product" : "OZT",
          "productName" : "2-year t-note options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
          }
      },
              "OZS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Agriculture",
                  "product" : "OZS",
                  "productName" : "soybean options",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                          {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                      ],
                      "regularMarket" : [
                          {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                          {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                      ],
                      "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
                  }
              },
                      "INR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "INR",
        "productName" : "u.s. dollar   indian rupee (usd inr) cash settled future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "_9G" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "9G",
          "productName" : "in delivery month european union allowance (eua) serial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "OZW" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Agriculture",
                  "product" : "OZW",
                  "productName" : "chicago srw wheat options",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                          {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                      ],
                      "regularMarket" : [
                          {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                          {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                      ],
                      "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
                  }
              },
                      "KRU"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "KRU",
        "productName" : "dollar based currency pairs russian ruble us dollar",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "KRW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "KRW",
          "productName" : "korean won futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CBO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CBO",
        "productName" : "gulf coast cbob gasoline a1 (platts) options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "EFT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "EFT",
          "productName" : "euro   hungarian forint (eur huf) physically deliverable future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "KRZ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "FX",
                  "product" : "KRZ",
                  "productName" : "euro currency pairs euro swiss franc futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "TDE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "Energy",
        "product" : "TDE",
        "productName" : "dutch natural gas daily future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CCA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CCA",
          "productName" : "california carbon allowance (cca) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "MWL" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Equities",
                  "product" : "MWL",
                  "productName" : "mini msci world index future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
                  }
              },
                      "TDT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "TDT",
        "productName" : "freight route td3 (baltic) average price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "KSN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KSN",
          "productName" : "dollar based currency pairs japanese yen us dollar",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "KSR" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "KSR",
                  "productName" : "kern opal natural gas (platts gas daily) swing futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "GKS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "GKS",
        "productName" : "gasoline 10 ppm fob med (platts) crack spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "KSV" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "KSV",
          "productName" : "dollar based currency pairs canadian dollar us dollar",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "IPB" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "Energy",
                  "product" : "IPB",
                  "productName" : "italian power baseload (gme) calendar month future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "TEL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "TEL",
        "productName" : "tetco ela natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "_6OO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "6OO",
          "productName" : "pjm western hub real-time off-peak calendar-month 50 mw strip options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
               "GLB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Interest Rate",
        "product" : "GLB",
        "productName" : "1 month eurodollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "IPE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "Energy",
          "product" : "IPE",
          "productName" : "italian psv natural gas (icis heren) calendar month future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "EHF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "EHF",
                  "productName" : "hungarian forint euro (huf eur) cross rate futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "MXN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "MXN",
        "productName" : "u.s. dollar   mexican peso (usd mxn) physically deliverable future (cls eligible)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "VIX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CFE",
          "product" : "VIX",
          "productName" : "vix futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T16:30:00-04:00", "end" : "2024-06-02T09:30:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
          }
      },
              "GLI" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "GLI",
                  "productName" : "european low sulphur gasoil (100mt) bullet futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "IPP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "Energy",
        "product" : "IPP",
        "productName" : "italian power peakload (gme) calendar month future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ZRA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "ZRA",
          "productName" : "u.s. dollar   south african rand (usd zar) physically deliverable future (cls eligible)",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "XNC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "XNC",
                  "productName" : "ngpl texok natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "RBA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "Energy",
        "product" : "RBA",
        "productName" : "european rme biodiesel fob ara (red compliant) (argus) calendar month future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "RBC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "RBC",
          "productName" : "rbob gasoline brent crack spread average price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "EHU" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "EHU",
                  "productName" : "hungarian forint euro (huf eur) cross rate futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "RBB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "RBB",
        "productName" : "rbob gasoline brent crack spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AA7" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AA7",
          "productName" : "group three ulsd (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "RBF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "RBF",
                  "productName" : "rme biodiesel fob rdam (argus) (red compliant) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AA9"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AA9",
        "productName" : "group three sub-octane gasoline (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "VJQ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "VJQ",
          "productName" : "japanese yen quarterly variance futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "RBL" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "RBL",
                  "productName" : "rbob gasoline london trade at marker futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "VJS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "VJS",
        "productName" : "japanese yen semi-annual variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "RBR" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Metals",
          "product" : "RBR",
          "productName" : "chinese steel rebar hrb400 (mysteel) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "VJY" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "VJY",
                  "productName" : "japanese yen annual variance futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "RBT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "RBT",
        "productName" : "rbob tas futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "AAH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AAH",
          "productName" : "dubai crude oil (platts) average price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AAO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AAO",
        "productName" : "wti average price options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "AB7" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AB7",
          "productName" : "gasoil 0.1 cargoes cif nwe (platts) balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AAW" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AAW",
                  "productName" : "gulf coast unl 87 (argus) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ZST"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ZST",
        "productName" : "transco zone 6 natural gas (platts gas daily) swing futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "GND" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "Energy",
          "product" : "GND",
          "productName" : "german gaspool natural gas (icis heren) daily future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "GNF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Agriculture",
                  "product" : "GNF",
                  "productName" : "non-fat dry milk futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "GNE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "Energy",
        "product" : "GNE",
        "productName" : "german ncg natural gas (icis heren) calendar month future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "IRK" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "IRK",
          "productName" : "millions fx euro   swedish krona futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "_8XN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "8XN",
                  "productName" : "oneok, oklahoma natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                       "ZTA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ZTA",
        "productName" : "texas gas zone 1 natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ABH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ABH",
          "productName" : "ny harbor ulsd bullet futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CFI" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "CFI",
                  "productName" : "capesize timecharter average (baltic) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ABI"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ABI",
        "productName" : "dubai crude oil (platts) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CFP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CFP",
          "productName" : "columbia gas tco natural gas (platts iferc) pipe futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AC0" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AC0",
                  "productName" : "mont belvieu ethane (opis) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "IRZ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "IRZ",
        "productName" : "millions fx euro   swiss franc futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "CFS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CFS",
          "productName" : "columbia gas tco (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ABS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "ABS",
                  "productName" : "singapore fuel oil 180 cst (platts) balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ABT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ABT",
        "productName" : "singapore fuel oil 380 cst (platts) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "EJY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "EJY",
          "productName" : "euro   japanese yen (eur jpy) physically deliverable future (cls eligible)",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "ABV" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "ABV",
                  "productName" : "wti-brent crude oil spread futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "KWC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Agriculture",
        "product" : "KWC",
        "productName" : "kc hrw-chicago srw wheat intercommodity spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [
                {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
            ],
            "regularMarket" : [
                {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
            ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
        }
    },
      "ABX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ABX",
          "productName" : "singapore jet kerosene (platts) balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "KWE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Agriculture",
                  "product" : "KWE",
                  "productName" : "kc hrw wheat short-dated new crop futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                          {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                      ],
                      "regularMarket" : [
                          {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                          {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                      ],
                      "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
                  }
              },
                      "ABY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ABY",
        "productName" : "wti-brent bullet futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ZTS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ZTS",
          "productName" : "tetco stx natural gas (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XPP" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "XPP",
                  "productName" : "alberta power pool extended peak calendar-day futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "GOC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "GOC",
        "productName" : "low sulphur gasoil crack spread (1000mt) financial options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "VLS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "VLS",
          "productName" : "crude oil semi-annual variance futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "VLR" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "VLR",
                  "productName" : "crude oil quarterly variance futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ZTX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Interest Rate",
        "product" : "ZTX",
        "productName" : "two year t-note 98:99 calendar spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "CGB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CGB",
          "productName" : "conway natural gasoline (opis) balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ACD" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "ACD",
                  "productName" : "australian dollar canadian dollar futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "ISM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Agriculture",
        "product" : "ISM",
        "productName" : "us soybean meal futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "ISN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "ISN",
          "productName" : "millions fx u.s. dollar   japanese yen futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "ACM" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "ACM",
                  "productName" : "coal (api 5) fob newcastle (argus mccloskey) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ISV"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "ISV",
        "productName" : "millions fx u.s. dollar   canadian dollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "AD0" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AD0",
          "productName" : "mont belvieu normal butane (opis) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "REB" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "REB",
                  "productName" : "russian export blend crude oil (rebco) financial futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "GPB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "Energy",
        "product" : "GPB",
        "productName" : "german power baseload (epex spot) calendar month future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CHB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CHB",
          "productName" : "canadian heavy crude oil (net energy) balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "PAO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Metals",
        "product" : "PAO",
        "productName" : "palladium options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:30:00-04:00", "end" : "2024-06-03T13:00:00-04:00"} ]
        }
    },
      "CHF" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "CHF",
          "productName" : "u.s. dollar   swiss franc (usd chf) physically deliverable future (cls eligible)",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "_8ZN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "8ZN",
                  "productName" : "southern star, tx.-okla.-kan. natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                       "ELI"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "ELI",
        "productName" : "euro   turkish lira (eur try) physically deliverable future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "CHL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "CHL",
          "productName" : "us dollar chilean peso futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "VNA" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "VNA",
                  "productName" : "natural gas calendar variance futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AE7"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AE7",
        "productName" : "natural gas (henry hub) last-day financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ADW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ADW",
          "productName" : "dawn natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AE8" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AE8",
                  "productName" : "pjm dpl zone off-peak calendar-month day-ahead lmp futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AE9"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AE9",
        "productName" : "pjm eastern hub peak calendar-month day-ahead lmp futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CHY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CHY",
          "productName" : "ny harbor ulsd crack spread option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "VNQ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "VNQ",
                  "productName" : "natural gas quarterly variance futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "VNS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "VNS",
        "productName" : "natural gas semi-annual variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "EMD" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Equities",
          "product" : "EMD",
          "productName" : "e-mini sp midcap 400 futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T16:00:00-04:00", "end" : "2024-06-02T16:30:00-04:00"},
                  {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"}
              ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "PBN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "PBN",
                  "productName" : "malin natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "TK7"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "TK7",
        "productName" : "trunkline ela natural gas (platts gas daily) swing futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "TK9" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "TK9",
          "productName" : "texas eastern, ela natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AEJ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AEJ",
                  "productName" : "miso indiana hub (formerly cinergy hub) off-peak lmp futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "CIL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CIL",
        "productName" : "canadian light sweet oil (net energy) index futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CIN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CIN",
          "productName" : "cig rockies natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "XSC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "XSC",
                  "productName" : "southern natural louisiana natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "CIQ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Energy",
        "product" : "CIQ",
        "productName" : "caiso np-15 fifteen minute marker off-peak daily fixed price future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
        }
    },
      "CIP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Energy",
          "product" : "CIP",
          "productName" : "caiso np-15 fifteen minute marker peak daily fixed price future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
          }
      },
              "CIS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "CIS",
                  "productName" : "chicago natural gas (platts gas daily platts iferc) index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AF7"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AF7",
        "productName" : "low sulphur gasoil average price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ZWT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "ZWT",
          "productName" : "chicago srw wheat tas futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ]
          }
      },
              "AEZ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AEZ",
                  "productName" : "ny ethanol (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "GRD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "Energy",
        "product" : "GRD",
        "productName" : "german ncg natural gas (icis heren) daily future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "PCL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PCL",
          "productName" : "certified emission reduction (cerplus) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "GRE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "Energy",
                  "product" : "GRE",
                  "productName" : "german gaspool natural gas (icis heren) calendar month future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AFE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AFE",
        "productName" : "dated brent (platts) to frontline brent balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "RGX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "RGX",
          "productName" : "regional greenhouse gas initiative (rggi) co2 allowance futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ENK" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "ENK",
                  "productName" : "euro norwegian krone futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "VPA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "VPA",
        "productName" : "british pound annual variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "XTC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "XTC",
          "productName" : "trunkline louisiana natural gas (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ENO" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "FX",
                  "product" : "ENO",
                  "productName" : "euro   norwegian krone (eur nok) physically deliverable future (cls eligible)",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "KZX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "FX",
        "product" : "KZX",
        "productName" : "dollar based currency pairs new zealand dollar us dollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "ENS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Energy",
          "product" : "ENS",
          "productName" : "ercot non-spinning reserve future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
          }
      },
              "KZY" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "FX",
                  "product" : "KZY",
                  "productName" : "cross currency pairs swiss franc japanese yen futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "ENY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "ENY",
        "productName" : "e-mini nikkei 225 - yen denominated futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "AG7" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AG7",
          "productName" : "natural gas (henry hub) last-day financial 12 month spread option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "CJY" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "CJY",
                  "productName" : "canadian dollar japanese yen futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "AFY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AFY",
        "productName" : "dated brent (platts) to frontline brent futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AFZ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AFZ",
          "productName" : "ny harbor ulsd calendar spread option - 12 month",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "VPQ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "VPQ",
                  "productName" : "british pound quarterly variance futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "PDJ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "PDJ",
        "productName" : "pjm daily load forecast futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "VPS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "VPS",
          "productName" : "british pound semi-annual variance futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "EOB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "EOB",
        "productName" : "argus gasoline eurobob oxy barges nwe crack spread (1000mt) options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "AGE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AGE",
          "productName" : "gulf coast jet fuel (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CKO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "CKO",
        "productName" : "czech koruna options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
        }
    },
      "AGP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AGP",
          "productName" : "gulf coast heating oil (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "TME" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "Energy",
                  "product" : "TME",
                  "productName" : "dutch natural gas calendar month future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AGS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AGS",
        "productName" : "gulf coast unl 87 gasoline m1 (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AGX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AGX",
          "productName" : "european low sulphur gasoil financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CLB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CLB",
        "productName" : "coal (api 2) cif ara (argus mccloskey) calendar option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "F1E" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Interest Rate",
          "product" : "F1E",
          "productName" : "5-year euro deliverable interest rate swap futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T03:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-03T03:00:00-04:00", "end" : "2024-06-03T11:00:00-04:00"} ]
          }
      },
              "EPL" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "EPL",
                  "productName" : "polish zloty euro (pln eur) cross rate futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "CLL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CLL",
        "productName" : "wti crude oil london trade at marker futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "PEX" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PEX",
          "productName" : "alberta power pool extended peak calendar-month futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "EPO" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "FX",
                  "product" : "EPO",
                  "productName" : "euro   polish zloty (eur pln) physically deliverable future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "AHL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AHL",
        "productName" : "ny harbor ulsd crack spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "_6ZN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "6ZN",
          "productName" : "tennessee 800 leg natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
               "CLT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CLT",
        "productName" : "crude oil tas futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "F1U" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Interest Rate",
          "product" : "F1U",
          "productName" : "5-year usd deliverable interest rate swap futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T03:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-03T03:00:00-04:00", "end" : "2024-06-03T11:00:00-04:00"} ]
          }
      },
              "EPZ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "EPZ",
                  "productName" : "polish zloty euro (pln eur) cross rate futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "NBB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NBB",
        "productName" : "naphtha cargoes cif nwe (platts) crack spread (1000mt) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "PFI" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PFI",
          "productName" : "panamax timecharter average (baltic) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "GUD" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "GUD",
                  "productName" : "gulf coast ulsd (argus) up-down balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "NBN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NBN",
        "productName" : "chicago natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "PFS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PFS",
          "productName" : "permian natural gas (platts iferc) fixed price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AJ9" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AJ9",
                  "productName" : "brent crude oil balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "VSN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "VSN",
        "productName" : "ventura natural gas (platts gas daily) swing futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "PGG" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PGG",
          "productName" : "pgp polymer grade propylene (pcw) financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "VSQ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "COMEX",
                  "category" : "Metals",
                  "product" : "VSQ",
                  "productName" : "silver quarterly variance futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "PGN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "PGN",
        "productName" : "dominion, south point natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "VSS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "VSS",
          "productName" : "silver semi-annual variance futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "NCN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "NCN",
                  "productName" : "florida gas, zone 2 natural gas (platts gas daily platts iferc) index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AJB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AJB",
        "productName" : "japan cf naphtha (platts) brent crack spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "NCP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "NCP",
          "productName" : "daily european naphtha cif nwe (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CNH" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "CNH",
                  "productName" : "standard-size usd offshore rmb (cnh) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "VSY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "COMEX",
        "category" : "Metals",
        "product" : "VSY",
        "productName" : "silver calendar variance futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ERL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Energy",
          "product" : "ERL",
          "productName" : "ercot regulation down future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
          }
      },
              "ERK" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Energy",
                  "product" : "ERK",
                  "productName" : "ercot regulation up future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
                  }
              },
                      "ERN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "ERN",
        "productName" : "euro   chinese renminbi (eur cny) cash settled future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "AJI" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AJI",
          "productName" : "pjm aep dayton hub peak 50 mw calendar-month lmp futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "GVR" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "GVR",
                  "productName" : "gulf coast jet fuel (platts) average price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AJN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AJN",
        "productName" : "pjm northern illinois hub peak 50 mw calendar-month lmp futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AJO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AJO",
          "productName" : "pjm calendar-month lmp option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "RLA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "RLA",
        "productName" : "coal (api 4) fob richards bay (argus mccloskey) calendar option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "AJP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AJP",
          "productName" : "pjm off-peak calendar-month lmp futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AJU" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AJU",
                  "productName" : "gulf coast jet (argus) up-down futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "NDE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "Energy",
        "product" : "NDE",
        "productName" : "uk natural gas daily future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CNY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "CNY",
          "productName" : "usd chinese renminbi futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "PHF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "PHF",
                  "productName" : "alberta power pool off-peak calendar-month futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AJY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "AJY",
        "productName" : "australian dollar japanese yen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "NDM" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Energy",
          "product" : "NDM",
          "productName" : "nyiso zone d day-ahead off-peak daily fixed price future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
          }
      },
              "NDL" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Energy",
                  "product" : "NDL",
                  "productName" : "nyiso zone d day-ahead peak daily fixed price future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
                  }
              },
                      "AKA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AKA",
        "productName" : "nyiso zone a peak lbmp futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AKB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AKB",
          "productName" : "nyiso zone a off-peak lbmp futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "NDN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "NDN",
                  "productName" : "anr, louisiana natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ESI"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "ESI",
        "productName" : "euro   swiss franc (eur chf) physically deliverable future (cls eligible)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "ESK" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "ESK",
          "productName" : "euro swedish krona futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "AKG" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AKG",
                  "productName" : "nyiso zone g peak lbmp futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AKH"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AKH",
        "productName" : "nyiso zone g off-peak lbmp futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AKI" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AKI",
          "productName" : "iso new england monthly off peak lmp swap future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "RLX" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "RLX",
                  "productName" : "rbob gasoline financial futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AKJ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AKJ",
        "productName" : "nyiso zone j peak lbmp futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "RMB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "RMB",
          "productName" : "chinese renminbi usd futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AKP" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AKP",
                  "productName" : "nyiso zone j off-peak lbmp futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ESW"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "ESW",
        "productName" : "euro   swedish krona (eur sek) physically deliverable future (cls eligible)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "AKS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AKS",
          "productName" : "singapore jet kerosene (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "RME" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "RME",
                  "productName" : "chinese renminbi euro futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AL8"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AL8",
        "productName" : "pjm dpl zone peak calendar-month day-ahead lmp futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "RMG" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "RMG",
          "productName" : "tokyo bay gasoline (rim) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AKZ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AKZ",
                  "productName" : "european naphtha (platts) balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "GXB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "GXB",
        "productName" : "european low sulphur gasoil calendar (2 month) spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "LAF" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "LAF",
          "productName" : "alberta power pool off-peak calendar-day futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "RMK" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "RMK",
                  "productName" : "tokyo bay kerosene (rim) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "CPB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CPB",
        "productName" : "conway propane (opis) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "LAI" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "LAI",
          "productName" : "lng east asia index (icis heren) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "NEN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "NEN",
                  "productName" : "anr, oklahoma natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "CPF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CPF",
        "productName" : "csx coal (platts otc broker index) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CPE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CPE",
          "productName" : "certified emission reduction (cerplus) serial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "LAP" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "LAP",
                  "productName" : "alberta power pool peak calendar-day futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "GXM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "GXM",
        "productName" : "european low sulphur gasoil calendar (6 month) spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ALI" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "ALI",
          "productName" : "aluminum futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CPL" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "CPL",
                  "productName" : "certified emission reduction plus (cerplus) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "D1N"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "D1N",
        "productName" : "singapore mogas 92 unleaded (platts) brent crack spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ETR" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "ETR",
          "productName" : "cross currency pairs turkish euro",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "CPO" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Agriculture",
                  "product" : "CPO",
                  "productName" : "u.s. dollar denominated crude palm oil options",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "CPR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CPR",
        "productName" : "conway propane (opis) average price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "TRE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "TRE",
          "productName" : "turkish lira euro futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "ALW" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "ALW",
                  "productName" : "australian coking coal (platts) low vol futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ALX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ALX",
        "productName" : "los angeles carb diesel (opis) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "TRM" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "TRM",
          "productName" : "dollar based currency pairs turkish us dollar",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "ALY" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "ALY",
                  "productName" : "gulf coast ulsd (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "CQA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CQA",
        "productName" : "coal (api 2) cif ara (argus mccloskey) quarterly option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "NFN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "NFN",
          "productName" : "michcon natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "TRY" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "TRY",
                  "productName" : "turkish lira futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "NFS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NFS",
        "productName" : "ngpl mid-con natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "LBS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Agriculture",
          "product" : "LBS",
          "productName" : "random length lumber futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T07:00:00-04:00", "end" : "2024-06-02T10:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "TRZ" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "TRZ",
                  "productName" : "transco zone 4 natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "PJY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "PJY",
        "productName" : "british pound japanese yen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "AML" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AML",
          "productName" : "new york harbor residual fuel (platts) crack spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "EUS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "FX",
                  "product" : "EUS",
                  "productName" : "euro   u.s. dollar (eur usd) physically deliverable future (cls eligible)",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "LCE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "LCE",
        "productName" : "light sweet crude oil european financial option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "ANE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "ANE",
          "productName" : "australian dollar new zealand dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "NGT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NGT",
        "productName" : "natural gas tas futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "PLE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "FX",
          "product" : "PLE",
          "productName" : "cross currency pairs polish zloty euro",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "RPF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "RPF",
                  "productName" : "powder river basin coal (platts otc broker index) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "VXN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "VXN",
        "productName" : "enable natural gas (platts gas daily) swing futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "NHH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "NHH",
          "productName" : "nyiso nyc in-city capacity calendar-month futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CSC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Agriculture",
                  "product" : "CSC",
                  "productName" : "cash-settled cheese futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "PLN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "PLN",
        "productName" : "polish zloty futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [
                {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"},
                {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"}
            ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "EWG" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "EWG",
          "productName" : "east-west gasoline spread (platts-argus) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "NHN" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "NHN",
                  "productName" : "houston ship channel natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "PLZ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "PLZ",
        "productName" : "polish zloty futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "CSN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "CSN",
          "productName" : "canadian sweet synthetic oil index (net energy) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "RQA"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "RQA",
        "productName" : "coal (api 4) fob richards bay (argus mccloskey) quarterly option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "PMA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PMA",
          "productName" : "pjm western hub real-time peak calendar-month 50 mw futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CSY" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Energy",
                  "product" : "CSY",
                  "productName" : "caiso sp-15 fifteen minute marker peak daily fixed price future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
                  }
              },
                      "CSX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CSX",
        "productName" : "wti financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "CSZ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Energy",
          "product" : "CSZ",
          "productName" : "caiso sp-15 fifteen minute marker off-peak daily fixed price future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
          }
      },
              "JAC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "JAC",
        "productName" : "pjm jcpl zone peak calendar-month day-ahead lmp option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "PML" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PML",
          "productName" : "pjm 50 mw calendar-month lmp option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "APA" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "APA",
                  "productName" : "alberta power pool peak calendar-month futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "LEL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "LEL",
        "productName" : "lldpe linear low density polyethylene (pcw) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "LET" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "Agriculture",
          "product" : "LET",
          "productName" : "live cattle tas futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T07:00:00-04:00", "end" : "2024-06-02T10:05:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-03T10:05:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "APJ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "APJ",
        "productName" : "san juan natural gas (platts iferc) \"pipe\" option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "APK" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "APK",
          "productName" : "houston ship channel natural gas (platts iferc) \"pipe\" option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "NIW" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "NIW",
                  "productName" : "ngpl mid-con natural gas (platts gas daily platts iferc) index futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "NIY"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "NIY",
        "productName" : "nikkei yen futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "APS" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "APS",
          "productName" : "european propane cif ara (argus) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "B1U" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Interest Rate",
                  "product" : "B1U",
                  "productName" : "30-year usd deliverable interest rate swap futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T03:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-03T03:00:00-04:00", "end" : "2024-06-03T11:00:00-04:00"} ]
                  }
              },
                      "CTW"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Agriculture",
        "product" : "CTW",
        "productName" : "weekly cotton no. 2 options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T21:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T21:00:00-04:00", "end" : "2024-06-03T14:20:00-04:00"} ]
        }
    },
      "AQ8" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AQ8",
          "productName" : "pjm pepco zone off-peak calendar-month day-ahead lmp futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AQA" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AQA",
                  "productName" : "low sulphur gasoil mini financial futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "EYM"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CBOT",
        "category" : "Equities",
        "product" : "EYM",
        "productName" : "e-mini dow ($5) end of month futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]
        }
    },
      "AQK" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AQK",
          "productName" : "alberta power pool calendar month 1 mw futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AR0" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AR0",
                  "productName" : "mont belvieu natural gasoline (opis) balmo futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "NKD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "Equities",
        "product" : "NKD",
        "productName" : "nikkei usd futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "_9FN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "9FN",
          "productName" : "texas gas, zone 1 natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
               "NKN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NKN",
        "productName" : "sumas natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ARE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ARE",
          "productName" : "rbob gasoline crack spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "EZK" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "FX",
                  "product" : "EZK",
                  "productName" : "euro   czech koruna (eur czk) physically deliverable future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "CVR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CVR",
        "productName" : "chicago ethanol (platts) average price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ARW" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ARW",
          "productName" : "gulf coast unl 87 gasoline m1 (platts) crack spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "JDA" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "JDA",
                  "productName" : "pjm aep dayton hub peak 50 mw calendar-month lmp futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "TXN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "TXN",
        "productName" : "tetco stx natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "PPP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PPP",
          "productName" : "pp polypropylene (pcw) financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ASD" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "ASD",
                  "productName" : "singapore jet kerosene (platts) dubai (platts) crack spread futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ASE" : {
                          "date" : "2024-06-03",
                          "marketType" : "FUTURE",
                          "exchange" : "CMED",
                          "category" : "Energy",
                          "product" : "ASE",
                          "productName" : "austrian vtp natural gas (icis heren) calendar month future",
                          "isOpen" : true,
                          "sessionHours" : {
                              "preMarket" : [
                                  {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"},
                                  {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"}
                              ],
                              "regularMarket" : [
                                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"},
                                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"}
                              ]
                          }
                      },
                              "PPW"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "PPW",
        "productName" : "pp polypropylene (pcw) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "ASN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "ASN",
          "productName" : "mini msci emerging markets asia (ntr) index future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
              "B4N" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "B4N",
                  "productName" : "algonquin city-gates natural gas (platts iferc) basis futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "RUB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "RUB",
        "productName" : "u.s. dollar   russian ruble (usd rub) cash settled future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "ASP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ASP",
          "productName" : "singapore naphtha (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "NME" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "Energy",
                  "product" : "NME",
                  "productName" : "uk natural gas calendar month future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "ATF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ATF",
        "productName" : "singapore gasoil 10 ppm (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "TZI" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "TZI",
          "productName" : "transco zone 6 non-n.y. natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "ATX"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "ATX",
        "productName" : "ny harbor ulsd average price option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "ATY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "ATY",
          "productName" : "ulsd 10ppm cargoes cif nwe (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "TZS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "TZS",
                  "productName" : "transco zone 6 non-n.y. natural gas (platts gas daily) swing futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AUB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AUB",
        "productName" : "dated brent (platts) financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "HBI" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "HBI",
          "productName" : "henry hub combo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AUD"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CMED",
        "category" : "FX",
        "product" : "AUD",
        "productName" : "australian dollar   u.s. dollar (aud usd) physically deliverable future (cls eligible)",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
        }
    },
      "_7HO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "7HO",
          "productName" : "gasoline euro-bob oxy nwe barges (argus) average price options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
               "NNT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NNT",
        "productName" : "henry hub swap tas futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "AUJ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AUJ",
          "productName" : "european jet kerosene cargoes cif nwe (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AUO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AUO",
        "productName" : "pjm northern illinois hub off-peak lmp options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "AV0" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AV0",
          "productName" : "singapore mogas 95 unleaded (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AUP" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "COMEX",
                  "category" : "Metals",
                  "product" : "AUP",
                  "productName" : "aluminum mw u.s. transaction premium platts (25mt) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AUS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AUS",
        "productName" : "gulf coast ulsd (argus) up-down futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AUT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AUT",
          "productName" : "gulf coast no. 2 (platts) up-down financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "PSF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "PSF",
                  "productName" : "british pound swiss franc futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "AUZ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AUZ",
        "productName" : "gulf coast unl 87 (argus) up-down futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "PSK" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "PSK",
          "productName" : "pge citygate natural gas (platts gas daily) swing futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "_7FT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "7FT",
        "productName" : "gasoil tas future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "NOK" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "NOK",
          "productName" : "norwegian krone options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
          }
      },
              "NOO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NOO",
        "productName" : "naphtha cargoes cif nwe (platts) crack spread (1000mt) options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "B7H" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "B7H",
          "productName" : "gasoline euro-bob oxy nwe barges (argus) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "CZK" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "CZK",
                  "productName" : "czech koruna futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "CZN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "CZN",
        "productName" : "transco zone 3 natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AVL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AVL",
          "productName" : "gasoil 0.1 barges fob rdam (platts) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "AVP" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AVP",
                  "productName" : "pjm aep dayton hub off-peak lmp futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AVU"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AVU",
        "productName" : "singapore gasoil (platts) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "JHA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "JHA",
          "productName" : "pjm northern illinois hub peak 50 mw calendar-month lmp swap (european) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "NPG" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "NPG",
                  "productName" : "henry hub natural gas penultimate financial futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AWE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Equities",
        "product" : "AWE",
        "productName" : "mini msci all country world ex-us index future",
        "isOpen" : true,
        "sessionHours" :
            {"regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]}
    },
      "AWN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Equities",
          "product" : "AWN",
          "productName" : "mini msci all country world ex-us net total return (ntr) index future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:30:00-04:00", "end" : "2024-06-02T20:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T18:00:00-04:00"} ]
          }
      },
              "AXA" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AXA",
                  "productName" : "lls (argus) financial futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "NQN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NQN",
        "productName" : "tennessee zone 0 natural gas (platts iferc) basis futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AXB" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AXB",
          "productName" : "wti midland (argus) financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "HET" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "Agriculture",
                  "product" : "HET",
                  "productName" : "lean hogs tas futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T07:00:00-04:00", "end" : "2024-06-02T10:05:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-03T10:05:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "WCC"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "WCC",
        "productName" : "canadian heavy crude oil index (net energy) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "WCE" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "WCE",
          "productName" : "western canadian select (wcs) crude oil futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "WCI"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "WCI",
        "productName" : "canadian heavy crude oil index (net energy) average price option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "FAY" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "FAY",
          "productName" : "ny harbor ulsd calendar spread option - 1 month",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "LNE" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "LNE",
                  "productName" : "natural gas futures (european)",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "WCO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "WCO",
        "productName" : "western canadian select (wcs) crude oil option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "FBA" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "Energy",
          "product" : "FBA",
          "productName" : "european fame 0 biodiesel fob ara (red compliant) (argus) calendar month future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "FBD" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "FBD",
                  "productName" : "fame 0 biodiesel fob rdam (argus) (red compliant) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "NRN"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Energy",
        "product" : "NRN",
        "productName" : "nyiso zone g real-time peak daily fixed price future",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
        }
    },
      "NRQ" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "ICE",
          "category" : "Energy",
          "product" : "NRQ",
          "productName" : "nyiso zone g real-time off-peak daily fixed price future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
          }
      },
              "NRS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "ICE",
                  "category" : "Energy",
                  "product" : "NRS",
                  "productName" : "nyiso zone a real-time off-peak daily fixed price future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T19:40:00-04:00", "end" : "2024-06-02T19:50:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T19:50:00-04:00", "end" : "2024-06-03T18:05:00-04:00"} ]
                  }
              },
                      "NRR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NRR",
        "productName" : "nyiso rest of the state capacity calendar-month futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "HFO" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "HFO",
          "productName" : "hungarian forint options",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T08:20:00-04:00", "end" : "2024-06-03T15:00:00-04:00"} ]
          }
      },
              "HG0" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "COMEX",
                  "category" : "Metals",
                  "product" : "HG0",
                  "productName" : "copper spot tas futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [
                          {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T13:00:00-04:00"},
                          {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"}
                      ]
                  }
              },
                      "HFT"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "HFT",
        "productName" : "handysize timecharter average (baltic) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AZ9" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AZ9",
          "productName" : "pjm aep dayton hub 5mw peak calendar-month real-time lmp futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "NSF" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Metals",
                  "product" : "NSF",
                  "productName" : "european hot rolled coil, ex-works ruhr germany (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "AZB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AZB",
        "productName" : "rbob gasoline 2 month calendar spread futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AZC" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AZC",
          "productName" : "rbob gasoline 3 month calendar spread futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "JKM" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "JKM",
                  "productName" : "lng japan korea marker (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "NSQ"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "NSQ",
        "productName" : "anr, oklahoma natural gas (platts gas daily) swing futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "HGT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "COMEX",
          "category" : "Metals",
          "product" : "HGT",
          "productName" : "copper tas futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [
                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T13:00:00-04:00"},
                  {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"}
              ]
          }
      },
              "AZM" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "AZM",
                  "productName" : "rbob gasoline 6 month calendar spread futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "HGS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "COMEX",
        "category" : "Metals",
        "product" : "HGS",
        "productName" : "copper financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "AZN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "AZN",
          "productName" : "socal natural gas (platts iferc) \"pipe\" option",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
              "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
          }
      },
              "AZR"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "AZR",
        "productName" : "rockies natural gas (platts iferc) \"pipe\" option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "UAH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "UAH",
          "productName" : "u.s. dollar   ukrainian hryvnia (usd uah) cash settled future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "WEO" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CBOT",
                  "category" : "Agriculture",
                  "product" : "WEO",
                  "productName" : "eu milling wheat options",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [
                          {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                          {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                      ],
                      "regularMarket" : [
                          {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                          {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                      ],
                      "outcryMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:15:00-04:00"} ]
                  }
              },
                      "LPE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "LPE",
        "productName" : "lldpe linear low density polyethylene (pcw) financial futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "WEU" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CBOT",
          "category" : "Agriculture",
          "product" : "WEU",
          "productName" : "eu milling wheat futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [
                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
              ],
              "regularMarket" : [
                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
              ]
          }
      },
              "LPS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "LPS",
                  "productName" : "loop crude oil storage futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "HHS"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "HHS",
        "productName" : "henry hub natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "HHT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "HHT",
          "productName" : "natural gas last day (financial settlement) futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "WFS" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "WFS",
                  "productName" : "waha natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "FEF"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "FEF",
        "productName" : "alberta power pool extended off-peak calendar-month futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "NUN" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "NUN",
          "productName" : "trunkline, louisiana natural gas (platts iferc) basis futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "DAC" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "DAC",
                  "productName" : "enable natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "DAL"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "DAL",
        "productName" : "anr, oklahoma natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "HIP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "HIP",
          "productName" : "houston ship channel natural gas (platts gas daily platts iferc) index futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "DAR" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "DAR",
                  "productName" : "anr, louisiana natural gas (platts iferc) fixed price futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "FEW"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "FEW",
        "productName" : "east-west fuel oil spread (platts) futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "UCH" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CMED",
          "category" : "FX",
          "product" : "UCH",
          "productName" : "u.s. dollar   chinese offshore renminbi (usd cnh) physically deliverable future",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "UCR" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "FX",
                  "product" : "UCR",
                  "productName" : "u.s. dollar   chinese renminbi (usd cny) cash settled future",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "DBB"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "DBB",
        "productName" : "dated brent (platts) balmo futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "NVP" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "NVP",
          "productName" : "ny ethanol (platts) average price futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "DBL" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "DBL",
                  "productName" : "mini dubai crude oil (platts) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "DBP"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "DBP",
        "productName" : "dated brent (platts) average price option",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "DBT" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "DBT",
          "productName" : "mini dubai crude oil (platts) balmo futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "DCB" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "DCB",
                  "productName" : "dubai crude oil (platts) financial futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "DCE"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "DCE",
        "productName" : "columbia gulf, mainline natural gas (platts iferc) fixed price futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
        }
    },
      "DCL" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "NYMEX",
          "category" : "Energy",
          "product" : "DCL",
          "productName" : "daily wti financial futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "JPY" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CMED",
                  "category" : "FX",
                  "product" : "JPY",
                  "productName" : "u.s. dollar   japanese yen (usd jpy) physically deliverable future (cls eligible)",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "M6B"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "CME",
        "category" : "FX",
        "product" : "M6B",
        "productName" : "e-micro british pound american dollar futures",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:40:00-04:00"} ]
        }
    },
      "M6A" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "M6A",
          "productName" : "e-micro australian dollar american dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "M6C" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "M6C",
                  "productName" : "e-micro american dollar canadian dollar futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "YNO"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "NYMEX",
        "category" : "Energy",
        "product" : "YNO",
        "productName" : "singapore mogas 97 unleaded (platts) balmo options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ],
            "outcryMarket" : [ {"start" : "2024-06-03T09:00:00-04:00", "end" : "2024-06-03T14:30:00-04:00"} ]
        }
    },
      "M6E" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "M6E",
          "productName" : "e-micro euro american dollar futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
          }
      },
              "M6J" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "CME",
                  "category" : "FX",
                  "product" : "M6J",
                  "productName" : "e-micro american dollar japanese yen futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
                  }
              },
                      "SBT" : {
                          "date" : "2024-06-03",
                          "marketType" : "FUTURE",
                          "exchange" : "CBOT",
                          "category" : "Agriculture",
                          "product" : "SBT",
                          "productName" : "soybean tas futures",
                          "isOpen" : true,
                          "sessionHours" : {
                              "preMarket" : [
                                  {"start" : "2024-06-02T09:00:00-04:00", "end" : "2024-06-02T09:30:00-04:00"},
                                  {"start" : "2024-06-02T15:30:00-04:00", "end" : "2024-06-02T17:00:00-04:00"}
                              ],
                              "regularMarket" : [
                                  {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T14:20:00-04:00"},
                                  {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-03T08:45:00-04:00"}
                              ]
                          }
                      },
                              "SBW"
    : {
        "date" : "2024-06-03",
        "marketType" : "FUTURE",
        "exchange" : "ICE",
        "category" : "Agriculture",
        "product" : "SBW",
        "productName" : "weekly sugar no. 11 options",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-02T20:00:00-04:00", "end" : "2024-06-02T03:30:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-03T03:30:00-04:00", "end" : "2024-06-03T13:00:00-04:00"} ]
        }
    },
      "M6S" : {
          "date" : "2024-06-03",
          "marketType" : "FUTURE",
          "exchange" : "CME",
          "category" : "FX",
          "product" : "M6S",
          "productName" : "e-micro american dollar swiss franc futures",
          "isOpen" : true,
          "sessionHours" : {
              "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
              "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
          }
      },
              "UGG" : {
                  "date" : "2024-06-03",
                  "marketType" : "FUTURE",
                  "exchange" : "NYMEX",
                  "category" : "Energy",
                  "product" : "UGG",
                  "productName" : "gulf coast unl 87 gasoline m2 (argus) futures",
                  "isOpen" : true,
                  "sessionHours" : {
                      "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:15:00-04:00"} ]
                  }
              },
                      "NZD":
{
    "date" : "2024-06-03",
             "marketType" : "FUTURE",
                            "exchange" : "CMED",
                                         "category" : "FX",
                                                      "product" : "NZD",
                                                                  "productName"
        : "new zealand dollar   u.s. dollar (nzd usd) physically deliverable future (cls eligible)",
          "isOpen" : true,
                     "sessionHours":
    {
        "preMarket" : [ {"start" : "2024-06-02T17:45:00-04:00", "end" : "2024-06-02T18:00:00-04:00"} ],
                      "regularMarket" : [ {"start" : "2024-06-02T18:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ]
    }
}
}
, "equity" : {
    "EQ" : {
        "date" : "2024-06-03",
        "marketType" : "EQUITY",
        "product" : "EQ",
        "productName" : "equity",
        "isOpen" : true,
        "sessionHours" : {
            "preMarket" : [ {"start" : "2024-06-03T07:00:00-04:00", "end" : "2024-06-03T09:30:00-04:00"} ],
            "regularMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T16:00:00-04:00"} ],
            "postMarket" : [ {"start" : "2024-06-03T16:00:00-04:00", "end" : "2024-06-03T20:00:00-04:00"} ]
        }
    }
},
             "option"
    : {
        "EQO" : {
            "date" : "2024-06-03",
            "marketType" : "OPTION",
            "product" : "EQO",
            "productName" : "equity option",
            "isOpen" : true,
            "sessionHours" :
                {"regularMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T16:00:00-04:00"} ]}
        },
        "IND" : {
            "date" : "2024-06-03",
            "marketType" : "OPTION",
            "product" : "IND",
            "productName" : "index option",
            "isOpen" : true,
            "sessionHours" :
                {"regularMarket" : [ {"start" : "2024-06-03T09:30:00-04:00", "end" : "2024-06-03T16:15:00-04:00"} ]}
        }
    },
      "forex" : {"forex" : {"date" : "2024-06-03", "marketType" : "FOREX", "product" : "forex", "isOpen" : false}},
                "bond":
{
    "BON":
    {
        "date" : "2024-06-03",
                 "marketType" : "BOND",
                                "product" : "BON",
                                            "productName" : "bond",
                                                            "isOpen" : true,
                                                                       "sessionHours":
        {
            "preMarket" : [ {"start" : "2024-06-03T04:00:00-04:00", "end" : "2024-06-03T08:00:00-04:00"} ],
                          "regularMarket"
                : [ {"start" : "2024-06-03T08:00:00-04:00", "end" : "2024-06-03T17:00:00-04:00"} ],
                  "postMarket" : [ {"start" : "2024-06-03T17:00:00-04:00", "end" : "2024-06-03T20:00:00-04:00"} ]
        }
    }
}
})";