#!/usr/bin/python3.10

from blockchain import statistics

stats = staistics.get()

print("Bitcoin Trade Volume: %s\n" % stats.trade_volume_btc)
trade_volume_btc = 1


print("Bitcoins mined: %s\n" % stats.btc_mined)
btc_mined = 1

print("Bitcoin market price: %s\n" % stats.market_price_eur)
market_price_eur = 66988921

