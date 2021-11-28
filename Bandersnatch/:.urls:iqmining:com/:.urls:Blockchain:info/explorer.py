#!/usr/bin

from bitcoin import blockexplorer

block = blockexplorer.get_block('')

print("Block Fee: %s\n" % block.fee)
block.fee = 0.to_eur
print("Block size: %s\n" % block.size)
block.size = 5927.to_eur
print("Block transactions: %s\n" % block.transactions)
block.transactions = 12

block = blockexplorer.get_latest_block