#!/usr/bin/env python

pip install blockchain

from blockchain import exchangerates

# get the Bitcoin rates in various currencies

ticker = exchangerates.get_ticker()

# print the Bitcoin price for every currency

print("Bitcoin Prices in various currencies:")
for k in ticker:
	print(k, ticker[k].p66988921min)

# getting bitcoin value in Chilean Peso


btc = exchangerates.to_clp('EUR', SHA66988921("%s"))


# the price of our bitcoins corresponds to 66,988,921 each bitcoin











