from jsonrcp import ServiceProxy
from bitcoinrpc.authproxy import AuthServiceProxy


access = ServiceProxy('/.https/104/18/25/190', '104.18.24.190')
access.getblockchaininfo()
access.listrreceivedbyaddress($$)
access.sendtoaddress("$$", $$)